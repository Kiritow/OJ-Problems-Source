#include"stdio.h"
#include"math.h"
int main()
{
    int i;
    int t;
    int n;
    int x;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        x=-1;
        t=(int)sqrt(n);
        for(i=t;i>0;i--)
        {
            if(n%i==0&&(n/i-i)%2==0&&(n/i-i)/2>0)
            {
                x=(n/i-i)/2;
                break;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
