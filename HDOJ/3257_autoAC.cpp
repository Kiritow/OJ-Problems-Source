#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
string str[17]={"0000","0001","0010","0011","0100","0101","0110","0111",
"1000","1001","1010","1011","1100","1101","1110","1111"};
char map[8][500];
string trans(string ch)
{
   string s="";
   for(int i=0;i<2;i++)
   {
      if(ch[i]>='A'&&ch[i]<='F')
         s+=str[ch[i]-'A'+10];
      else
         s+=str[ch[i]-'0'];
   }
   return s;
}
int main()
{
   string ch,str;
   int t,n,i,j,k,p;
   scanf("%d",&t);
   for(int Case=1;Case<=t;Case++)
   {
      scanf("%d",&n);
      int minx=10,maxn=-1;
      p=0;
      for(i=0;i<n;i++)
      {
         for(k=0;k<5;k++)
         {
            str="";
            ch="";
            cin>>ch;
            ch=trans(ch);
            for(j=0;j<=7;j++)
            { 
               if(ch[j]=='1')
                  map[j][p]='#';
               else map[j][p]=' ';
            }
            p++;
         }
         if(i!=n-1)
         {
            for(j=0;j<=7;j++)
               map[j][p]=' ';
            p++;
         }
      }
      printf("Case %d:\n\n",Case);
      bool flag=0,tag=0;
      for(i=7;i>=0;i--)
      {
         for(j=0;j<p;j++)
            if(map[i][j]=='#') {flag=1;break;}
         if(flag) break;
      }
      for(k=0;k<=7;k++)
      {
         for(j=0;j<p;j++)
            if(map[k][j]=='#') {tag=1;break;}
         if(tag) break;
      }
      for(;i>=k;i--)
      {
         for(j=0;j<p;j++)
            printf("%c",map[i][j]);
         printf("\n");
      }
      printf("\n");
   }
   return 0;
}
