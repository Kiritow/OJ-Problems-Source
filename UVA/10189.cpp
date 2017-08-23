#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char buff[110][110];
int mp[110][110];

int main()
{
    int cc=1;

    int n,m;
    while(scanf("%d %d%*c",&n,&m)==2&&n&&m)
    {
        if(cc!=1) printf("\n");

        printf("Field #%d:\n",cc++);
        memset(mp,0,sizeof(mp));

        for(int i=1;i<=n;i++)
        {
            scanf("%s",&buff[i][1]);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(buff[i][j]=='*')
                {
                    mp[i][j]=-999;
                    ++mp[i-1][j-1];
                    ++mp[i-1][j];
                    ++mp[i-1][j+1];
                    ++mp[i][j-1];
                    ++mp[i][j+1];
                    ++mp[i+1][j-1];
                    ++mp[i+1][j];
                    ++mp[i+1][j+1];
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j]<0)
                {
                    printf("*");
                }
                else
                {
                    printf("%d",mp[i][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
