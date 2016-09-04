#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double PI = 3.1415926 * 2;
int t,n;
double r;
double dis_tance;
double minn;
int map[100010];
int main()
{
    scanf("%d",&t);
    while(t --)
    {
        minn = 100000.00;
        scanf("%d%lf",&n,&r);
        memset(map,0,sizeof(map));
        for(int i = 1;i <= n;i ++)
              scanf("%d",&map[i]);
        if(map[1] == map[n])
            printf("inf\n");
        else
        {
            sort(map + 1,map + n + 1);
            dis_tance = (PI * r) / n;
            for(int i = n;i > 1;i --)
               if(dis_tance / (map[i] - map[i - 1]) < minn)
                  minn = dis_tance / (map[i] - map[i - 1]);
            printf("%.3lf\n",minn);
        }
    }
    return 0;
}
