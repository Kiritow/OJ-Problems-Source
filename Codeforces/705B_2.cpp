#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int tmp;
    int a0=0;
    int a1=0;
    int laststate=2;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&tmp);
        if(tmp==1)
        {
            printf("%d\n",laststate);
            continue;
        }
        if(tmp%2==0) a0++;
        else a1++;
        if(a1%2==1)
        {
            laststate=2-((a0+a1)%2==0);
            printf("%d\n",laststate);
        }
        else
        {
            laststate=2-((a0+a1)%2==1);
            printf("%d\n",laststate);
        }
    }

    return 0;
}
