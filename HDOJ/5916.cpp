#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int cc=1;cc<=t;cc++)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        if(n==2)
        {
            printf("Case #%d: 1 2\n",cc);
            continue;
        }
        if(n==3)
        {
            printf("Case #%d: 1 2 3\n",cc);
            continue;
        }

        printf("Case #%d: ",cc);
        printf("%d",2*k);
        for(int p=k;p>=1;--p) printf(" %d",p);
        for(int p=k+1;p<=2*k-1;++p) printf(" %d",p);
        for(int p=2*k+1;p<=n;++p) printf(" %d",p);
        printf("\n");
    }
    return 0;
}
