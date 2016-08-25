#include<iostream>
#include<string.h>
using namespace std;
int a[150010]; 
int main()
{
    int p,i;
    while(scanf("%d",&p)!=EOF)
    {        
        memset(a,0,sizeof(a));
        for (i=1;i<=p;i++)
            scanf("%d",&a[i]);
        int s=0;
        int x=0;
        for (i=0;i<=p;i++)
        {
            if(x==0&&a[i]-a[i+1]<=0&&a[i+1]-a[i+2]>=0)
            {
                s=s+a[i+1];    
                x=1;
            }
            else
                if (x==1&&a[i]-a[i+1]>=0&&a[i+1]-a[i+2]<=0)
                {
                    s-=a[i+1];
                    x=0;
                }
        }
        printf("%d\n",s);
    }
    return 0;
}
