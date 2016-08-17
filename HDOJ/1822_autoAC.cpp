#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int map1[5000][5000],map2[5000][5000];
int m,n;
bool check(int x ,int y)
{
    int i ,j,maxx = map2[y][x];
    for(i = 1; i <=n; i++)
    if(map2[i][x] > maxx) return false;
    return true;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        scanf("%d",&map1[i][j]);//cin>>map1[i][j];
        for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        scanf("%d",&map2[i][j]);//cin>>map2[i][j];
        int ans = 0,max1 = 0,max2 = 0;
        for(i = 1; i <= n; i++)
        {
            int maxx = map1[1][i];
            for(j = 2; j <= m; j++)
            if(map1[j][i] > maxx) maxx = map1[j][i];
            for(j = 1; j <= m; j++)
            {
                if(map1[j][i] == maxx)
                {
                    if(check(j,i))
                    {
                        ans++;
                        max1 = map1[j][i];
                        max2 = map2[i][j];
                    }
                }
            }
        }
        if(ans == 1) printf("%d %d\n",max1,max2);//cout<<c[1].x<<" "<<c[1].y<<endl;
        else printf("Have %d Nash Points.\n",ans);
    }
    return 0;
}
