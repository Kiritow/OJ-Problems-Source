#include<stdio.h>
#include<string.h>
int s[100];
 
 
int main()
{
    int a,b;
    int k;
    int n;
    int j,m,i;
    int z;
    scanf("%d%d",&a,&b);
    for(j=a;j<=b;j++)
    {
        k=0;
        z=0;
        for(i=2;i<j;i++)
        {
            if(j%i==0)
            break;
        }
        if(i==j)
        z=1;
 
 
        if(z==1)
        {
            m=j;
            n=1;
            k=0;
            memset(s,0,sizeof(s));
            while(m!=0)
            {
                s[n]=m%10;
                m/=10;
                n++;
            }
            for(i=1;i<n;i++)
            {
                if(s[i]!=s[n-i])
                    break;
            }
            if(i==n)
            {
                k=1;
            }
            else
            {
                k=0;
            }
        }
        if (k == 1)
            printf("%d\n",j);
 
    }
    return 0;
}
 
