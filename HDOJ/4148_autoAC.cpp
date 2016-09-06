#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[31][10000];
int main()
{
    int n,i,j,len;
    s[1][0]='1';
    s[1][2]='\0';
    for(i=2;i<31;i++)
    {
        len=strlen(s[i-1]);
        int sum=1,k=0;
        for(j=0;j<len;j++)
           if(s[i-1][j+1]==s[i-1][j]) sum++;
           else
           {
               s[i][k]=sum+'0';
               k++;
               s[i][k]=s[i-1][j];
               k++;
               sum=1;
           }
           s[i][k]='\0';
    }
    while(cin>>n&&n)
    {
        len=strlen(s[n]);
        cout<<len<<endl;
    }
    return 0;
}
