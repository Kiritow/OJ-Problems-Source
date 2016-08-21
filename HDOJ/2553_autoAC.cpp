#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int n,vis[15][15],a[15][15],ok,b[15];
void dfs(int num,int x)
{
    if(num==n)
        ok++;
    if(x==n+1)
        return;
    for(int i=1;i<=n;i++)
    {
        int he=1;
        if(!vis[x][i])
        {
            for(int l=1;l<x;l++)
            {
                if(vis[l][i])
                {
                    he=0; 
                    break;
                }
                for(int j=1;j<=n;j++)
                {
                    int k1=abs(x-l),k2=abs(i-j);
                    if(k1==k2 && vis[l][j])
                    {
                        he=0;
                        break;
                    }
                    if(he==0)
                        break;
                }
            }
            if(he)
            {
                vis[x][i]=1;
                dfs(num+1,x+1);
                vis[x][i]=0;
            }
        }
    }
}
int main()
{
        for(n=1;n<=10;n++)
        {
            memset(vis,0,sizeof(vis));
            ok=0;
            dfs(0,1);
            b[n]=ok;
        }
    int z;
    while(cin>>z,z)
    {
        cout<<b[z]<<endl;
    }
    return 0;
}
