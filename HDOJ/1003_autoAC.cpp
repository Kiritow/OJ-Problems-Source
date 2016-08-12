#include <stdio.h>
int data[100000];
int main()
{
    int i,j,k,l,sum,b,e,max=0,t;
    scanf("%d",&i);
    for (j=1;j<=i;j++)
    {
        max = -100000;
        scanf("%d",&k);
        for (sum=0, l=0, t=0 , e=0;l<k;l++)
        {
            scanf("%d",&data[l]);
            if (sum>=0)
            {
                sum+=data[l];
            }
            else
            {
                sum = data[l];
                t = l;
            }
            if (sum>max)
            {
                max = sum;
                b = t;
                e = l;
            }
        }
        printf("Case %d:\n",j);
        printf("%d %d %d\n",max,b+1,e+1);
        if (j != i)
            printf("\n");
    }
    return 1;
}
