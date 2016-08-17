#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10001;
int n,m,ans[maxn];
void DFS(int cur)
{
    for(int i=0;i<m;i++)
    {
    ans[cur]=i;
    bool is=false;
    for(int j=1;2*j<=cur+1;j++)
    {
        bool flag=0;
        for(int k=0;k<j;k++)
        if(ans[cur-j-k]!=ans[cur-k])
        {
            flag=1;
            break;
        }
        if(!flag)
        {
        is=true;
        break;
        }
    }
    if(is)
        continue;
    if(--n==0)
    {
        for(int i=0;i<=cur;i++)
        {
        if(i&&i%64==0)
            printf("\n");
        else if(i&&i%4==0)
            printf(" ");
        printf("%c",'A'+ans[i]);
        }
        printf("\n%d\n",cur+1);
        return;
    }
    DFS(cur+1);
    if(!n)
        return;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
    DFS(0);
    }
    return 0;
}
