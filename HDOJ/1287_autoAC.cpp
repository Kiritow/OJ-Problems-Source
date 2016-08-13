#include<iostream>
using namespace std;
char str[10005];
int wen[10005];
int main()
{
      int n;
      char s;
      while(cin>>n)
      {
          int top=0; 
        for(int j=0;j<n;j++)
        {
            cin>>wen[j];
        }
        for(char c='A';c<='Z';c++)
          {
              for(int i=0;i<n;i++)
              {
                  s=c^wen[i];
              if(s>='A'&&s<='Z')
              {
                  str[top++]=s;
              }
              else
              {
                  top=0;
                  break;
              }
              }
              if(top==n)
              {
                  break;
              }
          }
          for(int k=0;k<top;k++)
          {
              cout<<str[k];
          }
          cout<<endl;
      }
      return 0;
}
