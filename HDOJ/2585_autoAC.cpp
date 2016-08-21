#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int find(string a,string b)
{
    int i,j;
    for(i=0;i<a.length();i++)
    {
           if(a[i]=='*')
           {
                if(i==a.length()-1)
                        return true;
               string c=a.substr(i+1);
                for(j=i;j<b.length();j++)
                    if(find(c,b.substr(j)))  return 1;
           }
           else
           {
               if(i>=b.length()) return 0;
               if(a[i]=='?')  continue;
               if(a[i]!=b[i]) return 0;
           }
    }
    return 1;
}
int main()
{
      int ans;
      string a,b;
      while(cin>>a)
      {
          int k;
          ans=0;
          scanf("%d",&k);
           while(k--)
           {
               cin>>b;
               if(find(a,b)) ans+=1;
           }
           printf("%d\n",ans);
      }
      return 0;
}
