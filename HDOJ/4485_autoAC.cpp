#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int p,a,b;
char s[10000000+1];
int main()
{
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d%d%s",&a,&b,s);
        int j=0;
        int ans=0;
        int l=strlen(s)-1;
        for(int i=l;i>=0;i--)
        {
            ans+=(s[i]-'0')%(b-1);
            ans%=b-1;
        }
        printf("%d %d\n",a,ans);
    }
    return 0;
}
