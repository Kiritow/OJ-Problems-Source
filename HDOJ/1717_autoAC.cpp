#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    char str[20];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int len = strlen(str);
        int i,j,a,b;
        int flag = 1;
        int ans1 = 0,ans2 = 0;
        int shi1 = 1,shi2 = 0;
        for(i = 2;i < len;i++)
        {
            if(str[i] == '(')
            {flag = 0;}
            if(str[i] >= '0'&&str[i] <= '9')
            {
                if(flag)
                {
                    shi1 = shi1*10;
                    ans1 = ans1*10+str[i]-'0';
                }
                else
                {
                    shi2 = shi2*10+9;
                    ans2 = ans2*10+str[i]-'0';
                }
            }
        }
        if(flag)
        {
            printf("%d/%d\n",ans1/gcd(ans1,shi1),shi1/gcd(ans1,shi1));
        }
        else
        {
            int cnt = gcd(ans2+shi2*ans1,shi2);
            a=(ans2+shi2*ans1)/cnt;
            b=shi2/cnt;
            int Cnt=gcd(a,b*shi1);
            printf("%d/%d\n",a/Cnt,b*shi1/Cnt);
        }
    }
    return 0;
}
