#include<stdio.h>
#include<string.h>
int main()
{
    int a[10000],i,n,sum,len;
    char s[1000];
    a['I']=1;a['V']=5;a['X']=10;a['L']=50;a['C']=100;a['D']=500;a['M']=1000;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(s);
        len=strlen(s);
        sum=0;
        for(i=0;i<=len-2;i++)
        {
            if(a[s[i]]>=a[s[i+1]])
                sum=sum+a[s[i]];
            else
                sum=sum-a[s[i]];
        }
        sum=sum+a[s[len-1]];
        printf("%d\n",sum);
    }
    return 0;
}
