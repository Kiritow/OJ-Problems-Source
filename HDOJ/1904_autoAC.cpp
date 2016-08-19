#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
int s[10001][6];
int main()
{
 int n,i,j,sum,max,num;
 map<string,int>::iterator it;
 map<string,int>ans;
 while(scanf("%d",&n),n)
 {
  ans.clear();
  for(i=1;i<=n;i++)
  for(j=0;j<5;j++)
  scanf("%d",&s[i][j]);
  for(i=1;i<=n;i++)
  sort(s[i],s[i]+5);
  for(i=1;i<=n;i++)
  {
    string str;
    for(j=0;j<5;j++)
    {
    char a[5];
    itoa(s[i][j],a,10);
    str+=a;
    }
    ans[str]++;
  }
  max=num=0;
  for(it=ans.begin();it!=ans.end();it++)
  if(it->second>max)max=it->second;
  for(it=ans.begin();it!=ans.end();it++)
  if(it->second==max)num++;
  printf("%d\n",num*max);
 }
 return 0;
}
