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
        int n;
        scanf("%d",&n);

        int cnt=0;
        int x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x%2==1) ++cnt;
        }

        if(cnt>=n-cnt)
        {
            printf("2 1\n");
        }
        else
        {
            printf("2 0\n");
        }
    }
    return 0;
}
