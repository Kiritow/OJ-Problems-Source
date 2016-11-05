#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod = 2147493647;
ll n,a,b;
struct Matrix
{
    ll m[7][7];
    void init1()
    {
        m[0][0] = b,m[0][1] = 0,m[0][2] = 0,m[0][3] = 0,m[0][4] = 0,m[0][5] = 0,m[0][6] = 0;
        m[1][0] = a,m[1][1] = 0,m[1][2] = 0,m[1][3] = 0,m[1][4] = 0,m[1][5] = 0,m[1][6] = 0;
        m[2][0] = 16,m[2][1] = 0,m[2][2] = 0,m[2][3] = 0,m[2][4] = 0,m[2][5] = 0,m[2][6] = 0;
        m[3][0] = 8,m[3][1] = 0,m[3][2] = 0,m[3][3] = 0,m[3][4] = 0,m[3][5] = 0,m[3][6] = 0;
        m[4][0] = 4,m[4][1] = 0,m[4][2] = 0,m[4][3] = 0,m[4][4] = 0,m[4][5] = 0,m[4][6] = 0;
        m[5][0] = 2,m[5][1] = 0,m[5][2] = 0,m[5][3] = 0,m[5][4] = 0,m[5][5] = 0,m[5][6] = 0;
        m[6][0] = 1,m[6][1] = 0,m[6][2] = 0,m[6][3] = 0,m[6][4] = 0,m[6][5] = 0,m[6][6] = 0;
    }
    void init2()
    {
        m[0][0] = 1,m[0][1] = 2,m[0][2] = 1,m[0][3] = 4,m[0][4] = 6,m[0][5] = 4,m[0][6] = 1;
        m[1][0] = 1,m[1][1] = 0,m[1][2] = 0,m[1][3] = 0,m[1][4] = 0,m[1][5] = 0,m[1][6] = 0;
        m[2][0] = 0,m[2][1] = 0,m[2][2] = 1,m[2][3] = 4,m[2][4] = 6,m[2][5] = 4,m[2][6] = 1;
        m[3][0] = 0,m[3][1] = 0,m[3][2] = 0,m[3][3] = 1,m[3][4] = 3,m[3][5] = 3,m[3][6] = 1;
        m[4][0] = 0,m[4][1] = 0,m[4][2] = 0,m[4][3] = 0,m[4][4] = 1,m[4][5] = 2,m[4][6] = 1;
        m[5][0] = 0,m[5][1] = 0,m[5][2] = 0,m[5][3] = 0,m[5][4] = 0,m[5][5] = 1,m[5][6] = 1;
        m[6][0] = 0,m[6][1] = 0,m[6][2] = 0,m[6][3] = 0,m[6][4] = 0,m[6][5] = 0,m[6][6] = 1;
    }
    Matrix operator * (Matrix t)
    {
        Matrix res;
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                res.m[i][j] = 0;
                for (int k = 0;k < 7; k++)
                    res.m[i][j] = (res.m[i][j] + (m[i][k] % mod) * (t.m[k][j] % mod) % mod) % mod;
            }
        }
        return res;
    }
    Matrix operator ^ (int k)
    {
        Matrix res,s;
        res.init2();
        s.init2();
        while(k)
        {
            if(k & 1)
                res = res * s;
            k >>= 1;
            s = s * s;
        }
        return res;
    }
};
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&a,&b);
        if(n == 1)
        {
            printf("%lld\n",a % mod);
            continue;
        }
        if(n == 2)
        {
            printf("%lld\n",b % mod);
            continue;
        }
        Matrix ans,t;
        ans.init1();
        t.init2();
        ans = (t^(n-3)) * ans;
        printf("%lld\n",ans.m[0][0]);
    }
    return 0;
}
