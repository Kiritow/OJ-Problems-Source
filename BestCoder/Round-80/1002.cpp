#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
long long q_mul( long long a, long long b, long long mod ) //快速计算 (a*b) % mod
{
    long long ans = 0;  // 初始化
    while(b)                //根据b的每一位看加不加当前a
    {
        if(b & 1)           //如果当前位为1
        {
            b--;
            ans =(ans+ a)%mod;   //ans+=a
        }
        b /= 2;                         //b向前移位
        a = (a + a) % mod;          //更新a

    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long q,p;
        scanf("%I64d %I64d",&q,&p);
        long long a=q-1;
        long long b=q-2;
        long long ans;
        if(a%2==0)
        {
            ans=q_mul(a/2,b,p);
        }
        else
        {
            ans=q_mul(a,b/2,p);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
