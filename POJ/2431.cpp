#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define MAX_N 10000

int L,P,N;

pair<int,int> X[MAX_N+1];

struct _A
{
public:
    int& operator [] (int x)
    {
        return X[x].first;
    }
}A;

struct B
{
public:
    int& operator [] (int x)
    {
        return X[x].second;
    }
}B;

void solve()
{
    A[N]=L;
    B[N]=0;
    N++;

    priority_queue<int> bus;

    int ans=0,pos=0,tank=P;

    for(int i=0;i<N;i++)
    {
        int d=A[i]-pos;

        while(tank-d<0)
        {
            if(bus.empty())
            {
                printf("-1\n");
                return;
            }

            tank+=bus.top();
            bus.pop();

            ++ans;
        }

        tank-=d;
        pos=A[i];
        bus.push(B[i]);
    }

    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&A[i],&B[i]);
    }
    scanf("%d %d",&L,&P);

    for(int i=0;i<N;i++)
    {
        A[i]=L-A[i];
    }

    sort(X,X+N);

    solve();
}

/*

int main()
{
    int n;
    scanf("%d",&n);
    vector< pair<int,int> > vec;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        vec.push_back(make_pair(a,b));
    }
    int L,P;
    scanf("%d %d",&L,&P);
    priority_queue<int> bus;
    int cnt=0;
    int now=0;
    int fuel=P;
    for(int i=0;i<n;i++)
    {
        int nextLength=L-vec[i].first-now;
        while(fuel-nextLength<0)
        {
            if(bus.empty())
            {
                /// Can not reach
                printf("-1\n");
                return 0;
            }

            fuel+=bus.top();
            bus.pop();
            ++cnt;
        }

        fuel=fuel-nextLength;
        now=L-vec[i].first;
        bus.push(vec[i].second);
    }

    printf("%d\n",cnt);
    return 0;
}

//*/
