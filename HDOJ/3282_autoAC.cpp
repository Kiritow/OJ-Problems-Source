#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
void run()
{
 int n,m;
 scanf("%d%d",&n,&m);
 int i,num[10001];
 int ans[10001]={0};
 int u=2;
 printf("%d %d\n",n,(m+1)/2);
 scanf("%d",&num[1]);
 ans[1]=num[1];
 for(i=2;i<=m;i++) 
 {
  int tmp,j,k;
  scanf("%d",&tmp);
  if(tmp<=num[1]) 
  {
   for(k=i-1;k>=1;k--)
   {
    num[k+1]=num[k];
   }
   num[1]=tmp; 
  }
  else if(tmp>=num[i-1]) 
  {num[i]=tmp;}
  else 
  {
   bool f=false;
   for(j=i-1;j>=1;j--)
   {
    if(tmp>=num[j-1] && tmp<=num[j]) 
    {
     f=true;
     int k;
     {
      for(k=i-1;k>=j;k--)
      {
       num[k+1]=num[k];
      }
      num[j]=tmp;
     }
    }
    if(f==true) break;
   }
  }
  if(i%2==1) 
  {
   ans[u++]=num[(i+1)/2];
  } 
 }
 for(i=1;i<u;i++)
 {
  if(i%10==0 || i==u-1) printf("%d\n",ans[i]);
  else printf("%d ",ans[i]);
 }
}
int main()
{ 
 int total;
 cin>>total;
 for(int now=1;now<=total;now++)  run();
 return 0;
}
