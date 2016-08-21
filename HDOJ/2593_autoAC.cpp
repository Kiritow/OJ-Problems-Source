#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int x[10009];
int main()
{
 int n,i,j;
 set<int>set1;
 while(scanf("%d",&n)!=EOF)
 {
  for(i=0;i<n;i++)
  {
   scanf("%d",&x[i]);
   set1.insert(x[i]);
  }
  sort(&x[0],&x[n]);
  int ok=0;
  for(i=0;i<n;i++)
  {
   for(j=i+2;j<n;j++)
   {
    if((x[i]+x[j])%2==0&&set1.find((x[i]+x[j])/2)!=set1.end())
    {
     ok=1;
     printf("Sequence is not 3-free. Witness: %d,%d,%d.\n",x[i],(x[i]+x[j])/2,x[j]);
     break;
    }
   }
   if(ok==1)break;
  }
  if(ok==0)
   printf("Sequence is 3-free.\n");
 }
 return 0;
}
