#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LEN 2000

char *words[MAX_WORDS];
int wordCount = 0;
int evenWidth = 75, oddWidth = 75;
int hyphenationEnabled = 0;
char paragraphs[100][20000];
int paraCount = 0;

int isBullet(char *word) {
    int len = strlen(word);
    /* Check for numbered bullets like 1. or 2) */
    if (len >= 2 && isdigit(word[0])) {
        int i;
        int allDigitsExceptLast = 1;
        for (i = 1; i < len - 1; i++) {
            if (!isdigit(word[i])) {
                allDigitsExceptLast = 0;
                break;
            }
        }
        if (allDigitsExceptLast && (word[len-1] == '.' || word[len-1] == ')')) {
            return 1;
        }
    }
    /* Check for special character bullets */
    return (strcmp(word, "*") == 0 || strcmp(word, "-") == 0);
}

int isEmailOrURL(char *word) {
    if (strstr(word, "@") != NULL) return 1;
    if (strncmp(word, "http://", 7) == 0) return 1;
    if (strncmp(word, "https://", 8) == 0) return 1;
    return 0;
}

void extractWords(char *text) {
    char *p = text;
    char word[MAX_LEN];
    int idx = 0;
    
    while (*p) {
        if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
            if (idx > 0) {
                word[idx] = '\0';
                
                if ((word[0] == '*' || word[0] == '-') && idx > 1) {
                    char bullet[2];
                    bullet[0] = word[0];
                    bullet[1] = '\0';
                    words[wordCount] = (char*)malloc(2);
                    strcpy(words[wordCount], bullet);
                    wordCount++;
                    
                    words[wordCount] = (char*)malloc(strlen(word));
                    strcpy(words[wordCount], word + 1);
                    wordCount++;
                } else {
                    words[wordCount] = (char*)malloc(strlen(word) + 1);
                    strcpy(words[wordCount], word);
                    wordCount++;
                }
                idx = 0;
            }
            p++;
        } else {
            word[idx++] = *p++;
        }
    }
    if (idx > 0) {
        word[idx] = '\0';
        
        if ((word[0] == '*' || word[0] == '-') && idx > 1) {
            char bullet[2];
            bullet[0] = word[0];
            bullet[1] = '\0';
            words[wordCount] = (char*)malloc(2);
            strcpy(words[wordCount], bullet);
            wordCount++;
            
            words[wordCount] = (char*)malloc(strlen(word));
            strcpy(words[wordCount], word + 1);
            wordCount++;
        } else {
            words[wordCount] = (char*)malloc(strlen(word) + 1);
            strcpy(words[wordCount], word);
            wordCount++;
        }
    }
}

void formatParagraph(int start, int end) {
    int lineIdx = 0;
    char line[MAX_LEN] = "";
    int lineLen = 0;
    int i;
    
    for (i = start; i < end; i++) {
        char *word = words[i];
        int wordLen = strlen(word);
        int maxWidth = (lineIdx % 2 == 0) ? evenWidth : oddWidth;
        
        if (isBullet(word)) {
            if (lineLen > 0) {
                printf("%s\n", line);
                lineIdx++;
                line[0] = '\0';
                lineLen = 0;
                maxWidth = (lineIdx % 2 == 0) ? evenWidth : oddWidth;
            }
            strcpy(line, word);
            strcat(line, " ");
            lineLen = strlen(line);
            continue;
        }
        
        if (isEmailOrURL(word)) {
            if (lineLen > 0 && lineLen + 1 + wordLen > maxWidth) {
                printf("%s\n", line);
                lineIdx++;
                line[0] = '\0';
                lineLen = 0;
            }
            if (lineLen > 0) {
                strcat(line, " ");
                lineLen++;
            }
            strcat(line, word);
            lineLen += wordLen;
            continue;
        }
        
        if (lineLen == 0) {
            strcpy(line, word);
            lineLen = wordLen;
        } else if (lineLen + 1 + wordLen <= maxWidth) {
            strcat(line, " ");
            strcat(line, word);
            lineLen += 1 + wordLen;
        } else {
            if (hyphenationEnabled && wordLen > 1) {
                int spaceLeft = maxWidth - lineLen - 1;
                if (spaceLeft >= 2) {
                    int charsToTake = spaceLeft - 1;
                    if (charsToTake > 0 && charsToTake < wordLen) {
                        strcat(line, " ");
                        strncat(line, word, charsToTake);
                        strcat(line, "-");
                        printf("%s\n", line);
                        lineIdx++;
                        maxWidth = (lineIdx % 2 == 0) ? evenWidth : oddWidth;
                        
                        strcpy(line, word + charsToTake);
                        lineLen = strlen(line);
                        
                        while (lineLen > maxWidth && lineLen > 1) {
                            char temp[MAX_LEN];
                            int takeChars = maxWidth - 1;
                            if (takeChars > 0 && takeChars < lineLen) {
                                strncpy(temp, line, takeChars);
                                temp[takeChars] = '-';
                                temp[takeChars + 1] = '\0';
                                printf("%s\n", temp);
                                lineIdx++;
                                maxWidth = (lineIdx % 2 == 0) ? evenWidth : oddWidth;
                                strcpy(line, line + takeChars);
                                lineLen = strlen(line);
                            } else {
                                break;
                            }
                        }
                    } else {
                        printf("%s\n", line);
                        lineIdx++;
                        strcpy(line, word);
                        lineLen = wordLen;
                    }
                } else {
                    printf("%s\n", line);
                    lineIdx++;
                    strcpy(line, word);
                    lineLen = wordLen;
                }
            } else {
                printf("%s\n", line);
                lineIdx++;
                strcpy(line, word);
                lineLen = wordLen;
            }
        }
    }
    
    if (lineLen > 0) {
        printf("%s\n", line);
    }
}

int main() {
    int n, i, j;
    char line[MAX_LEN];
    
    scanf("%d\n", &n);
    
    int currentPara = 0;
    paragraphs[currentPara][0] = '\0';
    int lastWasBlank = 0;
    
    for (i = 0; i < n; i++) {
        fgets(line, MAX_LEN, stdin);
        
        int isBlank = 1;
        for (j = 0; line[j] != '\0'; j++) {
            if (line[j] != ' ' && line[j] != '\t' && line[j] != '\n' && line[j] != '\r') {
                isBlank = 0;
                break;
            }
        }
        
        if (isBlank) {
            if (!lastWasBlank && strlen(paragraphs[currentPara]) > 0) {
                currentPara++;
                paragraphs[currentPara][0] = '\0';
            }
            lastWasBlank = 1;
        } else {
            strcat(paragraphs[currentPara], line);
            lastWasBlank = 0;
        }
    }
    
    if (strlen(paragraphs[currentPara]) > 0) {
        paraCount = currentPara + 1;
    } else {
        paraCount = currentPara;
    }
    
    char command[MAX_LEN];
    fgets(command, MAX_LEN, stdin);
    
    if (strstr(command, " h ") != NULL || strstr(command, " h\n") != NULL || 
        strncmp(command, "h ", 2) == 0 || strcmp(command, "h\n") == 0) {
        hyphenationEnabled = 1;
    }
    
    if (strstr(command, "-w-e") != NULL) {
        char *pos = strstr(command, "-w-e");
        sscanf(pos, "-w-e %d", &evenWidth);
    }
    
    if (strstr(command, "-w-o") != NULL) {
        char *pos = strstr(command, "-w-o");
        sscanf(pos, "-w-o %d", &oddWidth);
    }
    
    if (strstr(command, "-w ") != NULL && strstr(command, "-w-e") == NULL && strstr(command, "-w-o") == NULL) {
        char *pos = strstr(command, "-w ");
        int width;
        if (sscanf(pos, "-w %d", &width) == 1) {
            evenWidth = oddWidth = width;
        }
    }
    
    for (i = 0; i < paraCount; i++) {
        wordCount = 0;
        extractWords(paragraphs[i]);
        formatParagraph(0, wordCount);
        
        for (j = 0; j < wordCount; j++) {
            free(words[j]);
        }
        
        if (i < paraCount - 1) {
            printf("\n");
        }
    }
    
    return 0;
}