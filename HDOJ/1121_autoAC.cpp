#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int a[1000];
        int b[1000];
        int c[1000];
        for(int i=0;i<x;i++)
        {
            scanf("%d",&a[i]);
        }
        int num;
        int flag=0;
        int w=x;
        int f1=0;
        for(num=0;;num++)
        {
            int k=0;
            b[f1++]=a[w-1];
            if(flag==1)
                break;
            for(int i=0;i<w-1;i++)
            {
                if(a[i]==a[i+1])
                {
                    k++;
                }
            }
            if(k==w-1)
                flag=1;
            if(flag==0)
            {
                for(int i=0;i<w-1;i++)
                    a[i]=a[i+1]-a[i];
            }        
            w--;
        }
        for(int i=0;i<y;i++)
        {
            c[i]=b[num-1];
        }
        for(int i=num-2;i>=0;i--)
        {
            c[0]+=b[i];
            for(int j=1;j<y;j++)
                c[j]+=c[j-1];
        }
        int ff=0;
        for(int i=0;i<y;i++)
            ff==0?printf("%d",c[i]):printf(" %d",c[i]),ff=1;
        printf("\n");
    }
    return 0;
}
