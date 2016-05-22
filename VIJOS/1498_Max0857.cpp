#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
 int wei;
 int sum;
};
int min(int a,int b)
{
 if(a>b) return b;
 else return a;
}
int cmp(const void *a,const void *b)
{
 node n1=*(node *)a;
 node n2=*(node *)b;
 if(n2.sum!=n1.sum) return n2.sum-n1.sum;
 else
  return n2.wei-n1.wei;
}
int cmp1(const void *a,const void *b)
{
 return *(int *) a-*(int *) b;
}
int main()
{
 node Xxian[1001];
 node Yxian[1001];
 int pai1[1001],pai2[1001];
 memset(Xxian,0,sizeof(Xxian));
 memset(Yxian,0,sizeof(Yxian));
 int n,m,k,l,d;
 int x1,y1,x2,y2;
 cin>>n>>m>>k>>l>>d;
 for(int i=1;i<=d;i++)
 {
  cin>>x1>>y1>>x2>>y2;
  if(x1==x2)
  {
   Xxian[min(y1,y2)].sum++;
   Xxian[min(y1,y2)].wei=min(y1,y2);
  }
  else
  {
   Yxian[min(x1,x2)].sum++;
   Yxian[min(x1,x2)].wei=min(x1,x2);
  }
 }
 qsort(Xxian,1000,sizeof(node),cmp);
 qsort(Yxian,1000,sizeof(node),cmp);
 for(int b=0;b<k;b++)
  pai1[b]=Yxian[b].wei;
 qsort(pai1,k,sizeof(int),cmp1);
 for(int b=0;b<k-1;b++)
  cout<<pai1[b]<<' ';
 cout<<pai1[k-1]<<'\n';
 for(int c=0;c<l;c++)
  pai2[c]=Xxian[c].wei;
 qsort(pai2,l,sizeof(int),cmp1);
 for(int c=0;c<l-1;c++)
  cout<<pai2[c]<<' ';
 cout<<pai2[l-1]<<'\n';
}
