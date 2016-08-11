#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
long long num[1000000];
long long ans;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    long long n;
    int u;
    scanf ("%d",&u);
    while (u--)
    {
        scanf ("%lld",&n);
        ans = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            scanf ("%d",&num[i]);
            ans += num[i];
        }
        ans *= (n-1);
        sort(num+1,num+1+n,cmp);
        long long mul = 1;
        long long ant;		//二进制末尾为1的个数 
        while (num[1])
        {
            ant = 0;
            for (int i = 1 ; i <= n ; i++)
            {
                if (num[i] == 0)
                    break;
                if (num[i] & 1)
                    ant++;
                num[i] >>= 1;
            }
            ans += (((ant-1) * ant) >> 1) * mul;		//与运算 
            ans += ((n-ant) * ant + (((ant-1) * ant) >> 1)) * mul;		//或运算 
            ans += ((n-ant) * ant) * mul;		//异或运算 
            mul <<= 1;
        }
        printf ("%lld\n",ans);
    }
    return 0;
}
