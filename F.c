#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORDS 10000

char words[MAX_WORDS][200];
int wordCount=0;
int evenW=75,oddW=75;
int useHyphen=0;

int isEmail(char *w){
    return strchr(w,'@')!=NULL;
}

int isURL(char *w){
    return strncmp(w,"http://",7)==0||strncmp(w,"https://",8)==0;
}

int isBullet(char *w){
    int len=strlen(w);
    if(len==0)return 0;
    if(strcmp(w,"*")==0||strcmp(w,"-")==0)return 1;
    if(len>=2&&isdigit(w[0])){
        if(w[len-1]=='.'||w[len-1]==')'){
            for(int i=1;i<len-1;i++){
                if(!isdigit(w[i]))return 0;
            }
            return 1;
        }
    }
    return 0;
}

void extractWords(char lines[][MAX_LINE],int n){
    int lastWasBlank=0;
    for(int i=0;i<n;i++){
        int isBlank=1;
        for(int j=0;lines[i][j];j++){
            if(lines[i][j]!=' '&&lines[i][j]!='\t'){
                isBlank=0;
                break;
            }
        }
        if(isBlank){
            if(!lastWasBlank&&wordCount>0&&strcmp(words[wordCount-1],"PARA_BREAK")!=0){
                strcpy(words[wordCount++],"PARA_BREAK");
            }
            lastWasBlank=1;
            continue;
        }
        lastWasBlank=0;
        char temp[MAX_LINE];
        strcpy(temp,lines[i]);
        char *tok=strtok(temp," \t");
        while(tok){
            if((tok[0]=='*'||tok[0]=='-')&&strlen(tok)>1){
                char bullet[2]={tok[0],0};
                strcpy(words[wordCount++],bullet);
                strcpy(words[wordCount++],tok+1);
            }else{
                int len=strlen(tok);
                if(len>=3&&isdigit(tok[0])&&(tok[1]=='.'||tok[1]==')')&&!isdigit(tok[2])){
                    char bullet[3]={tok[0],tok[1],0};
                    strcpy(words[wordCount++],bullet);
                    strcpy(words[wordCount++],tok+2);
                }else if(len>=4&&isdigit(tok[0])&&isdigit(tok[1])&&(tok[2]=='.'||tok[2]==')')&&!isdigit(tok[3])){
                    char bullet[4]={tok[0],tok[1],tok[2],0};
                    strcpy(words[wordCount++],bullet);
                    strcpy(words[wordCount++],tok+3);
                }else{
                    strcpy(words[wordCount++],tok);
                }
            }
            tok=strtok(NULL," \t");
        }
    }
}

void addWord(char *line,char *word,int *len,int maxWidth){
    int wordLen=strlen(word);
    if(*len==0){
        strcpy(line,word);
        *len=wordLen;
    }else{
        strcat(line," ");
        strcat(line,word);
        *len+=1+wordLen;
    }
}

void formatText(){
    char line[MAX_LINE]="";
    int len=0;
    int idx=0;
    int i=0;
    
    while(i<wordCount){
        if(strcmp(words[i],"PARA_BREAK")==0){
            if(len>0){
                printf("%s\n",line);
                line[0]=0;
                len=0;
                idx++;
            }
            printf("\n");
            i++;
            continue;
        }
        
        int maxW=(idx%2==0)?evenW:oddW;
        
        if(isBullet(words[i])){
            if(len>0){
                printf("%s\n",line);
                line[0]=0;
                len=0;
                idx++;
                maxW=(idx%2==0)?evenW:oddW;
            }
            strcpy(line,words[i]);
            strcat(line," ");
            len=strlen(line);
            i++;
            continue;
        }
        
        char *w=words[i];
        int wLen=strlen(w);
        
        if(isEmail(w)||isURL(w)){
            if(len==0){
                strcpy(line,w);
                len=wLen;
                i++;
            }else if(len+1+wLen<=maxW){
                strcat(line," ");
                strcat(line,w);
                len+=1+wLen;
                i++;
            }else{
                printf("%s\n",line);
                strcpy(line,w);
                len=wLen;
                idx++;
                i++;
            }
            continue;
        }
        
        if(len==0){
            if(wLen<=maxW){
                strcpy(line,w);
                len=wLen;
                i++;
            }else if(useHyphen){
                int fit=maxW-1;
                if(fit>0&&fit<wLen){
                    strncpy(line,w,fit);
                    line[fit]=0;
                    strcat(line,"-");
                    printf("%s\n",line);
                    char tmp[200];
                    strcpy(tmp,w+fit);
                    strcpy(words[i],tmp);
                    line[0]=0;
                    len=0;
                    idx++;
                }else{
                    strcpy(line,w);
                    len=wLen;
                    i++;
                }
            }else{
                strcpy(line,w);
                len=wLen;
                i++;
            }
        }else{
            if(len+1+wLen<=maxW){
                strcat(line," ");
                strcat(line,w);
                len+=1+wLen;
                i++;
            }else{
                if(useHyphen&&wLen>1){
                    int space=maxW-len-1;
                    if(space>=2){
                        int take=space-1;
                        if(take>0&&take<wLen){
                            strcat(line," ");
                            strncat(line,w,take);
                            strcat(line,"-");
                            printf("%s\n",line);
                            char tmp[200];
                            strcpy(tmp,w+take);
                            strcpy(words[i],tmp);
                            line[0]=0;
                            len=0;
                            idx++;
                        }else{
                            printf("%s\n",line);
                            line[0]=0;
                            len=0;
                            idx++;
                        }
                    }else{
                        printf("%s\n",line);
                        line[0]=0;
                        len=0;
                        idx++;
                    }
                }else{
                    printf("%s\n",line);
                    line[0]=0;
                    len=0;
                    idx++;
                }
            }
        }
    }
    
    if(len>0){
        printf("%s\n",line);
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    
    char lines[100][MAX_LINE];
    for(int i=0;i<n;i++){
        fgets(lines[i],MAX_LINE,stdin);
        int len=strlen(lines[i]);
        if(len>0&&lines[i][len-1]=='\n')lines[i][len-1]=0;
    }
    
    char cmd[MAX_LINE];
    fgets(cmd,MAX_LINE,stdin);
    
    if(strstr(cmd," h "))useHyphen=1;
    if(strstr(cmd," h\n"))useHyphen=1;
    if(strncmp(cmd,"h ",2)==0)useHyphen=1;
    
    char *p=strstr(cmd,"-w-e ");
    if(p){
        sscanf(p+5,"%d",&evenW);
    }
    p=strstr(cmd,"-w-o ");
    if(p){
        sscanf(p+5,"%d",&oddW);
    }
    p=strstr(cmd,"-w ");
    if(p&&!strstr(cmd,"-w-e")&&!strstr(cmd,"-w-o")){
        int w;
        if(sscanf(p+3,"%d",&w)==1){
            evenW=oddW=w;
        }
    }
    
    extractWords(lines,n);
    formatText();
    
    return 0;
}


