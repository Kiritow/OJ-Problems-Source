#include<iostream>
#include<string>
#include<ctype.h>
#include<cstdio>
using namespace std;
int main()
{
    int n[11111]={0};
    n[2]=1,n[1]=1;
    for(int i=3;i<11111;i++)
    {
        n[i]=(n[i-1]+n[i-2])%26;
    }
    char c[11111];
    while(gets(c))
    {
        int num=0;
        for(int i=0;c[i];i++)
        {
            if(isupper(c[i]))
            {
                num++;
                printf("%c",isupper(c[i]+n[num])?c[i]+n[num]:c[i]+n[num]-26);
            }
            else
                printf("%c",c[i]);
        }
        cout<<endl;
    }
    return 0;
}
