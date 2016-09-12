#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 500005
struct point{
    int i, v;
}p[M];
struct node
{
    int v;
    int cur;
}s[M];
int has[M],  res[M];
bool cmp (point a, point b)
{
    return a.v > b.v;
}
int S()
{
    int ret=0,ok=0;
    char c;
    while((c=getchar()))
    {
        if(c>='0'&&c<='9')
        ret=(ret<<3)+ret+ret+c-'0',ok=1;
        else if(ok)
        return ret;
    }
    return ret;
}
bool cmp2(node a,node b)
{
    return a.v<b.v;
}
int main()
{
    int  n, d, i, j, ans;
    while (~scanf("%d%d",&n,&d))
    {
        for (i = 0; i < n; i++)
        {
            p[i].v=S();
            p[i].i = i+1;
        }
        sort(p, p+n, cmp);
        for (j = 0; j < d; j++)
        {
            s[j].v=S();
            s[j].cur=j;
        }
        sort(s,s+d,cmp2);
        memset(has, 0, sizeof(has));
        ans = 0;
        for (i = 0, j = d - 1; j >= 0; j--)
        {
            for ( ; i < n; i++) 
            {
                if (p[i].v <= s[j].v)
                    break;
                int id = p[i].i;
                has[id] = 1;
                if (!has[id-1] && !has[id+1]) ++ans;
                else if (has[id-1] && has[id+1]) --ans;
            }
            res[s[j].cur] = ans;
        }
        for (i = 0; i < d; i++)
        {
            printf ("%d\n", res[i]);
        }
    }
    return 0;
}
