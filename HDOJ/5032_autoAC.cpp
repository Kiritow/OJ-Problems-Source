#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
ll bit[1010];
void update(int pos,ll val)
{
    for(int i=pos;i<=1000;i+=i&-i)
        bit[i]+=val;
}
ll psum(int pos)
{
    ll ans=0;
    for(int i=pos;i>0;i-=i&-i)
        ans+=bit[i];
    return ans;
}
struct Point
{
    int x,y;
    bool operator <(Point one)const
    {
        return y*one.x<=one.y*x;
    }
}point[1000010];
struct Qu
{
    int x,y,len,no;
    bool operator <(Qu one)const
    {
        return ll(y*one.x)<ll(one.y*x);
    }
}qu[1000010];
ll ans[1000010];
int main()
{
    int n=0;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
        {
            point[n].x=i;
            point[n++].y=j;
        }
    sort(point,point+n);
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        int a,b,m;
        scanf("%d%d%d",&a,&b,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&qu[i].x,&qu[i].y,&qu[i].len);
            qu[i].no=i;
        }
        sort(qu,qu+m);
        memset(bit,0,sizeof(bit));
        for(int i=0,j=0;i<m;i++)
        {
            Point t;
            t.x=qu[i].x;
            t.y=qu[i].y;
            while(j<n&&point[j]<t)
            {
                update(point[j].x,ll(point[j].x+a)*(point[j].y+b));
                j++;
            }
            ans[qu[i].no]=psum(qu[i].len);
        }
        printf("Case #%d:\n",cs);
        for(int i=0;i<m;i++)
            cout<<ans[i]<<endl;
    }
}
