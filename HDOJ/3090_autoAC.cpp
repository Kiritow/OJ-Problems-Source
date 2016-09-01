#include <cstdio>
#include <algorithm>
using namespace std;
struct Node
{
    int d,p;
};
Node roads[10001];
int n,m;
int sum;
bool cmp(Node n1,Node n2)
{
    return n1.p > n2.p;
}
int main()
{
    while(scanf("%d %d", &n, &m), m!=0 || n!=0)
    {
        sum = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &roads[i].d, &roads[i].p);
            sum += roads[i].d*roads[i].p;
        }
        sort(roads, roads+n, cmp);
        for(int i=0; i<n; i++)
        {
            if(m > roads[i].d)
            {
                m -= roads[i].d;
                sum -= roads[i].d * roads[i].p;
            }
            else
            {
                sum -= m * roads[i].p;
                break;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
