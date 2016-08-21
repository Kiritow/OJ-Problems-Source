#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int t,n,i,a[14],b[14],m,k;
    scanf("%d",&t);
    while (t--)
    {
        queue <int> q;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            q.push(i);
        for(i=0;i<n;i++)
        {
            k=i+1;
            while (k--)
            {
                m=q.front();
                q.pop();
                q.push(m);
            }
            a[i]=q.front();
            q.pop();
        }
        for(i=0;i<n;i++)
            b[a[i]]=i+1;
        for(i=0;i<n-1;i++)
            printf("%d ",b[i]);
        printf("%d\n",b[i]);
    }
}
