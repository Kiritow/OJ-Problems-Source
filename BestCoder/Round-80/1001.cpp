#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int tmp;
        bool haveone=false;
        bool havezero=false;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if(tmp==1) haveone=true;
            else if(tmp==0) havezero=true;
        }
        if(haveone&&havezero)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
