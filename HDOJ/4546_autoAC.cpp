#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
const int maxn = 10011;
struct Node
{
    int sum;
    int nex;
    int ith;
    Node(){}
    Node(int sum_, int nex_, int ith_){sum = sum_, nex = nex_, ith = ith_;}
    bool operator<(const Node &b)const
    {return b.nex < nex;}
};
int a[maxn];
int Cal(int m)
{
    priority_queue<Node> q;
    Node lin;
    lin.sum = 0, lin.nex = a[0], lin.ith = 0;
    q.push(lin);
    int cnt = 0;
    a[n] = 0;
    while(cnt < m)
    {
        lin = q.top(); q.pop();
        if(lin.ith >= n) continue;
        q.push(Node(lin.sum, lin.sum + a[lin.ith + 1], lin.ith + 1));
        q.push(Node(lin.nex, lin.nex + a[lin.ith + 1], lin.ith + 1));
        cnt += 1;
    }
    for(m = 0; !q.empty(); m ++) a[m] = q.top().sum, q.pop();
    sort(a, a + m);
    return a[m - 1];
}
int main()
{
    int i, t, ca;
    for(scanf("%d", &t), ca = 1; ca <= t; ca ++)
    {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        printf("Case #%d: %d\n", ca, Cal(m));
    }
    return 0;
}
