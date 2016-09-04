#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 10002
#define PUTS(M,x) for(int k=0;k<M;k++) putchar(x)
#define ll long long
using namespace std;
char c[MAX];
int l;
ll a[MAX];
char ss[MAX<<4][20];
int len[MAX];
int tot;
typedef struct{
    ll fz,fm;
}fs;
fs A[3],p;
void cons(int l){
    if(c[0]=='L'){
        a[0]=0; a[1]=2; tot=1;
    }else{
        a[0]=2; tot=0;
    }
    for(int i=1;i<l;i++){
        if(c[i]==c[i-1]) a[tot]++;
        else{
            a[tot]--;
            a[++tot]=2;
        }
    }
    tot++;
}
int main()
{
    int M;
    while(scanf("%s",c)!=EOF){
        l=strlen(c);
        cons(l);
        for(int i=0;i<tot;i++) sprintf(ss[i],"%I64d",a[i]);
        len[tot-1]=strlen(ss[tot-1]);
        len[tot-2]=strlen(ss[tot-2]) + 3 + strlen(ss[tot-1]);
        for(int i=tot-3;i>=0;i--){
            len[i]=strlen(ss[i]) + 3 + len[i+1];
        }
        M=len[0];
        for(int i=0;i<tot-1;i++){
            PUTS(M-1,' ');  putchar('1');   putchar('\n');
            PUTS(M-len[i],' ');
            printf("%s + ",ss[i]);
            PUTS(len[i+1],'-');
            putchar('\n');
        }
        PUTS(M-(int)strlen(ss[tot-1]),' ');
        printf("%s",ss[tot-1]);
        printf("\n");
    }
    return 0;
}
