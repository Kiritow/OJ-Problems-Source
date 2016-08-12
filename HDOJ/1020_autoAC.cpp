#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[10010];
int main()
{
     int n;
     scanf("%d",&n);
     getchar();
     while(n--)
     {
          int len,i,j,count=1;
          memset(s,0,sizeof(s));
          scanf("%s",s);
          len=strlen(s);
          i=0;
          j=i+1;
          while(j<=len)
          {
               if(s[i]!=s[j])
               {
                    if(count==1)
                    {
                     printf("%c",s[i]);
                    }
                    else
                    {
                         printf("%d%c",count,s[i]);
                       }
                       i=j;
                       j++;
                       count=1;
                  }
                  else
                  {
                       j++;
                       count++;
                     }
             }
             printf("\n");
        }
}
