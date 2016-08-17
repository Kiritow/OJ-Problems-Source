#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int zsh(char s[])
{
 int p;
 for(p=0;p<strlen(s);p++)
 {
  if(s[p]=='.')
  break;
 }
 return p;
}
int pd(char s[])
{
 int l=0,flag=0;
 for(l=0;l<strlen(s);l++)
 {
  if(s[l]=='.')
  {
   flag=1;
   break;
  }
 }
 return flag;
}
void add(char as[],char bs[])
{
 int l,j,az[405]={0},bz[405]={0},c[405]={0};
 for(l=0;l<strlen(as);l++)
 {
  az[l]=as[l]-48;
  bz[l]=bs[l]-48;
 }
 for(j=0;j<l;j++)
 {
    c[j]+=az[j]+bz[j];
    if(c[j]>=10)
     {
      c[j+1]++;
      c[j]-=10;
     }
 }
 if(c[l]>0) 
 l++;
 for(j=0;j<l;j++)
 {
  as[j]=c[j]+48;
 }
 as[j]='\0';
}
int main() 
{
    int i,j,lz,lx;
    char a[405],b[405];
    while(scanf("%s %s",a,b)!=EOF)
   {
     int lxa,lxb;
     lxa=pd(a)>0?(strlen(a)-zsh(a)-1):0;
     lxb=pd(b)>0?(strlen(b)-zsh(b)-1):0;
        char a1[405],b1[405];
     lx=lxa>lxb?lxa:lxb;
     lz=zsh(a)>zsh(b)?zsh(a):zsh(b);
     for(i=0;i<lx+lz;i++)
        {a1[i]='0';b1[i]='0';}
     a1[lx+lz]='\0';b1[lx+lz]='\0';
     for(i=0;i<zsh(a);i++)
     a1[lx+zsh(a)-i-1]=a[i];
     for(i=zsh(a)+1;i<strlen(a);i++)
     a1[lx-i+zsh(a)]=a[i];
     for(i=0;i<zsh(b);i++)
     b1[lx+zsh(b)-i-1]=b[i];
     for(i=zsh(b)+1;i<strlen(b);i++)
     b1[lx-i+zsh(b)]=b[i];
     add(a1,b1);
     for(i=0;i<strlen(a1);i++)
     {
      if(a1[i]!='0')
      break;
     }
     for(j=strlen(a1)-1;j>=lx;j--)
     printf("%c",a1[j]);
     if(i>=lx)
     printf("\n");
     else
     {
      printf(".");
      for(;j>=i;j--)
      printf("%c",a1[j]);
      printf("\n");
     }
   }
    return 0;
}
