#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<stack>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<list>
#include<vector>
using namespace std;
int n;
int from[1000][11];
int to[1000][11];
int l;
int s[11],e[11];
bool vist[100000];
bool ans;
int get(int f[])
{
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=i*11+f[i];
    return sum;
}
bool yes(int *a,int *b)
{
    for (int i=0;i<n;i++)
    {
        if (a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
void dfs(int *f)
{
    int i,j,k;
    if  (yes(f,e))
    {
        ans=true;
        return ;
    }
    for (i=0;i<l;i++)
    {
        k=get(from[i]);
        if (!vist[k]&&yes(from[i],f))
        {
            vist[k]=true;
            dfs(to[i]);
            vist[k]=false;
        }
        k=get(to[i]);
        if (!vist[k]&&yes(to[i],f))
        {
            vist[k]=true;
            dfs(from[i]);
            vist[k]=false;
        }
    }
}
void put()
{
    int i,j,k;
    for (i=0;i<l;i++)
    {
        for (j=0 ;j<n;j++)
            cout<<from[i][j]<<' ';
        for (j=0;j<n;j++)
            cout<<to[i][j]<<' ';
        cout<<endl;
    }
}
int main()
{
    int i,j,k;
    int num=0;
    while (cin>>n,n)
    {
        num++;
        l=0;
        for (i=0;i<n;i++)
            cin>>s[i];
        for (i=0;i<n;i++)
            cin>>e[i];
        while (cin>>k)
        {
            if (k<0)
                break;
            from[l][0]=k;
            for (i=1;i<n;i++)
                cin>>from[l][i];
            for (i=0;i<n;i++)
                cin>>to[l][i];
            l++;
        }
        memset(vist,false,sizeof(vist));
        ans=false;
        dfs(s);
        if (ans)
            printf("Maze #%d can be travelled\n",num);
        else
            printf("Maze #%d cannot be travelled\n",num);
    }
}
