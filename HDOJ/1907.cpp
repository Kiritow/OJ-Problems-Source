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
        int ans=0;
        int tmp;
        //ans--;
        bool have_over_one=false;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&tmp);
            if(tmp>1)
            {
                have_over_one=true;
            }
            ans=ans^tmp;
        }
        #if 0
        printf("%d\n",ans);
        #endif // 0
        if(!have_over_one)
        {
            if(n%2==0)
            {
                printf("John\n");
            }
            else
            {
                printf("Brother\n");
            }
        }
        else
        {
            if(ans==0)
            {
                printf("Brother\n");
            }
            else
            {
                printf("John\n");
            }
        }
    }
    return 0;
}
