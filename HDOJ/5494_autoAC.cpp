#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))
int main ()
{
    int T,n,m;
    int a[1111],b[1111];
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=0; i<n; i++)
            cin>>a[i];
        for (int i=0; i<n; i++)
            cin>>b[i];
        sort(a, a+n);
        sort(b, b+n);
        int suma=0,sumb=0;
        for (int i=1; i<=m; i++)
        {
            suma+=a[i-1];
            sumb+=b[n-i];
        }
        if (suma>sumb)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
