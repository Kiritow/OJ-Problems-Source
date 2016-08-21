#include<iostream>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string a[110];
int vis[200];
int n,m;
struct Node
{
    int x1,y1,x2,y2;
};
Node res;
int check(int x,int y)
{
    res.x1=x,res.y1=y;
    int i=x,j=y;
    while(j<m&&a[i][j]==a[x][y]) j++;j--;
    if(j-y<=1) return 0;
    while(i<n&&a[i][j]==a[x][y]) i++;i--;
    if(i-x<=1) return 0;
    res.x2=i,res.y2=j;
    while(j>=0&&a[i][j]==a[x][y]) j--;j++;
    while(i>=0&&a[i][j]==a[x][y]) i--;i++;
    if(i==x&&j==y) return 1;
    return 0;
}
int ok(int x,int y)
{
    for(int i=res.x1+1;i<res.x2;i++)
    {
        for(int j=res.y1+1;j<res.y2;j++)
        {
            if(a[i][j]!='.') return 0;
        }
    }
    return 1;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        string cnt;
        for(int i=0;i<n;i++) cin>>a[i];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='.') continue;
                if(vis[int(a[i][j])]) continue;
                if(isalpha(a[i][j]))
                {
                    vis[int(a[i][j])]=1;
                    if(check(i,j)&&ok(i,j))
                    {
                        cnt+=a[i][j];
                    }
                }
            }
        }
        sort(cnt.begin(),cnt.end());
        cout<<cnt<<endl;
    }
    return 0;
}
