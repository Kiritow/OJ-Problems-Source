#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define sf scanf
int T;
int a[5],b[5];
int d[1000005];
int main()
{
    sf("%d",&T);
    while(T--)
    {
        for(int i = 0;i<3;i++)sf("%d",a+i);
        for(int i = 0;i<3;i++)sf("%d",b+i);
        int sum = 0;
        for(int i = 0;i<3;i++)sum+=a[i];
        if( (a[1]&1) || (b[1]&1) )
        {
            puts("-1");
            continue;
        }
        if(sum==4)
        {
            puts("4\n1 2 0\n1 3 0\n2 3 1\n3 4 1");
            continue;
        }
        printf("%d\n",a[1]/2+a[2]+b[1]/2+b[2]);
        int t = 1;
        while(a[2]!=-1){printf("%d %d 0\n",t,t+1);t++;a[2]--;}t++;
        while(a[1]!=2){printf("%d %d 0\n",t,t+1);t+=2;a[1]-=2;}
            int tt = 0;
            for(int i = 1;i<=sum;i+=2) d[tt++] = i;
            for(int i = 2;i<=sum;i+=2)d[tt++] = i;
        t = 0;
        while(b[2]!=-1){printf("%d %d 1\n",min(d[t],d[t+1]),max(d[t],d[t+1]));t++;b[2]--;}t++;
        while(b[1]!=2){printf("%d %d 1\n",min(d[t],d[t+1]),max(d[t],d[t+1]));t+=2;b[1]-=2;}
    }
}
