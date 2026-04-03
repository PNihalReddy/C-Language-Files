#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LEN 200

char lines[MAX_LINES][MAX_LEN];
int lineCount=0;
int vars[26];

int isNumber(char *s){
    int i=0;
    if(s[i]=='-'||s[i]=='+')i++;
    if(!s[i])return 0;
    while(s[i]){
        if(!isdigit(s[i]))return 0;
        i++;
    }
    return 1;
}

int getValue(char *s){
    while(*s==' ')s++;
    char temp[50];
    int i=0;
    while(s[i]&&s[i]!=' '&&s[i]!='\n'&&s[i]!='\r')temp[i]=s[i],i++;
    temp[i]=0;
    if(isNumber(temp))return atoi(temp);
    return vars[temp[0]-'A'];
}

int evalCondition(char *cond){
    char left[50],op[5],right[50];
    int i=0,j=0;
    while(cond[i]&&cond[i]!='='&&cond[i]!='!'&&cond[i]!='<'&&cond[i]!='>')left[j++]=cond[i++];
    left[j]=0;
    j=0;
    while(cond[i]&&(cond[i]=='='||cond[i]=='!'||cond[i]=='<'||cond[i]=='>'))op[j++]=cond[i++];
    op[j]=0;
    j=0;
    while(cond[i])right[j++]=cond[i++];
    right[j]=0;
    int lv=getValue(left);
    int rv=getValue(right);
    if(strcmp(op,"==")==0)return lv==rv;
    if(strcmp(op,"!=")==0)return lv!=rv;
    if(strcmp(op,"<=")==0)return lv<=rv;
    if(strcmp(op,">=")==0)return lv>=rv;
    if(strcmp(op,"<")==0)return lv<rv;
    if(strcmp(op,">")==0)return lv>rv;
    return 0;
}

void execute(int start,int end);

void executeIf(int idx,int end){
    char *line=lines[idx];
    char cond[100];
    int i=3;
    while(line[i]==' ')i++;
    int j=0;
    while(line[i])cond[j++]=line[i++];
    cond[j]=0;
    int yesIdx=-1,noIdx=-1,endIdx=-1;
    int depth=0;
    for(int k=idx+1;k<=end;k++){
        if(strncmp(lines[k],"if ",3)==0||strncmp(lines[k],"for ",4)==0)depth++;
        if(strcmp(lines[k],"end")==0){
            if(depth==0){endIdx=k;break;}
            depth--;
        }
        if(strcmp(lines[k],"Yes")==0&&depth==0)yesIdx=k;
        if(strcmp(lines[k],"No")==0&&depth==0)noIdx=k;
    }
    if(evalCondition(cond)){
        if(yesIdx!=-1){
            int yesEnd=(noIdx!=-1)?noIdx-1:endIdx-1;
            execute(yesIdx+1,yesEnd);
        }
    }else{
        if(noIdx!=-1){
            execute(noIdx+1,endIdx-1);
        }
    }
}

void executeFor(int idx,int end){
    char *line=lines[idx];
    char varName[10],startVal[50],endVal[50];
    int i=4;
    while(line[i]==' ')i++;
    int j=0;
    while(line[i]&&line[i]!=' ')varName[j++]=line[i++];
    varName[j]=0;
    while(line[i]==' ')i++;
    j=0;
    while(line[i]&&line[i]!=' ')startVal[j++]=line[i++];
    startVal[j]=0;
    while(line[i]==' ')i++;
    j=0;
    while(line[i])endVal[j++]=line[i++];
    endVal[j]=0;
    int depth=0;
    int endIdx=-1;
    for(int k=idx+1;k<=end;k++){
        if(strncmp(lines[k],"if ",3)==0||strncmp(lines[k],"for ",4)==0)depth++;
        if(strcmp(lines[k],"end")==0){
            if(depth==0){endIdx=k;break;}
            depth--;
        }
    }
    int sv=getValue(startVal);
    int ev=getValue(endVal);
    int varIdx=varName[0]-'A';
    if(sv<=ev){
        for(int v=sv;v<=ev;v++){
            vars[varIdx]=v;
            execute(idx+1,endIdx-1);
        }
    }else{
        for(int v=sv;v>=ev;v--){
            vars[varIdx]=v;
            execute(idx+1,endIdx-1);
        }
    }
}

Yash Raj, [01-Nov-25 11:17 AM]
void execute(int start,int end){
    for(int i=start;i<=end;i++){
        if(strncmp(lines[i],"if ",3)==0){
            int depth=0;
            int endIdx=-1;
            for(int k=i+1;k<=end;k++){
                if(strncmp(lines[k],"if ",3)==0||strncmp(lines[k],"for ",4)==0)depth++;
                if(strcmp(lines[k],"end")==0){
                    if(depth==0){endIdx=k;break;}
                    depth--;
                }
            }
            executeIf(i,endIdx);
            i=endIdx;
        }else if(strncmp(lines[i],"for ",4)==0){
            int depth=0;
            int endIdx=-1;
            for(int k=i+1;k<=end;k++){
                if(strncmp(lines[k],"if ",3)==0||strncmp(lines[k],"for ",4)==0)depth++;
                if(strcmp(lines[k],"end")==0){
                    if(depth==0){endIdx=k;break;}
                    depth--;
                }
            }
            executeFor(i,endIdx);
            i=endIdx;
        }else if(strncmp(lines[i],"print ",6)==0){
            char *p=lines[i]+6;
            while(*p==' ')p++;
            printf("%d\n",getValue(p));
        }
    }
}

int main(){
    while(fgets(lines[lineCount],MAX_LEN,stdin)){
        int len=strlen(lines[lineCount]);
        if(len>0&&lines[lineCount][len-1]=='\n')lines[lineCount][len-1]=0;
        lineCount++;
    }
    char varLine[MAX_LEN],valLine[MAX_LEN];
    strcpy(varLine,lines[lineCount-2]);
    strcpy(valLine,lines[lineCount-1]);
    lineCount-=2;
    char *tok=strtok(varLine," ");
    int idx=0;
    char varNames[26][5];
    int varCnt=0;
    while(tok){
        strcpy(varNames[varCnt++],tok);
        tok=strtok(NULL," ");
    }
    tok=strtok(valLine," ");
    idx=0;
    while(tok){
        int val=atoi(tok);
        int vidx=varNames[idx][0]-'A';
        vars[vidx]=val;
        idx++;
        tok=strtok(NULL," ");
    }
    execute(0,lineCount-1);
    return 0;
}