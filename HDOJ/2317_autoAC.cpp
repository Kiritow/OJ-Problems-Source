#include <stdio.h>
int main()
{
    int a,r,e,c,sum,s;
    scanf("%d",&a);
    while(a--)
    {
        s=0; sum=0; 
        scanf("%d%d%d",&r,&e,&c);
        s=e-c;
        if(s>r) printf("advertise\n");
        else if(s==r) printf("does not matter\n");
        else if(s<r) printf("do not advertise\n");
    }
}
