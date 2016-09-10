#include <stdio.h>
int main()
{
    int n,m,i,j;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0,j=-1;i<m;i++)
        {
            j+=1;
            j%=n;
        }
        printf("%d\n",j);
    }
    return 1;
}
