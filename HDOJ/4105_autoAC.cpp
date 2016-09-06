#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[5000];
int main()
{
    int i,j,k,n,m,b,c;
    while (1)
    {
          if (scanf("%d",&n)==EOF) break;
          scanf("%s",a);
          for (i=0;i<n;i++) a[i]-='0';
          bool f=false;
          int ans=0;
          b=0;
          c=10;
          for (i=0;i<n;i++)
          {
              if (f==false)
              {
                 if (c>a[i]) b=a[i];
                 else
                 {
                     i++;
                     b=a[i];
                 }
              }
              else
              {
                  if (a[i]>b) c=a[i];
                  else
                  {
                      if (a[i]==0)
                      {
                         while (a[i]==0) i++;
                         b=0;
                         c=a[i];
                      }
                      else
                      {
                          i++;
                          c=a[i-1]*10+a[i];
                      }
                  }
              }
              if (i>=n) break;
              ans++;f=!f;
          }
          cout<<ans-1<<endl;
    }
    return 0;
}
