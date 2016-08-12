#include<stdio.h>
#include<string.h>
#define MAX 10000
char a[MAX];
void count(int n)
{
    int tem,sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    if(sum<10)
    {
        printf("%d\n",sum);
    }
    else
    {
        count(sum);
    }
}
int main()
{
    int i,num,len;
    while(scanf("%s",a)&&a[0]!='0')
    {
        num=0;
        len=strlen(a);
        for(i=0;i<len;i++)
        {
            num+=(a[i]-'0');
        }
        count(num);
    }        
    return 0;
}
