#include<stdio.h>
#include<string.h>
int main()
{ 
  int n,i;
  scanf("%d",&n);
  while(n--)
  {
      char str[50],z,c;
      scanf("%s",str);
      z=strlen(str);
      for(i=0;i<z;)
      {
         c=str[i];
        str[i]=str[i+1];
        str[i+1]=c;
        i+=2;     
      }
      printf("%s\n",str);
  }                                  
  return 0;
 }
