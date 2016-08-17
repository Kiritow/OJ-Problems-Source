#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int M=2005;
#define min(a,b) a<b?a:b
int map[M][M];
#define inf 0xffffff
int main()
{
    int n,m,i,j,k,s,e,l,s1,e1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                map[i][j]=inf;
            for(i=0;i<m;i++)
            {
                scanf("%d%d%d",&s,&e,&l);
                if(map[s][e]>l)
                    map[s][e]=map[e][s]=l;
            }
            for(k=0;k<n;k++)
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                        map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
                    scanf("%d%d",&s1,&e1);
                    if(s1==e1)
                        printf("0\n");
                    else if(map[s1][e1]==inf)
                        printf("-1\n");
                    else
                        printf("%d\n",map[s1][e1]);
    }
    return 0;
}
