#include<cstdio>  
#include<string.h>  
using namespace std;  
int fib[20],sg[1010],m,n,p;  
int calsg(int now){  
    int i,tem;  
    int next[20];  
    memset(next,0,sizeof(next));  
    for(i=1;fib[i]<=now;i++){  
        tem=now-fib[i];  
        if(sg[tem]==-1)  
            sg[tem]=calsg(tem);  
        next[sg[tem]]=1;  
    }  
    for(i=0;;i++)  
        if(next[i]==0){  
            return i;  
        }  
}   
int main(){  
    int i,j,tem;  
    fib[1]=1;  
    fib[2]=2;  
    for(i=3;i<=16;i++)     
        fib[i]=fib[i-1]+fib[i-2];  
    memset(sg,-1,sizeof(sg));  
    while(scanf("%d %d %d",&m,&n,&p)==3 && !(m==0 && n==0 && p==0)){  
        tem=calsg(m)^calsg(n)^calsg(p);  
        if(tem==0)  
            printf("Nacci\n");  
        else   
            printf("Fibo\n");  
    }  
}
