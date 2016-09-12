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
int main()
{
    int T;
    ll n,x,sum;
    cin>>T;
    while(T--)
    {
        cin>>n;
        sum = 0;
        int k=0,re=0;
        ll maxx = -INF;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x == 0) {re++; continue;}
            if(x < 0)
            {
                k++;
                maxx = max(maxx, x);
            }
            if(i == re) sum = x;
            else sum *= x;
        }
        if(k%2&&n!=1&&!(k==1&&re+k==n)) sum /= maxx;
        if(re>0&&(sum<0||n==1)) sum = 0;
        cout<<sum<<endl;
    }
    return 0;
}
