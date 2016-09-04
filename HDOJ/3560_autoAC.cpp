#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,m,pre[N],flag[N],degree[N];
int main()
{
    int i;
    int a,b,t1,tt1,t2,tt2,f1,f2;
    int ans1,ans2;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)    {degree[i]=flag[i]=0;pre[i]=i;}
        while(m--)
        {
            scanf("%d%d",&a,&b);
            degree[a]++;
            degree[b]++;
            f1=pre[a];
            f2=pre[b];
            while(pre[f1]!=f1)    f1=pre[f1];
            while(pre[f2]!=f2)    f2=pre[f2];
            t1=a;
            t2=b;
            while(pre[t1]!=f1)    {tt1=pre[t1];pre[t1]=f1;t1=tt1;}
            while(pre[t2]!=f2)    {tt2=pre[t2];pre[t2]=f2;t2=tt2;}
            if(f1==f2)    continue;
            pre[f1]=pre[f2];
        }
        ans1=ans2=0;
        for(i=0;i<n;i++)
        {
            f1=pre[i];
            while(pre[f1]!=f1)    f1=pre[f1];
            t1=i;
            while(pre[t1]!=f1)    {tt1=pre[t1];pre[t1]=f1;t1=tt1;}
            if(degree[i]!=2)    flag[f1]=1;
        }
        for(i=0;i<n;i++)
        {
            if(pre[i]!=i)    continue;
            ans1++;
            if(!flag[i])    ans2++;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
