#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        break;
        if((n*m)%2==0)
        printf("Wonderful!\n");
        else
        printf("What a pity!\n");        
    }    
}
