#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std; 
struct park
{
    int x, y;
}; 
int main()
{
    int i, j, n, m, T, k, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        park p[2505]; 
        int turn[55];
        memset(turn, 0, sizeof(turn)); 
        int num=0; 
        for(i=1; i<=n; i++)
        { 
            turn[i]=1; 
            for(j=1; j<=m; j++)
            {
                scanf("%d", &k);
                if(k==-1) 
                    continue;
                num++;
                p[k].x=i, p[k].y=j;
            }
        } 
        int total=0; 
        int mid; 
        for(i=1; i<=num; i++)
        {
            if(p[i].y>turn[p[i].x])
                 mid=p[i].y-turn[p[i].x];
            else
                mid=turn[p[i].x]-p[i].y; 
            total+=20*(p[i].x-1)+5*(min(mid, m-mid));
            turn[p[i].x]=p[i].y;
        }
        printf("%d\n", total);
    }
}
