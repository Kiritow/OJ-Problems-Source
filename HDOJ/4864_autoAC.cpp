#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    int x,y;
} s1[100005],s2[100005];
int cmp(node a,node b)
{
    if(a.x == b.x)
        return a.y>b.y;
    return a.x>b.x;
}
int main()
{
    int n,m,i,j,cnt;
    __int64 sum;
    while(~scanf("%d%d",&n,&m))
    {
        for(i = 0; i<n; i++)
            scanf("%d%d",&s1[i].x,&s1[i].y);
        for(i = 0; i<m; i++)
            scanf("%d%d",&s2[i].x,&s2[i].y);
        sort(s1,s1+n,cmp);
        sort(s2,s2+m,cmp);
        cnt = sum = 0;
        int c[105] = {0};
        for(i = 0,j = 0; i<m; i++)
        {
            while(j<n && s1[j].x>=s2[i].x)
            {
                c[s1[j].y]++;
                j++;
            }
            for(int k = s2[i].y; k<=100; k++)
            {
                if(c[k])
                {
                    c[k]--;
                    sum+=(s2[i].x*500+s2[i].y*2);
                    cnt++;
                    break;
                }
            }
        }
        printf("%d %I64d\n",cnt,sum);
    }
}
