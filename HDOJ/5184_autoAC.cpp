#include <cstdio>
#include <iostream>
#include <cstring> 
#include <cctype> 
#include <algorithm> 
#define LL __int64
using namespace std;
const LL N=1000005;
const LL MOD=1000000007;
LL mod[N];
LL ny[N];
char str[N];
int n;
LL C(int a,int b){
    if(b<0 || a<0 || a<b) return 0;
    return mod[a]*ny[b]%MOD*ny[a-b]%MOD;
}
int for_ny(int a,int m){
    int p=1,q=0,b=m,c,d;
    while(b>0){
        c=a/b;
        d=a; a=b; b=d%b;
        d=p; p=q; q=d-c*q;
    }
    return p<0?p+m:p;
}
int main(){
    mod[0]=1;
    ny[0]=for_ny(mod[0],MOD);
    for(int i=1;i<N;i++){
        mod[i]=(mod[i-1]*i)%MOD;
        ny[i]=(LL)for_ny((int)mod[i],(int)MOD);
    }
    while(scanf("%d",&n)!=EOF){
        getchar();
        scanf("%s",str);
        if(n%2){
            puts("0");
            continue;
        }
        int len=strlen(str);
        int p=0,q=0,i;
        for(i=0;i<len;i++){
            if(str[i]=='(') p++;
            if(str[i]==')') q++;
            if(q>p) break;
        }
        if(i<len){
            puts("0");
            continue;
        }
        n/=2;
        q=n-q,p=n-p;
        if(q<0||p<0){
            puts("0");
            continue;
        }
        int m=p+q;
        LL ans=(C(m,q)-C(m,q+1)+MOD)%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}
