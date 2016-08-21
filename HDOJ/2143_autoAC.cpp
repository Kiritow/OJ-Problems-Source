#include<stdio.h>
int main()
{
    _int64 a,b,c;
    int flag;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
    {
        flag=0;
        if(a+b==c||a+c==b||b+c==a||a*b==c||a*c==b||b*c==a)
            flag=1;
        else if((a&&(b%a==c||c%a==b))||(b&&(a%b==c||c%b==a))||(c&&(a%c==b||b%c==a)))
            flag=1;
        if(flag)
            puts("oh,lucky!");
        else
            puts("what a pity!");
    }
    return 0;
}
