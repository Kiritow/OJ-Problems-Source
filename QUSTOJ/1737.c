#include <stdio.h>
//Written by Kiritow. 求最大公约数
long gcd(long a,long b)
{
    if(a==0||b==0)
    {
        if(a+b==0)
        {
            return 0;
        }
        return (a==0)?b:a;
    }
 
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
int main()
{
    int a,b,c,d;
    char op;
    scanf("%d/%d%c%d/%d",&a,&b,&op,&c,&d);
    int x,y;
    switch(op)
    {
    case '+':
        x=a*d+b*c;
        y=b*d;
        break;
    case '-':
        x=a*d-b*c;
        y=b*d;
        break;
    case '*':
        x=a*c;
        y=b*d;
        break;
    case '/':
        x=a*d;
        y=b*c;
        break;
    }
    int ret;
    while((ret=gcd(x,y))!=1)
    {
        x/=ret;
        y/=ret;
    }
    //*/
    int mx=x>y?x:y;
    printf("%d/%d%c%d/%d=%d/%d\n",a,b,op,c,d,x,y);
    return 0;
}
