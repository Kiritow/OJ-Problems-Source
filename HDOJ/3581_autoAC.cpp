#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct segment
{
    int s, e;
    bool operator <(const segment &t)const
    {
        return e>t.e;
    }
}seg[100005];
int p[505], n, m;
int num[505][505];
bool cmp(segment a, segment b)
{
    if(a.s==b.s)return a.e<b.e;
    return a.s<b.s;
}
int main()
{
    int t, ca, i, j, k;
    scanf("%d", &ca);
    for(t=1; t<=ca; t++)
    {
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)
            scanf("%d%d", &seg[i].s, &seg[i].e);
        sort(seg, seg+n, cmp);
        for(i=0; i<m; i++)
            scanf("%d", &p[i]);
        memset(num, 0, sizeof(num));
        segment ts;
        k=0;
        for(i=0; i<m; i++)
        {
            priority_queue<segment> q;
            for(; k<n; k++)
            {
                if(seg[k].e<p[i])continue;
                if(seg[k].s>p[i])break;
                q.push(seg[k]);
            }
            for(j=i; j<m; j++)
            {
                if(i!=0)num[i][j]=num[i-1][j];
                while(!q.empty())
                {
                    ts=q.top();
                    if(ts.e>=p[j])break;
                    q.pop();
                }
                num[i][j]+=q.size();
                num[j][i]=num[i][j];
            }
        }
        printf("Case %d:\n", t);
        for(i=0; i<m; i++)
        {
            for(j=0; j<m-1; j++)
                printf("%d ", num[i][j]);
            printf("%d\n", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
