#include<iostream>
#include<string>
using namespace std;
int f[100000];
int main()
{
   string s;
   while(cin>>s&&s!="0")
   {
      int i;
      for(i=0;i<s.size()+1;i++)
           f[i]=1;
       i=s.size()-1;    
      while(s[i]=='0')
         {
            i--;if(i==0)goto end;
            i--;if(i==0)goto end;   
         }
       i--;   
      for(;i>=0;i--)
      {
         while(s[i]=='0')
         {
            i--;f[i]=f[i+2];if(i==0)goto end;
            i--;f[i]=f[i+1];if(i==0)goto end;
            if(s[i]=='0')continue;
            i--; 
         } 
          if(s[i]<='2')
         {
            f[i]=f[i+1]+f[i+2];
         }
         else  
         {
            f[i]=f[i+1];
         }
     }
     end:
     cout<<f[0]<<endl;
   }
   return 0;
}
