#include <stdio.h>
#include <string.h>
char str[100];
long long gcd(long long x,long long y)
{
    return y==0?x:gcd(y,x%y);
}
long long Ex_Euclid(long long a,long long b,long long &x,long long &y)
{
    long long ans,t;
    if (b==0)
    {
        x=1;
        y=0;
        ans=0;
        return ans;
    }
    ans=Ex_Euclid(b,a%b,x,y);
    t=x;
    x=y;
    y=t-(a/b)*y;
    return ans;
}
int main()
{
    int i,j,n;
    long long A,B,C,D,x,y,k,t;
    while(scanf("%s",str)!=EOF)
    {
        A=0;
        for (i=0;i<strlen(str)-1;i++)
        {
            A=A*10+str[i]-'0';
        }
        scanf("%s",str);
        scanf("%s",str);
        B=0;
        for (i=0;i<strlen(str)-1;i++)
        {
            B=B*10+str[i]-'0';
        }
        scanf("%s",str);
        scanf("%s",str);
        C=0;
        for (i=0;i<strlen(str);i++)
        {
            C=C*10+str[i]-'0';
        }
        if (A==0) A=1;
        if (B==0) B=1;
        D=gcd(A,B);
        if (C%D!=0)
        {
            printf("No.\n\n");
            continue;
        }
        n=Ex_Euclid(A,B,x,y);
        x=x*C/D;
        t=B/D;
        x=(x%t+t)%t;
        k=(C-A*x)/B;
        if (k>=0)
        {
            printf("Yes.\n\n");
            continue;
        }
        y=y*C/D;
        t=A/D;
        y=(y%t+t)%t;
        k=(C-B*y)/A;
        if (k>=0)
        {
            printf("Yes.\n\n");
            continue;
        }
        printf("No.\n\n");
    }
    return 0;
}
