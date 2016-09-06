#include<cstdio>
#include<algorithm>
using namespace std;
const int N =102;
const int mod = 1000000007;
int h;
struct matrix
{
    int row,col;
    int m[N][N];
    void init(int row,int col)
    {
        this->row = row;
        this->col = col;
        for(int i=0; i<=row; ++i)
            for(int j=0; j<=col; ++j)
                m[i][j] = 0;
    }
} A,pm[33],ans;
matrix operator*(const matrix & a,const matrix& b)
{
    matrix res;
    res.init(a.row,b.col);
    for(int k=1; k<=a.col; ++k)
    {
        for(int i=1; i<= res.row; ++i)
        {
            if(a.m[i][k] == 0 ) continue;
            for(int j = 1; j<=res.col; ++j)
            {
                if(b.m[k][j] == 0 ) continue;
                res.m[i][j] = (1LL *a.m[i][k]*b.m[k][j] + res.m[i][j])%mod;
            }
        }
    }
    return res;
}
void cal(int x)
{
    for(int i=0; i<=31; ++i)
        if(x & (1<<i) ) ans = pm[i]*ans;
}
void getPm()
{
    pm[0] = A;
    for(int i=1; i<=31; ++i)
        pm[i] = pm[i-1]*pm[i-1];
}
struct sp
{
    int nk,tk;
    int ck[N];
    bool operator<(const sp & o)const
    {
        return nk<o.nk;
    }
} p[N];
int main()
{
    int n,m,q,t,f[N],c[N],kase=0;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        for(int i=m; i>0; --i)   scanf("%d",&f[i]);
        scanf("%d",&t);
        h =t;
        for(int i=1; i<=t; ++i)  scanf("%d",&c[i]);
        for(int i=0; i<q; ++i)
        {
            scanf("%d%d",&p[i].nk,&p[i].tk);
            if(p[i].tk > h) h = p[i].tk;
            for(int j=1; j<=p[i].tk; ++j) scanf("%d",&p[i].ck[j]);
        }
        sort(p,p+q);
        A.init(h,h);
        for(int i=1; i<=t; ++i) A.m[1][i] = c[i];
        for(int i=2; i<=h; ++i)  A.m[i][i-1] = 1;
        getPm();
        ans.init(h,1);
        for(int i = m; i > 0; --i)   ans.m[i][1] = f[i];
        int last=m;
        for(int i=0; i<q; ++i)
        {
            if( p[i].nk <=last ||  p[i].nk >n ) continue;
            cal( p[i].nk-last-1);
            last =  p[i].nk;
            for(int j=1; j<=p[i].tk; ++j)  A.m[1][j] = p[i].ck[j];
            for(int j=p[i].tk+1; j<=h; ++j) A.m[1][j] = 0;
            ans  =A*ans;
        }
        cal(n-last);
        printf("Case %d: %d\n",++kase,ans.m[1][1]);
    }
    return 0;
}
