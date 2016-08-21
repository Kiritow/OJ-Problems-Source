#include<stdio.h>
int main()
{
    int C;
    scanf("%d",&C);
    while(C--)
    {
        int n,k=0;
        scanf("%d",&n);
        while(n!=0)
        {
            while(n%2==0)
            {
                n=n/2;    
            }
            while(n%2!=0)
            {
                n--;
                k++;    
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
