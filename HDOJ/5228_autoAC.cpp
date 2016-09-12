#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int has[13*4];
char s[5];
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
         memset(has,0,sizeof(has));
         for(int i=0;i<5;i++)
         {
             scanf("%s",s);
             int cur;
             if(strlen(s)==3)
             {
                 cur=(s[1]-'0')*10+s[2]-'0';
             }
             else
             {
                 cur=s[1]-'0';
             }
             cur--;
             has[cur*4+s[0]-'A']++;
         }
         int ans=5;
         for(int i=0;i<10;i++)
         {
             for(int j=0;j<4;j++)
             {
                 int cnt=5;
                 for(int k=0;k<5;k++)
                 {
                     int num=(i+k)*4+j;
                     if(has[num%(52)]) cnt--;
                 }
                 ans=min(ans,cnt);
             }
         }
         printf("%d\n",ans);
     }
}
