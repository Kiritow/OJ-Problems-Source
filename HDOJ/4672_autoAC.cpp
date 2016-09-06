#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#define I(x) scanf("%d",&x)
using namespace std;
int sg[10001],a[100001];
char x[20],y[20];
int main(){
    int n,m,i,j,MIN,b,t,ans;
    while(scanf("%d%d%s%s",&n,&m,x,y)!=EOF){
        memset(sg,-1,sizeof(sg));
        sg[0]=0;MIN=1e9;
        bool flag=0;
        for(i=0;i<n;i++) I(a[i]);
        for(i=0;i<m;i++){
            I(b);
            MIN=min(MIN,b);
            for(j=0;j+b<=10000;j++)
                if(sg[j]>=0)
                    sg[j+b]=max(sg[b+j],sg[j]+1);
        }
        ans=0;
        for(i=0;i<n;i++){
            t=a[i];
            if(t<=10000){
                if(sg[t]<0) flag=1;
                else ans^=sg[t];
            }
            else{
                t=(t-10000+MIN)%MIN+10000-MIN;
                if(sg[t]<0) flag=1;
                else ans^=sg[t]+(a[i]-t)/MIN;
            }
        }
        if(!flag&&ans) puts(x);
        else puts(y);
    }
    return 0;
}
