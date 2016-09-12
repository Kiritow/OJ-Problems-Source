#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 2000001
#define mod 10007
#define eps 1e-5
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int t=read();
    while(t--){
        ll n=read();
        int ans=0;
        int flag=1;
        while(n)
        {
            if(flag)
            {
                if(n&1)
                {
                    ans++;
                    flag=0;
                }
            }
            else if(!(n&1))
            {
                flag=1;
            }
            n>>=1;
        }
        cout<<ans<<endl;
    }
}
