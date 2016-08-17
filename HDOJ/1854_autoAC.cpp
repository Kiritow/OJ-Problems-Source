#include<stdio.h>
#include<string.h>
#define N 1010
char str[N];
int Judge(char *s)
{
         int len,i,ans;
         len=strlen(s);
         ans=0;
         for(i=0;i<len;i++)
         {
                   if(s[i]=='0')
                   {
                            ans++;
                   }
                   else if(s[i]=='1')
                   {
                            if(ans>1)
                            {
                                     ans--;
                            }
                            else
                            {
                                     return 0;
                            }
                   }
         }
         if(ans>=1)
         {
                   return 1;
         }
}
int main()
{
         int n,len,flag;
         scanf("%d",&n);
         getchar();
         while(n--)
         {
                   scanf("%s",str);
                   flag=Judge(str);
                   if(flag)
                   {
                            printf("Yes\n");
                   }
                   else
                   {
                            printf("No\n");
                   }
         }
         return 0;
}
