#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
const int N=100011;
int n,m,ans[N];
struct node0
{
    int cost,index;
}E[N];
struct node
{
    int index,load;
    bool friend operator<(node n1,node n2)
    {
        return n2.load<n1.load;
    }
};
int cmp(const void *a,const void *b)
{
    node0 *c,*d;
    c=(node0 *)a;
    d=(node0 *)b;
    return d->cost-c->cost;
}
void solve()
{
    int i;
    priority_queue<node>q;
    node now;
    qsort(E,n,sizeof(E[0]),cmp);
    for(i=0;i<m;i++)    {now.index=i;now.load=0;q.push(now);}
    for(i=0;i<n;i++)
    {
        now=q.top();
        q.pop();
        now.load+=E[i].cost;
        ans[E[i].index]=now.index;
        q.push(now);
    }
    cout<<n<<endl;
    cout<<ans[0];
    for(i=1;i<n;i++)    cout<<" "<<ans[i];
    cout<<endl;
}
int main()
{
    int T;
    int i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)    {scanf("%d",&E[i].cost);E[i].index=i;}
        solve();
    }
    return 0;
}
