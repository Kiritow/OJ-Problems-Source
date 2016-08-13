#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l,n,m,t;
    int a[1002],b[1002] = {0};
    while (scanf("%d",&n)!=EOF && n)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(b,0,sizeof(b));
        int sum = 0;
        k=0;
        int maxnum = -1;
        for (i=0;i<n;i++)
        {
            b[i] = a[i];
            int maxb = 0;
            for (j=0;j<i;j++)    
            {
                if (a[i] > a[j])
                {
                    if (b[j] > maxb)
                    {
                        maxb = b[j];
                    }
                }
            }
            b[i] += maxb;
            if (b[i] > maxnum)
            {
                maxnum = b[i];
            }
        }
        printf("%d\n",maxnum);
    }
    return 0;
}
