#include <stdio.h>
#include <string.h>
#define len 251
char post[len],s[len]; //post 涓哄缂琛ㄨ揪寮
int priority[len],n; //priority 涓鸿绠绗浼绾
void postfix(){
    int p,ep,i; 
char expresion[len];
    for(i=p=ep=0;i<n;i++){
        switch(s[i]){
        case '(':expresion[ep++]=s[i];
            break;
        case '+':
        case '-':for(;ep&&expresion[ep-1]!='(';post[p++]=expresion[--ep]);
            expresion[ep++]=s[i];
            break;
        case '*':
        case '/':for(;ep&&(expresion[ep-1]=='*'||expresion[ep-1]=='/');post[p++]=expresion[--ep]);
            expresion[ep++]=s[i];
            break;
        case ')':for(;ep&&expresion[--ep]!='(';post[p++]=expresion[ep]);
            break;
        default:post[p++]=s[i];
            break;
        }
    }
    while(ep)
        post[p++]=expresion[--ep];
    post[p]='\0';
}
void infix(){
    int k,p,i,tem; 
    bool c;
    char stack[len][len],s1[len],s2[len]; 
    for(i=p=0;i<n;i++){
        switch(post[i]){
        case '+':
        case '-':
        case '*':
        case '/':k=(post[i]=='*'||post[i]=='/')?2:1; 
            c=(post[i]=='-'||post[i]=='/')?true:false; 
            if(priority[p-1]&&(priority[p-1]<k||(priority[p-1]==k&&c))){
                s2[0]='(';
                s2[1]='\0';
                strcat(s2,stack[p-1]);
                strcat(s2,")");
            }
            else{
                s2[0]='\0';
                strcat(s2,stack[p-1]);
            }
            --p;
            if(priority[p-1]&&priority[p-1]<k){
                s1[0]='(';
                s1[1]='\0';
                strcat(s1,stack[p-1]);
                strcat(s1,")");
            }
            else{
                s1[0]='\0';
                strcat(s1,stack[p-1]);
            }
            strcpy(stack[p-1],s1);
            tem=(int)strlen(stack[p-1]);
            stack[p-1][tem]=post[i];
            stack[p-1][tem+1]='\0';
            strcat(stack[p-1],s2);
            priority[p-1]=k;
            break;
        default:stack[p][0]=post[i];
            stack[p][1]='\0';
            priority[p++]=0;
            break;
        }
    }
    strcpy(post,stack[0]);
}
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        n=(int)strlen(s);
        memset(post,0,sizeof(post));
        postfix();
        infix();
        puts(post);
    }
    return 0;
}
