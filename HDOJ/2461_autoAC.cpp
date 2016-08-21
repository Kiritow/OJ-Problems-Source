#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct Rectangle { int x1, y1, x2, y2;};
Rectangle rec[30];
int a[30], cnt;
int s[1100000];
int n, m;
Rectangle Intersection ( Rectangle r1, Rectangle r2 )
{
    Rectangle ret;
    if ( r1.x2 <= r2.x1 || r2.x2 <= r1.x1 || r1.y2 <= r2.y1 || r2.y2 <= r1.y1 )
    {
        ret.x1 = ret.y1 = ret.y1 = ret.y2 = 0;
        return ret;
    }
    ret.x1 = max ( r1.x1, r2.x1 );
    ret.y1 = max ( r1.y1, r2.y1 );
    ret.x2 = min ( r1.x2, r2.x2 );
    ret.y2 = min ( r1.y2, r2.y2 );
    return ret;
}
int Area ( Rectangle r )
{
    if ( r.x1 >= r.x2 || r.y1 >= r.y2 )
        return 0;
    return (r.y2-r.y1) * (r.x2-r.x1);
}
int In_Exclusion ( int k, Rectangle r )
{
    if ( Area(r) == 0 ) return 0;
    int ret = 0;
    Rectangle tmp;
    for ( int i = k; i < cnt; i++ )
    {
        tmp = Intersection(r,rec[a[i]]);
        ret += Area(tmp) - In_Exclusion ( i + 1, tmp );
    }
    return ret;
}
int main()
{
    int t = 0;
    Rectangle total;
    total.x1 = total.y1 = 0;
    total.x2 = total.y2 = 1000;
    while (scanf("%d%d",&n,&m) && (m||n))
    {
        int i, R, id, add;
        for ( i = 1; i <= n; i++ )
            scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
        printf("Case %d:\n",++t);
        memset(s,0,sizeof(s));
        for ( i = 1; i <= m; i++ )
        {
            scanf("%d",&R);
            cnt = add = 0;
            while ( R-- )
            {
                scanf("%d",&id);
                if ( add & (1<<(id-1)) ) continue;
                add = (add | (1<<(id-1)));
                a[cnt++] = id;
            }
            if ( s[add] == 0 )
                s[add] = In_Exclusion (0,total);
            printf("Query %d: %d\n",i,s[add]);
        }
        printf("\n");
    }
    return 0;
}
