#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 105;
const int forever = -1;
const int never = -2;
struct point
{
    ll x, y;
} p[maxn], v[maxn];
map <ll, ll> Map;
ll cti[maxn][maxn];
void initial(int n)
{
    int i, j, t;
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if(p[i].x==p[j].x && p[i].y==p[j].y && v[i].x==v[j].x && v[i].y==v[j].y)
                cti[i][j]=cti[j][i]=forever;
            else
            {
                cti[i][j]=cti[j][i]=never;
                if(v[i].x != v[j].x)
                {
                    if((p[i].x-p[j].x)%(v[j].x-v[i].x) != 0)continue;
                    t=(p[i].x-p[j].x)/(v[j].x-v[i].x);
                    if(t<0 || (p[i].y+v[i].y*t != p[j].y+v[j].y*t))continue;
                }
                else if(v[i].y != v[j].y)
                {
                    if((p[i].y-p[j].y)%(v[j].y-v[i].y) != 0)continue;
                    t=(p[i].y-p[j].y)/(v[j].y-v[i].y);
                    if(t<0 || (p[i].x+v[i].x*t != p[j].x+v[j].x*t))continue;
                }
                else continue;
                cti[i][j]=cti[j][i]=t;
            }
        }
}
int main()
{
    int i, j, k, n, tmp, cnt, res, ans;
    ll a, b, c, t;
    while(~scanf("%d", &n) && n)
    {
        for(i = 0; i < n; i++)scanf("%I64d%I64d%I64d%I64d", &p[i].x, &p[i].y, &v[i].x, &v[i].y);
        if(n == 1 || n == 2)
        {
            printf("%d\n", n);
            continue;
        }
        initial(n);
        ans = 0;
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++)
            {
                Map.clear();
                cnt = 0;
                res = 0;
                for(k = 0; k < n; k++)
                {
                    if(k==i || k==j)continue;
                    a = (v[i].x-v[j].x)*(v[i].y-v[k].y) - (v[i].x-v[k].x)*(v[i].y-v[j].y);
                    b = (p[i].x-p[j].x)*(v[i].y-v[k].y) + (v[i].x-v[j].x)*(p[i].y-p[k].y)
                        - (p[i].y-p[j].y)*(v[i].x-v[k].x) - (v[i].y-v[j].y)*(p[i].x-p[k].x);
                    c = (p[i].x-p[j].x)*(p[i].y-p[k].y) - (p[i].y-p[j].y)*(p[i].x-p[k].x);
                    if(a==0 && b==0 && c==0)cnt++;
                    else if(a==0)
                    {
                        if(c==0 || b==0)continue;
                        else if(c%b==0)
                        {
                            t=-c/b;
                            if(t>0 && t!=cti[i][j])
                            {
                                tmp = ++Map[t];
                                res = max(tmp, res);
                            }
                        }
                    }
                    else
                    {
                        ll d = b*b-4*a*c;
                        ll t1, t2;
                        if(d<0) continue;
                        else
                        {
                            ll sqd = sqrt(d+0.0);
                            if(sqd*sqd == d)
                            {
                                t1= -b+sqd;
                                if(t1%(2*a)==0)
                                {
                                    t1/=(2*a);
                                    if(t1>0 && t1!=cti[i][j])
                                    {
                                        tmp = ++Map[t1];
                                        res = max(tmp, res);
                                    }
                                }
                                if(sqd!=0)
                                {
                                    t2= -b-sqd;
                                    if(t2%(2*a)==0)
                                    {
                                        t2/=(2*a);
                                        if(t2>0 && t2!=cti[i][j])
                                        {
                                            tmp = ++Map[t2];
                                            res = max(tmp, res);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                ans = max(res+2+cnt, ans);
                if(cti[i][j]!=never && cti[i][j]!=0)
                {
                    res=0;
                    for(k=0; k<n; k++)
                    {
                        if(k==i || k==j)continue;
                        if(cti[i][j] == cti[i][k])res++;
                    }
                    ans=max(res+2, ans);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
