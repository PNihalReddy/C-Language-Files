#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 200
#define MAX_VARS 26

char lines[MAX_LINES][MAX_LINE_LEN];
int variables[MAX_VARS];
int lineCount = 0;
int currentLine = 0;

int getVarValue(char *token) {
    if (isalpha(token[0]) && strlen(token) == 1) {
        return variables[token[0] - 'A'];
    }
    return atoi(token);
}

void trim(char *str) {
    int i = 0, j = 0;
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')) {
        i++;
    }
    while (str[i] != '\0') {
        str[j++] = str[i++];
    }
    str[j] = '\0';
    j--;
    while (j >= 0 && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n' || str[j] == '\r')) {
        str[j--] = '\0';
    }
}

int evaluateCondition(char *condition) {
    char cond[MAX_LINE_LEN];
    strcpy(cond, condition);
    
    char *op = NULL;
    int val1, val2;
    
    if (strstr(cond, "==")) {
        op = "==";
    } else if (strstr(cond, "!=")) {
        op = "!=";
    } else if (strstr(cond, "<=")) {
        op = "<=";
    } else if (strstr(cond, ">=")) {
        op = ">=";
    } else if (strstr(cond, "<")) {
        op = "<";
    } else if (strstr(cond, ">")) {
        op = ">";
    }
    
    if (op) {
        char *token1 = strtok(cond, op);
        char *token2 = strtok(NULL, op);
        
        if (strcmp(op, "==") == 0) {
            token1 = strtok(cond, "=");
            strtok(NULL, "=");
            token2 = strtok(NULL, "=");
        } else if (strcmp(op, "!=") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0) {
            char *pos = strstr(condition, op);
            if (pos) {
                int idx = pos - condition;
                strncpy(cond, condition, idx);
                cond[idx] = '\0';
                token1 = cond;
                token2 = condition + idx + 2;
            }
        }
        
        trim(token1);
        trim(token2);
        
        val1 = getVarValue(token1);
        val2 = getVarValue(token2);
        
        if (strcmp(op, "==") == 0) return val1 == val2;
        if (strcmp(op, "!=") == 0) return val1 != val2;
        if (strcmp(op, "<") == 0) return val1 < val2;
        if (strcmp(op, ">") == 0) return val1 > val2;
        if (strcmp(op, "<=") == 0) return val1 <= val2;
        if (strcmp(op, ">=") == 0) return val1 >= val2;
    }
    
    return 0;
}

int findMatchingEnd(int startLine) {
    int depth = 1;
    int i = startLine + 1;
    
    while (i < lineCount && depth > 0) {
        char line[MAX_LINE_LEN];
        strcpy(line, lines[i]);
        trim(line);
        
        if (strncmp(line, "if ", 3) == 0 || strncmp(line, "for ", 4) == 0) {
            depth++;
        } else if (strcmp(line, "end") == 0) {
            depth--;
            if (depth == 0) {
                return i;
            }
        }
        i++;
    }
    return i;
}

int findNoBlock(int startLine, int endLine) {
    int depth = 0;
    int i = startLine + 1;
    
    while (i < endLine) {
        char line[MAX_LINE_LEN];
        strcpy(line, lines[i]);
        trim(line);
        
        if (strncmp(line, "if ", 3) == 0 || strncmp(line, "for ", 4) == 0) {
            depth++;
        } else if (strcmp(line, "end") == 0) {
            depth--;
        } else if (strcmp(line, "No") == 0 && depth == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void executeLine(int *linePtr);

void executeBlock(int startLine, int endLine) {
    int i = startLine;
    while (i < endLine) {
        executeLine(&i);
        i++;
    }
}

void executeLine(int *linePtr) {
    int i = *linePtr;
    if (i >= lineCount) return;
    
    char line[MAX_LINE_LEN];
    strcpy(line, lines[i]);
    trim(line);
    
    if (strlen(line) == 0 || strcmp(line, "Yes") == 0 || strcmp(line, "No") == 0 || strcmp(line, "end") == 0) {
        return;
    }
    
    if (strncmp(line, "print ", 6) == 0) {
        char *token = line + 6;
        trim(token);
        printf("%d\n", getVarValue(token));
        return;
    }
    
    if (strncmp(line, "if ", 3) == 0) {
        char *condition = line + 3;
        trim(condition);
        
        int endLine = findMatchingEnd(i);
        int noLine = findNoBlock(i, endLine);
        
        if (evaluateCondition(condition)) {
            int yesStart = i + 2;
            int yesEnd = (noLine != -1) ? noLine : endLine;
            executeBlock(yesStart, yesEnd);
        } else {
            if (noLine != -1) {
                executeBlock(noLine + 1, endLine);
            }
        }
        
        *linePtr = endLine;
        return;
    }
    
    if (strncmp(line, "for ", 4) == 0) {
        char forLine[MAX_LINE_LEN];
        strcpy(forLine, line + 4);
        trim(forLine);
        
        char *iterVar = strtok(forLine, " ");
        char *startVal = strtok(NULL, " ");
        char *endVal = strtok(NULL, " ");
        
        int start = getVarValue(startVal);
        int end = getVarValue(endVal);
        
        int endLine = findMatchingEnd(i);
        
        int varIdx = iterVar[0] - 'A';
        int val;
        for (val = start; val <= end; val++) {
            variables[varIdx] = val;
            executeBlock(i + 1, endLine);
        }
        
        *linePtr = endLine;
        return;
    }
}

int main() {
    while (fgets(lines[lineCount], MAX_LINE_LEN, stdin)) {
        lineCount++;
    }
    
    char *valuesLine = lines[lineCount - 1];
    char *varsLine = lines[lineCount - 2];
    
    char varsCopy[MAX_LINE_LEN];
    strcpy(varsCopy, varsLine);
    trim(varsCopy);
    
    char *varNames[MAX_VARS];
    int varCount = 0;
    
    char *token = strtok(varsCopy, " ");
    while (token != NULL) {
        varNames[varCount++] = token;
        token = strtok(NULL, " ");
    }
    
    char valuesCopy[MAX_LINE_LEN];
    strcpy(valuesCopy, valuesLine);
    trim(valuesCopy);
    
    token = strtok(valuesCopy, " ");
    int valIdx = 0;
    while (token != NULL && valIdx < varCount) {
        int varIdx = varNames[valIdx][0] - 'A';
        variables[varIdx] = atoi(token);
        token = strtok(NULL, " ");
        valIdx++;
    }
    
    lineCount -= 2;
    
    int i;
    for (i = 0; i < lineCount; i++) {
        executeLine(&i);
    }
    
    return 0;
}
