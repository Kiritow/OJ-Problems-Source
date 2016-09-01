#include<stdio.h>
int main()
{
    int n0;
    int iCase=0;
    while(scanf("%d",&n0),n0)
    {
        iCase++;
        printf("%d. ",iCase);
        if(n0%2==0)
          printf("even %d\n",n0/2);
        else 
          printf("odd %d\n",(n0-1)/2);
    }    
    return 0;
}
