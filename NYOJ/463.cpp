#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<9;j++)
            {
                printf("%d*%d=%d ",i,j,i*j);
            }
            printf("%d*9=%d\n",i,i*9);
        }
        printf("\n");
    }
    return 0;
}
