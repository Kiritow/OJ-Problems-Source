#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int fac[15]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void slove(int n,int m,int p){
    if(n<=2*m){
        if(n!=p&&(n%2==p%2))
            printf("1\n");
        else if(n==p)
            printf("%d\n",m-(n-1)/2);
        else
            printf("0\n");
        return ;
    }
    else if(n==2*m+1){
        if(p<2*m&&p&1)
            printf("1\n");
        else
            printf("0\n");
        return ;
    }
   int t=n-2*m,i;  
    for( i=0;i<14;i++){
        if(t==fac[i]&&p==t)//杩搴璇ュ涓p==t
        {
            printf("0\n");
            return;
        }
    }
    for( i=1;i<14;i++)
        if(t<fac[i])
        {
            if(p>2*m+fac[i-1]&&p<2*m+fac[i])
                 printf("Thrown\n");
            else
                 printf("0\n");
            return ;
        }
}
int main(){
    int t,n,m,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&p);
        slove(n,m,p);
    }
    return 0;
}
