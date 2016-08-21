#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
struct N
{
    int x,p,m;
   bool operator<(const N &a) const 
    {
        return p<a.p;
    }
}node[maxn];
int main()
{
    int i,n;
    int t;
    scanf("%d",&t);
    priority_queue<N> q;
    N a;
    while(t--)
    {
        while(!q.empty()) q.pop();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&node[i].x,&node[i].p,&node[i].m);
        }
           int p=0,sum=0;
            for(i=n-1;i>=0;i--)
            {
                q.push(node[i]);
                sum=node[i].x;
                while(!q.empty()&&sum!=0)
                {
                    a=q.top();
                    q.pop();
                    if(a.m>=sum)
                    {
                        a.m-=sum;
                        p+=a.p*sum;
                        sum=0;
                    }
                    else
                    {
                        sum-=a.m;
                        p+=a.p*a.m;
                        a.m=0;
                    }
                    if(a.m!=0)
                        q.push(a);
                }
                if(q.empty())
                    sum=0;
            }
            printf("%d\n",p);
        }
    return 0;
}
