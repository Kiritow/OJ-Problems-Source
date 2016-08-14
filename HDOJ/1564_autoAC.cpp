#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    if(i!=0)
    {
        while(i!=0)
        {
            if(i%2==0)
                printf("8600\n");
            else
                printf("ailyanlu\n");
            scanf("%d",&i);    
        }        
    }
    return 0;
}
