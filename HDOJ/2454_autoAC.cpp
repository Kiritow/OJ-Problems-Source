#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,i,j,a[1005],sum=0,flag=1;
        scanf("%d",&n);
        for (i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n,cmp);
        if (sum%2!=0)
        {
           flag=0;
        }
        else
        {
            while(a[0]>0)
            {
                for (j=1;j<=a[0];j++)
                    a[j]--;
                a[0]=0;
                sort(a,a+n,cmp);
            }
            sort(a,a+n);
            if (a[0]<0)
            {
                flag=0;
            }
        }
        if (flag!=0)
                printf("yes\n");
            else
                printf("no\n");
    }
    return 0;
}
