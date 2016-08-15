#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h> 
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
const int radix=256*256;
int main()
{
 string s; 
 long long r;
  while(getline(cin,s))
  {
   if(s[0]=='#')break;
  if(s.length()==0)
  {
   cout<<"00 00"<<endl;
   continue;
  }
  int len=s.length(),t;
     r=0;
  for(int i=0;i<len;i++)
  {   t=s[i];
   r=(256*r+t)%34943;
  }
  r=(r*radix)%34943;
  if(r==0)
  {
   cout<<"00 00"<<endl;
   continue;
  }
  r=34943-r;
  int b=r%256,a=r/256,c;
  c=a/16;
  if(c>9)cout<<(char)('A'+c-10);
  else cout<<c;
  c=a%16; 
  if(c>9)cout<<(char)('A'+c-10);
  else cout<<c;
  cout<<" ";
  c=b/16;
  if(c>9)cout<<(char)('A'+c-10);
  else cout<<c;
  c=b%16; 
  if(c>9)cout<<(char)('A'+c-10);
  else cout<<c;
  cout<<endl; 
  }
  return 0;
}
