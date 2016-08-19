#include<stdio.h>
#include<string.h>
int main()
{
    char a[10000],b[10000];
    int i,j,k1,k2,t,count;
    while(scanf("%s",a)!=EOF)
    {    t=0;count=0;
        if(a[0]=='#')
            break;
        scanf("%s",b);
        k1=strlen(a);
        k2=strlen(b);
        for(i=0,j=0;i<k1;i++)
        {
            if(a[i]==b[j])
            {t++;}
            else
            {t=0;}
            if(t==k2)
            {count++;t=0;}
            j++;
            if(j==k2)
            {j=0;}
        }
        printf("%d\n",count);
    }
    return 0;
}
