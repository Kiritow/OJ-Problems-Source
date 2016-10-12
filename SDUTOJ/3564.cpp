#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

char mp[MAXN][MAXN];

int cc[MAXN][MAXN];

int t;
int N,M;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(mp,0,sizeof(mp));
        scanf("%d %d%*c",&N,&M);
        for(int i=1;i<=N;i++)
        {
            gets(&mp[i][1]);
        }
        memset(cc,0,sizeof(cc));
        int realn=N+2;
        int realm=M+2;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(mp[i][j]=='#')
                {
                    cc[i][j]=2;
                    //++cc[i-1][j-1];
                    ++cc[i-1][j];
                    //++cc[i-1][j+1];
                    ++cc[i][j-1];
                    ++cc[i][j+1];
                    //++cc[i+1][j-1];
                    ++cc[i+1][j];
                    //++cc[i+1][j+1];
                }
            }
        }
        int c=0;
        for(int i=0;i<realn;i++)
        {
            for(int j=0;j<realm;j++)
            {
                if(cc[i][j]==1) ++c;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
