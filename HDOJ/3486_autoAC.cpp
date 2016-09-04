#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,l,r,m,tn,temp,t,M,ss;
int f[200001][18];
int lg[200001];
void pre_rmq()
{
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
}
int find(int x,int y)
{
    t=lg[y-x+1];
    return max(f[x][t],f[y-(1<<t)+1][t]);
}
bool check(int k)
{
    tn=n/k*k;
    temp=0;
    for(int i=1;i<=tn;i=i+tn/k)
    temp+=find(i,i+tn/k-1);
    if(temp>=M+1) return 1;
    return 0;
}
int main()
{
    for(int i=2;i<=200000;i++)
    lg[i]=lg[i>>1]+1;
    while(scanf("%d%d",&n,&M)!=EOF)
    {
        ss=0;
        if(n==-1&&M==-1) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i][0]);
            ss+=f[i][0];
        }
        if(ss<=M)
        {
            printf("-1\n");
            continue;
        }
        pre_rmq();
        l=1;r=n;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(check(m)) r=m-1;
            else l=m+1;
        }
        printf("%d\n",l);
    }
}
