#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define STRING_MAX 200

char codeBuffer[BUFFER_SIZE][STRING_MAX];
int totalLines = 0;
int memory[26];

int checkDigit(char *str) {
    int pos = 0;
    if (str[pos] == '-' || str[pos] == '+') pos++;
    if (!str[pos]) return 0;
    while (str[pos]) {
        if (!isdigit(str[pos])) return 0;
        pos++;
    }
    return 1;
}

int fetchValue(char *str) {
    while (*str == ' ') str++;
    char buffer[50];
    int idx = 0;
    while (str[idx] && str[idx] != ' ' && str[idx] != '\n' && str[idx] != '\r') {
        buffer[idx] = str[idx];
        idx++;
    }
    buffer[idx] = 0;
    if (checkDigit(buffer)) return atoi(buffer);
    return memory[buffer[0] - 'A'];
}

int checkCondition(char *expression) {
    char leftSide[50], operator[5], rightSide[50];
    int pos = 0, idx = 0;
    while (expression[pos] && expression[pos] != '=' && expression[pos] != '!' && expression[pos] != '<' && expression[pos] != '>') {
        leftSide[idx++] = expression[pos++];
    }
    leftSide[idx] = 0;
    idx = 0;
    while (expression[pos] && (expression[pos] == '=' || expression[pos] == '!' || expression[pos] == '<' || expression[pos] == '>')) {
        operator[idx++] = expression[pos++];
    }
    operator[idx] = 0;
    idx = 0;
    while (expression[pos]) {
        rightSide[idx++] = expression[pos++];
    }
    rightSide[idx] = 0;
    int leftVal = fetchValue(leftSide);
    int rightVal = fetchValue(rightSide);
    if (strcmp(operator, "==") == 0) return leftVal == rightVal;
    if (strcmp(operator, "!=") == 0) return leftVal != rightVal;
    if (strcmp(operator, "<=") == 0) return leftVal <= rightVal;
    if (strcmp(operator, ">=") == 0) return leftVal >= rightVal;
    if (strcmp(operator, "<") == 0) return leftVal < rightVal;
    if (strcmp(operator, ">") == 0) return leftVal > rightVal;
    return 0;
}

void runBlock(int begin, int finish);

void processConditional(int position, int endBoundary) {
    char *currentLine = codeBuffer[position];
    char condition[100];
    int pos = 3;
    while (currentLine[pos] == ' ') pos++;
    int idx = 0;
    while (currentLine[pos]) {
        condition[idx++] = currentLine[pos++];
    }
    condition[idx] = 0;
    int trueBlock = -1, falseBlock = -1, closeBlock = -1;
    int nestLevel = 0;
    int scan;
    for (scan = position + 1; scan <= endBoundary; scan++) {
        if (strncmp(codeBuffer[scan], "if ", 3) == 0 || strncmp(codeBuffer[scan], "for ", 4) == 0) {
            nestLevel++;
        }
        if (strcmp(codeBuffer[scan], "end") == 0) {
            if (nestLevel == 0) {
                closeBlock = scan;
                break;
            }
            nestLevel--;
        }
        if (strcmp(codeBuffer[scan], "Yes") == 0 && nestLevel == 0) trueBlock = scan;
        if (strcmp(codeBuffer[scan], "No") == 0 && nestLevel == 0) falseBlock = scan;
    }
    if (checkCondition(condition)) {
        if (trueBlock != -1) {
            int endTrue = (falseBlock != -1) ? falseBlock - 1 : closeBlock - 1;
            runBlock(trueBlock + 1, endTrue);
        }
    } else {
        if (falseBlock != -1) {
            runBlock(falseBlock + 1, closeBlock - 1);
        }
    }
}

void processLoop(int position, int endBoundary) {
    char *currentLine = codeBuffer[position];
    char iterator[10], beginStr[50], endStr[50];
    int pos = 4;
    while (currentLine[pos] == ' ') pos++;
    int idx = 0;
    while (currentLine[pos] && currentLine[pos] != ' ') {
        iterator[idx++] = currentLine[pos++];
    }
    iterator[idx] = 0;
    while (currentLine[pos] == ' ') pos++;
    idx = 0;
    while (currentLine[pos] && currentLine[pos] != ' ') {
        beginStr[idx++] = currentLine[pos++];
    }
    beginStr[idx] = 0;
    while (currentLine[pos] == ' ') pos++;
    idx = 0;
    while (currentLine[pos]) {
        endStr[idx++] = currentLine[pos++];
    }
    endStr[idx] = 0;
    int nestLevel = 0;
    int closeBlock = -1;
    int scan;
    for (scan = position + 1; scan <= endBoundary; scan++) {
        if (strncmp(codeBuffer[scan], "if ", 3) == 0 || strncmp(codeBuffer[scan], "for ", 4) == 0) {
            nestLevel++;
        }
        if (strcmp(codeBuffer[scan], "end") == 0) {
            if (nestLevel == 0) {
                closeBlock = scan;
                break;
            }
            nestLevel--;
        }
    }
    int startNum = fetchValue(beginStr);
    int endNum = fetchValue(endStr);
    int iterIndex = iterator[0] - 'A';
    int counter;
    for (counter = startNum; counter <= endNum; counter++) {
        memory[iterIndex] = counter;
        runBlock(position + 1, closeBlock - 1);
    }
}

void runBlock(int begin, int finish) {
    int current;
    for (current = begin; current <= finish; current++) {
        if (strncmp(codeBuffer[current], "if ", 3) == 0) {
            int nestLevel = 0;
            int closeBlock = -1;
            int scan;
            for (scan = current + 1; scan <= finish; scan++) {
                if (strncmp(codeBuffer[scan], "if ", 3) == 0 || strncmp(codeBuffer[scan], "for ", 4) == 0) {
                    nestLevel++;
                }
                if (strcmp(codeBuffer[scan], "end") == 0) {
                    if (nestLevel == 0) {
                        closeBlock = scan;
                        break;
                    }
                    nestLevel--;
                }
            }
            processConditional(current, closeBlock);
            current = closeBlock;
        } else if (strncmp(codeBuffer[current], "for ", 4) == 0) {
            int nestLevel = 0;
            int closeBlock = -1;
            int scan;
            for (scan = current + 1; scan <= finish; scan++) {
                if (strncmp(codeBuffer[scan], "if ", 3) == 0 || strncmp(codeBuffer[scan], "for ", 4) == 0) {
                    nestLevel++;
                }
                if (strcmp(codeBuffer[scan], "end") == 0) {
                    if (nestLevel == 0) {
                        closeBlock = scan;
                        break;
                    }
                    nestLevel--;
                }
            }
            processLoop(current, closeBlock);
            current = closeBlock;
        } else if (strncmp(codeBuffer[current], "print ", 6) == 0) {
            char *valuePtr = codeBuffer[current] + 6;
            while (*valuePtr == ' ') valuePtr++;
            printf("%d\n", fetchValue(valuePtr));
        }
    }
}

int main() {
    while (fgets(codeBuffer[totalLines], STRING_MAX, stdin)) {
        int length = strlen(codeBuffer[totalLines]);
        if (length > 0 && codeBuffer[totalLines][length - 1] == '\n') {
            codeBuffer[totalLines][length - 1] = 0;
        }
        totalLines++;
    }
    char variableLine[STRING_MAX], valueLine[STRING_MAX];
    strcpy(variableLine, codeBuffer[totalLines - 2]);
    strcpy(valueLine, codeBuffer[totalLines - 1]);
    totalLines -= 2;
    char *token = strtok(variableLine, " ");
    int position = 0;
    char varNames[26][5];
    int varCount = 0;
    while (token) {
        strcpy(varNames[varCount++], token);
        token = strtok(NULL, " ");
    }
    token = strtok(valueLine, " ");
    position = 0;
    while (token) {
        int value = atoi(token);
        int varPosition = varNames[position][0] - 'A';
        memory[varPosition] = value;
        position++;
        token = strtok(NULL, " ");
    }
    runBlock(0, totalLines - 1);
    return 0;
}