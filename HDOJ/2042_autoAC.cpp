#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,f[1000]={4},a;
    scanf("%d",&n);
    while(n--)
    {
        memset(f,0,sizeof(f));
        f[0]=4;
        scanf("%d",&a);
        if(a==1)
            printf("4\n");
        else
        {
            for(i=1;i<a;i++)
            {
                f[i]=(f[i-1]-1)*2;
            }
            printf("%d\n",f[a-1]);
        }
    }
    return 0;
}
