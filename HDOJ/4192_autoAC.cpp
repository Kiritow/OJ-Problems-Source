#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 10005
char str[N];
int num[N];
char op[N];
int v[11];
int id[11];
char cmp(char a,char b){
    if(a=='+'){
        if(b=='+' || b=='-' || b==')')return '>';
        else return '<';
    }
    if(a=='-'){
        if(b=='+' || b=='-' || b==')')return '>';
        else return '<';
    }
    if(a=='*'){
        if(b=='(')return '<';
        else return '>';
    }
    if(a=='('){
       if(b==')')return '=';
       else return '<';
    }
    if(a==')'){
        return '>';
    }
}
int cal(int a,int b,char c){
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
}
int gao(){
    int i,j;
    int topnum = 0,topop = 1;
    int k = 1;
    op[1] = '(';
    for(i=1;str[i];i++){
        if(islower(str[i])){
            topnum++;
            num[topnum] = v[id[k++]];
        } else {
            char c = cmp(op[topop],str[i]);
            char tag;
            if(c=='<'){
                topop++;
                op[topop] = str[i];
            } else if(c=='='){
                topop--;
            } else if(c=='>'){
                int b = num[topnum--];
                int a = num[topnum--];
                tag = op[topop--];
                int res = cal(a,b,tag);
                topnum++;
                num[topnum] = res;
                i--;
            }
        }
    }
    return num[topnum];
}
int main(){
    int n;
    while(scanf("%d",&n) && n){
        int i,j;
        for(i=1;i<=n;i++){
            scanf("%d",&v[i]);
            id[i] = i;
        }
        int ans;
        scanf("%d",&ans);
        scanf("%s",str+1);
        int len = strlen(str+1);
        str[0] = '(',str[len+1] = ')',str[len+2] = '\0';
        bool ok =0;
        do{
            int tmp = gao();
            if(tmp==ans){
                ok = 1;
                break;
            }
        }while(next_permutation(id+1,id+1+n));
        if(ok)puts("YES");
        else puts("NO");
    }
    return 0;
}
