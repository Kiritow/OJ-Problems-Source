#include <stdio.h>
int a[100000];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int thissum=0;
        int maxsum=a[0];
        int stop=a[0];
        int temp=a[0];
        int start=a[0];
        for(int i=0;i<n;i++)
        {
            thissum+=a[i];
            if(thissum>maxsum)
            {
                maxsum=thissum;
                start=temp;
                stop=a[i];
            }
            if(thissum<0)
            {
                thissum=0;
                temp=a[i+1];
            }
        }
        if(maxsum<0)
            printf("0 %d %d\n",a[0],a[n-1]);
        else
            printf("%d %d %d\n",maxsum,start,stop);
    }
    return 0;
}
