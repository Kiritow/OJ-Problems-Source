#include <stdio.h>
int main()
{
    int i,c,s,m,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        s = 0;
        for(i=0;i<m*n;i++)
        {
            scanf("%d",&c);
            if(c) s += c;
        }
        printf("%d\n",s);
    }
    return 0;
}
