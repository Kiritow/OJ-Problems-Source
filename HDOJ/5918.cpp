#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 100000
int a[MAXN];
int b[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;cc++)
    {
        int n,m,p;
        scanf("%d %d %d",&n,&m,&p);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        int qmax=n-(m-1)*p;
        int c=0;
        for(int q=1;q<=qmax;q++)
        {
            bool isok=true;
            for(int j=0;j<m;j++)
            {
                if(a[q+j*p-1]!=b[j])
                {
                    isok=false;
                    break;
                }
            }
            if(isok) ++c;
        }
        printf("Case #%d: %d\n",cc,c);
    }
    return 0;
}
