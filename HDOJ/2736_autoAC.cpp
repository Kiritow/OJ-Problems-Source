#include<stdio.h>
#include<string.h>
int main()
{
int i,j,len,k,z,l,flag;
char ch[100];
char  s[100][2];
while(gets(ch))
{
memset(s,0,sizeof(s));
flag=0;
if(ch[0]=='*')
break;
len=strlen(ch);
for(i=1;i<len-1;i++)
 {
  k=0;
  for(j=0;j+i<len;j++)      
 {
        s[k][0]=ch[j];                
s[k][1]=ch[j+i];
k++; 
 }
 for(z=0;z<k;z++)                     
   for(l=z+1;l<k;l++)
   {
    if(s[z][0]==s[l][0]&&s[z][1]==s[l][1])
      {flag=1;break;}
    }
    if(flag==1)
    break;
   }
   if(flag==1)
   {
    printf("%s is NOT surprising.\n",ch);
   }
   else
   {
    printf("%s is surprising.\n",ch);
   }
   memset(ch,0,sizeof(ch));
}
return 0;
}
