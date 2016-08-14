#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s;
   while(cin>>s)              
   {
      int count=0;
      int i,l,r;
      for(i=1;i<s.size()-1;i++)           
 {
         l=i-1;r=i+1;
         while(l>=0&&r<s.size())         
         {
            if(s[l]==s[r]){count++;l--;r++;}
            else break;
         }
      }
      for(i=0;i<s.size()-1;i++)    
      {
         if(s[i]==s[i+1])
         {
            count++; 
            l=i-1;r=i+2;
            while(l>=0&&r<s.size())
            {
                if(s[l]==s[r]){count++;l--;r++;}
                else break;
            }
         }
      }
      cout<<count+s.size()<<endl;
   }
   return 0;
}
