#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm> 
#include<queue> 
using namespace std; 
struct point
{
    int pla, num;
}; 
int cmp(int x, int y)
{
    return x>y;
} 
int main()
{
    int T, i, n, m;
    scanf("%d", &T);
    while(T--)
    {
        point p[105];
        int a[105]; 
        queue<point>Q; 
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            p[i].num=a[i], p[i].pla=i;
            Q.push(p[i]); 
        }
        sort(a, a+n, cmp); 
        int maxtop=0; 
        int num=1; 
        while(1)
        {
             point x=Q.front();
             Q.pop();
            if(x.num==a[maxtop]&&x.pla!=m)
                maxtop++, num++; 
            else if(x.num==a[maxtop]&&x.pla==m)
                break;
            else
                Q.push(x);
        }
        printf("%d\n", num);
    }
    return 0; 
}
