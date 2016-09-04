#include<stdio.h>
int main()
{
    int T;
    int m,k;
    int iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d%d",&m,&k);
        printf("Case #%d: %.8lf\n",iCase,(double)1/(k+m*k+1));
    }    
    return 0;
}
