#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,tmp,sum;
        scanf("%d",&n);
        sum=n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            sum+=tmp;
        }
        printf("%d\n",sum);
    }
    return 0;
}
