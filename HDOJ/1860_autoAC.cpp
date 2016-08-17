#include<stdio.h>
#include<string.h>
int main()
{
      int i,j,sum;
      char a[5],b[80];
            while(gets(a))
            {
                  if(a[0]=='#')
                        break;
                  else
                        gets(b);
                  for(i=0;i<strlen(a);i++)
                  {
                        sum=0;
                        for(j=0;j<strlen(b);j++)
                        {
                           if(a[i]==b[j])
                                 sum++;
                        }
                        printf("%c %d\n",a[i],sum);
                  }
            }
}
