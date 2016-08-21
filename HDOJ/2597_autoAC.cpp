#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<string>
#include<iostream>
using namespace std;
#define size 600
char s[size];
struct haha
{
    set<string>sset;
}mp[size][size];
void out();
int main()
{
    int x=-100,y=-100,i,j,flag=0;
    while(scanf("%s",s)!=EOF)
    {
          if(s[0]>='a'&&s[0]<='z')
          {
               mp[x][y].sset.insert(s);
               flag=1;
          }
          else
          {
              int n=0;
              if(flag==1) {x=-100;y=-100;flag=0;}
              if(s[0]=='-')
              {
                  if(x==-100) {x=-1; continue;}
                  else
                  {
                      if(x==-1)
                      {
                          out();
                          x=-100;
                          y=-100;
                          for(i=0;i<size;i++)
                              for(j=0;j<size;j++)
                                  mp[i][j].sset.clear();
                          continue;
                      }
                  }
              }
              i=0;
              while(s[i]!='\0')
              {
                  n=n*10+s[i]-'0';
                  i++;
              }
              if(x==-100) {x=n;continue;}
              else y=n;
              if(x>y)  {int temp=x;x=y;y=temp;}
          }
    }
    return 0;
}
void out()
{
    int i,j;
    set<string>::iterator it;
       for(i=0;i<size;i++)
          for(j=i;j<size;j++)
          {
              if(!mp[i][j].sset.empty())
              {
                  printf("%d %d",i,j);
                  for(it=mp[i][j].sset.begin();it!=mp[i][j].sset.end();it++)
                      cout<<" "<<*it;
                printf("\n");
              }
          }
}
