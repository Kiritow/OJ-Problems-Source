#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20];
int main()
{
    int k,i,j,l,m,n,q,t=0;
    while (scanf("%d",&k)!=EOF&&k)
    {
        if (t!=0)
        printf ("\n");
        t++;
        for (i=0;i<k;i++)
        {
            scanf("%d",&a[i]);
        }
        sort (a,a+k);
        for (i=0;i<k-5&&a[i+1];i++)
        {
            for (j=i+1;j<k-4&&a[j+1];j++)
            {
                for (l=j+1;l<k-3&&a[l+1];l++)
                {
                    for (m=l+1;m<k-2&&a[m+1];m++)
                    {
                        for (n=m+1;n<k-1&&a[n+1];n++)
                        {
                            for (q=n+1;q<k;q++)
                            {
                                printf ("%d %d %d %d %d %d\n",a[i],a[j],a[l],a[m],a[n],a[q]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
