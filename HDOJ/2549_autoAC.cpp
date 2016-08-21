#include<stdio.h>
#include<string.h>
int main()
{
    char a[100005];
    int length_a,i,j,n,t,d;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d",&a,&t);
        length_a=strlen(a);
        for(i=0;a[i]!='.';i++)
        {
        }
        j=i+1;
        d=length_a-j;
        if(t>d)
            printf("0\n");
        else
            printf("%c\n",a[i+t]);
    }
    return 0;
}
