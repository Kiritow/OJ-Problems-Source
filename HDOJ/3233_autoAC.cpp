#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps = 1e-7;
struct node{
    node(){}
    node(double _size,double _rem):size(_size),rem(_rem){}
    double size,rem;
};
node Q[1005],data[20005];
bool cmp(node a,node b)
{
    if(fabs(a.size-b.size) < eps) return a.rem > b.rem;
    return a.size < b.size;
}
double solve(int n,int m,double b)
{
    int len = 0;
    double ans = 0;
    for(int i = 0;i < n;++i)
    {
        if(len < m)
        {
            double Size = data[i].size*(1-data[i].rem*0.01);
            if(fabs(Size) < eps) continue;
            Q[len++] = node(Size,0.0);
            for(int j = len-1;j > 0;--j)
            {
                if(Q[j].size < Q[j-1].size)
                swap(Q[j],Q[j-1]);
                else
                break;
            }
        }
        if(len == m)
        {
            double t = Q[0].size / (b / m),s = Q[0].size;
            ans += t;
            for(int j = 1;j < len;++j)
            {
                Q[j].size -= s;
                Q[j-1] = Q[j];
            }
            len--;
        }
    }
    for(int i = 0;i < len;++i)
    {
        double t = Q[i].size / (b / (len-i)),s = Q[i].size;
        ans += t;
        for(int j = i;j < len;++j)
        Q[j].size -= s;
    }
    return ans;
}
int main()
{
    int n,m,b,casenum = 1;
    while(scanf("%d%d%d",&n,&m,&b) && n+m+b)
    {
        for(int i = 0;i < n;++i)
        scanf("%lf%lf",&data[i].size,&data[i].rem);
        sort(data,data+n,cmp);
        printf("Case %d: %.2lf\n\n",casenum++,solve(n,m,(double)b));
    }
    return 0;
}
