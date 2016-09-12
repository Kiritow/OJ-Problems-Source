#include <iostream>
#include <cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
#include<queue>
typedef long long ll;
using namespace std;
int main()
{
    int T;
    int n,a;
    priority_queue<ll, vector<ll>, greater<ll> >q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        while(!q.empty())
        {
            q.pop();
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            q.push(a);
        }
        ll sum = 0;
        while(!q.empty())
        {
            ll x = q.top();
            q.pop();
            if(q.empty())
            {
                continue;
            }
            ll y = q.top();
            q.pop();
            ll tmp= x + y;
            sum+=tmp;
            q.push(tmp);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
