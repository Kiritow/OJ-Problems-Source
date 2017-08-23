#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MAXN 20000

int N;
int L[MAXN+1];

void solve()
{
    priority_queue< int,vector<int>,greater<int> > bus;
    for(int i=0;i<N;i++)
    {
        bus.push(L[i]);
    }
    ll ans=0;

    while(bus.size()>1)
    {
        int A=bus.top();
        bus.pop();
        int B=bus.top();
        bus.pop();

        int C=A+B;
        ans+=C;

        bus.push(C);
    }

    printf("%I64d\n",ans);
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&L[i]);
    }
    solve();
}
