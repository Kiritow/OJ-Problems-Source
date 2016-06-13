#include<stdio.h>
#define N 600000
int main()
{
    int k,m,n;
    int s1,s2;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&m,&n);
        s1=0;
        s2=0;
        for(int i=1;i<m;i++)
        {
            if(m%i==0)
            s1+=i;
        }
        for(int j=1;j<n;j++)
        {
            if(n%j==0)
            s2+=j;
        }
        if((s1==n)&&(s2==m))
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
