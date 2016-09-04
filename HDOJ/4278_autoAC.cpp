#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n;
    char num[15];
    while(scanf("%s",num))
    {
        if(num[0]=='0')
            break;
        int l=strlen(num);
        int i;
        int sum=0;
        for(i=0;i<l;i++)
        {
            if(num[i]<'3')
                sum+=(int)(num[i]-'0')*pow(8.0,l*1.0-i-1);
            else if(num[i]<'8')
                sum+=(int)(num[i]-'0'-1)*pow(8.0,l*1.0-i-1);
            else
                sum+=(int)(num[i]-'0'-2)*pow(8.0,l*1.0-i-1);
        }
        printf("%s: %d\n",num,sum);
    }
}
