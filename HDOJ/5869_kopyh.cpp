//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 112345
using namespace std;
int n,m,sum,res,flag;
#define root 1 , n , 1
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
struct node
{
    int pos,val;
    node(int x=0,int y=0){pos=x,val=y;}
    friend bool operator < (node a, node b)
    {
        return a.val < b.val;
    }
    friend node operator + (node a, node b)
    {
        return  node(a.pos,a.val+b.val);
    }
}arr[N<<2];
int add[N<<2],tot;
void pushUp(int rt)
{
    arr[rt] = arr[rt<<1]+arr[rt<<1|1];
}
void pushDown(int l,int r,int rt)
{
    if(add[rt])
    {
        int m = (l+r)>>1;
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        arr[rt<<1].val += (m-l+1)*add[rt];
        arr[rt<<1|1].val += (r-m)*add[rt];
        add[rt] = 0;
    }
}
void updata(int l,int r,int rt,int ql,int qr,int val)
{
    if(l>qr||ql>r)return;
    if(l>=ql&&r<=qr)
    {
        arr[rt].val += (r-l+1)*val;
        add[rt] += val;
        return;
    }
    pushDown(l,r,rt);
    int m = (l+r)>>1;
    if(ql<=m)updata(lson,ql,qr,val);
    if(qr>m)updata(rson,ql,qr,val);
    pushUp(rt);
}
void build(int l,int r,int rt)
{
    add[rt]=0;
    if(l == r)
    {
        arr[rt].val = 0;
        arr[rt].pos = tot;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
node query(int l,int r,int rt,int ql,int qr)
{
    if(l>qr||ql>r)
        return node(0,0);
    if(l>=ql&&r<=qr)
        return arr[rt];
    pushDown(l,r,rt);
    int m = (l+r)>>1;
    return query(lson,ql,qr)+query(rson,ql,qr);
}
int a[N],pos[N*10],ans[N];
vector<pair<int,int> >vc[N],qu[N];
int gcd(int x,int y)
{   return y?gcd(y,x%y):x;  }
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    int i,j,k,cas,T,t,x,y,z,now;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            vc[i].clear();
            qu[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            x=a[i]; y=i;
            for(j=0;j<vc[i-1].size();j++)
            {
                t = gcd(vc[i-1][j].first,a[i]);
                if(t!=x)
                {
                    vc[i].push_back(make_pair(x,y));
                    x=t; y=vc[i-1][j].second;
                }
            }
            vc[i].push_back(make_pair(x,y));
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            qu[y].push_back(make_pair(x,i));
        }
        memset(pos,0,sizeof(pos));
        build(root);
        for(i=1;i<=n;i++)
        {
            for(j=0;j<vc[i].size();j++)
                if(pos[vc[i][j].first] < vc[i][j].second)
                {
                    if(pos[vc[i][j].first])updata(root,pos[vc[i][j].first],pos[vc[i][j].first],-1);
                    updata(root,vc[i][j].second,vc[i][j].second,1);
                    pos[vc[i][j].first] = vc[i][j].second;
//                    printf("pos=%d %d\n",vc[i][j].first,pos[vc[i][j].first]);
                }
            for(j=0;j<qu[i].size();j++)
                ans[qu[i][j].second] = query(root,qu[i][j].first,i).val;
        }
        for(i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
