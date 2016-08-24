#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int aa[100000];
void convert(int a,int b)
{
    char s[16];
    int i=0;
    for(;i<16;i++)
    {
        int k=a%2;
        if(k==1)s[i]='1';
        else if(b%2==1) s[i]='?';
        else s[i]='0';
        a/=2;b/=2;
    }
    for(i=15;i>=0;i--)
        printf("%c",s[i]);
        printf("\n");
}
int main()
{
    int a,b,c,d;
    int top=0;
    while(true)
    {  
        top=1;
        cin>>a;
        if(a==0) break;
        cin>>b>>c>>d;
        aa[0]=d;
        for(int i=0;i< 65537;i++)
        {  
            aa[top]=(a%c*d%c+b%c)%c;
            d=aa[top++];
            if(d==aa[0])break;
        }
        int result=aa[0];
        int com=aa[0];
        for(int i=1;i<top&&i<=65536;i++)
        {
            result &= aa[i];
            com |=aa[i];
        }
        convert(result,com);
    }
    return 0;
}
