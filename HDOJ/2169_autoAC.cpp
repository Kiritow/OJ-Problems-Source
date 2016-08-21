#include<stdio.h>
#include<string.h>
int main()
{
 int n,i,j,k,sum,len,q,w = 1,p;
 char c,a[16];
 scanf("%d",&n);
 while(n--)
 {
  getchar();
  scanf("%c ",&c);
  if(c=='b')
  {
   k=1;
   sum=0;
   scanf("%s",a);
   len=strlen(a);
   for(i=len-1;i>=0;i--)
   {
    sum=sum+(a[i]-'0')*k;
    k=-2*k;
   }
   printf("From binary: %s is %d\n", a, sum);
  }
  else if(c=='d')
  {
   scanf("%d",&p);
   i=0;
   q=p;
   if(p==0){printf("From decimal: 0 is 0\n");continue;}
   while(p!=0)
   {
    a[i++]=p%(-2);
    p=p/(-2);
    if(a[i-1]==-1)
    {
     a[i-1]=1;
     if(p<0)p--;
     else p++;
    }
   }
   printf("From decimal: %d is ",q);
   for(j=i-1;j>=0;j--)
    printf("%d",a[j]);
   printf("\n");
  }
 }
 return 0;
}
