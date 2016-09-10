#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
ll a[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;++i)
            scanf("%I64d",&a[i]);
        if(n > 40)
        {
            puts("Yes");
            continue;
        }
        int x = 0;
        for(ll i = 0;i < 40;++i)
        {
            int p = -1;
            for(ll j = x;j < n;++j)
            {
                if((a[j]>>i) & 1)
                {
                    p = j;
                    break;
                }
            }
            if(p == -1) continue;
            swap(a[x],a[p]);
            for(int j = x + 1;j < n;++j)
                if((a[j]>>i) & 1)
                    a[j] ^= a[x];
            x++;
        }
        int cnt = 0;
        for(int i = 0;i < n;++i)
            if(a[i]) cnt++;
        if(cnt < n)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
