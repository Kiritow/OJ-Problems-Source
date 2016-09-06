#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define maxn 60002
int maps[maxn][6];
multiset<int>se[1<<5];
multiset<int>::iterator i1,i2;
int main()
{
    int i,j,leap,x,n,m,a;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<(1<<5);i++)
            se[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&leap);
            if(leap==0)
            {
                for(j=0;j<m;j++)
                {
                    scanf("%d",&maps[i][j]);
                }
                for(a=0;a<(1<<m);a++)
                {
                    int as;
                    as=0;
                    for(j=0;j<m;j++)
                    {
                        if(a&(1<<j))as+=maps[i][j];
                        else as-=maps[i][j];
                    }
                    se[a].insert(as);
                }
            }
            else
            {
                scanf("%d",&x);
                for(a=0;a<(1<<m);a++)
                {
                    int as;
                    as=0;
                    for(j=0;j<m;j++)
                    {
                        if(a&(1<<j))as+=maps[x][j];
                        else as-=maps[x][j];
                    }
                    i1=se[a].find(as);
                    se[a].erase(i1);
                }
            }
            int ans=0;
            for(a=0;a<(1<<m);a++)
            {
                i1=se[a].begin();
                i2=se[a].end();
                i2--;
                ans=max(ans,(*i2)-(*i1));
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
