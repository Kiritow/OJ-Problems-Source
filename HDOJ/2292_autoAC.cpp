#include <iostream>
using namespace std;
const int maxn=1005;
__int64 n,m;
__int64 cnt[maxn];
int c[maxn][maxn];
int son(int n)
{
    int t = 1;
    while (t <= n) t=t<<1|1;
    t = (t - 1) / 2;
    t = (t - 1) / 2;
    int sum = n - 1 - t;
    if (sum > 2 * t + 1)
    {
        sum = 2 * t + 1;
    }
    return sum;
}
void calc_c() {
    for (int i = 0; i < maxn; i++) 
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) 
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
        }
    }
}
__int64 slove(int n)
{
    if(cnt[n])
        return cnt[n];
    if(n==0||n==1)
        return 1;
    int left=son(n);
    int right=(n-1)-left;
    return cnt[n]=( (slove(left)*slove(right) )%m )*(__int64)c[n-1][left]%m;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%I64d%I64d",&n,&m);
        calc_c();
        __int64 ans=slove(n);
        printf("%I64d\n",ans);
    }
    return 0;
}
