#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <algorithm>
using namespace std;

namespace LCIS_INT_LESSMEM
{
    const int MAXL=1024;
    int ldp[MAXL];
    int deal(int* pa,int na,int *pb,int nb)
    {
        memset(ldp,0,MAXL*sizeof(int));
        for(int i=1;i<=na;i++)
        {
            int k=0;
            for(int j=1;j<=nb;j++)
            {
                if(pa[i]>pb[j]) k=max(k,ldp[j]);
                else if(pa[i]==pb[j])
                {
                    ldp[j]=k+1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= nb; i++) ans = max(ans, ldp[i]);
        return ans;
    }
}

/// CSUOJ 1120
int a[1024];
int b[1024];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int na;
        scanf("%d",&na);
        for(int i=1;i<=na;i++)
        {
            scanf("%d",&a[i]);
        }
        int nb;
        scanf("%d",&nb);
        for(int i=1;i<=nb;i++)
        {
            scanf("%d",&b[i]);
        }
        printf("%d\n",LCIS_INT_LESSMEM::deal(a,na,b,nb));
    }
    return 0;
}
