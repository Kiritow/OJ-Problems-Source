#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10010;
int F[MAXN];
int num[MAXN];
int mo[MAXN];
int n;
void init()
{
    for(int i=1;i<=n;i++)
    {
        F[i]=-1;
        num[i]=1;
        mo[i]=0;
    }
}
int find(int x)
{
    if(F[x]==-1)return x;
    int t=F[x];
    F[x]=find(F[x]);
    mo[x]+=mo[t];
    return F[x];
}
void bing(int a,int b)
{
    int t1=find(a);
    int t2=find(b);
    if(t1!=t2)
    {
        F[t1]=t2;
        num[t2]+=num[t1];
        mo[t1]=1;
    }
}
int main()
{
    int m;
    int T;
    char str[10];
    int a,b;
    int iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&m);
        init();
        printf("Case %d:\n",iCase);
        while(m--)
        {
            scanf("%s",&str);
            if(str[0]=='T')
            {
                scanf("%d%d",&a,&b);
                bing(a,b);
            }
            else
            {
                scanf("%d",&a);
                int t=find(a);
                printf("%d %d %d\n",t,num[t],mo[a]);
            }
        }
    }
    return 0;
}
