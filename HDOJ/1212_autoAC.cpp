#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,t;
    char a[1010];
    while(scanf("%s%d",&a,&n)!=EOF)
    {
        t=0;
        for(i=0;i<strlen(a);i++)
        {
            t=t*10+a[i]-'0';
            t%=n;
        }
        printf("%d\n",t);
    }
    return 0;
}
