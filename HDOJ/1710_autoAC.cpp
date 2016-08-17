#include <iostream>
using namespace std;
const int N=1005;
int pre[N],in[N],post[N];
int n;
void getpost(int pa,int pb,int ia,int ib,int la,int lb)
{
    if(pa>pb||ia>ib||la>lb) return;
    int a,b,i;
    for (i=ia;i<=ib;i++)
    {
        if (in[i]==pre[pa])
        {
            break;
        }
    }
    a=i-ia;b=ib-i;
    post[lb]=in[i];
    getpost(pa+1,pa+a,ia,i-1,la,la+a-1);
    getpost(pb-b+1,pb,i+1,ib,lb-b,lb-1);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&pre[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&in[i]);
        getpost(1,n,1,n,1,n);
        for (int i=1;i<n;i++)
            printf("%d ",post[i]);
        printf("%d\n",post[n]);
    }
    return 0;
}
