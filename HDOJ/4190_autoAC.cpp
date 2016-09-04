#include<iostream>
#include<algorithm>
#include<math.h>
#define size 500010
using namespace std;
int n,m;
int a[size];
int ok(int x)
{
    int i = 0 , t = 0;
    while ( i < n) 
    {
          t += ceil(a[i]*1.0 / x );
          i++;
    }    
    if(t > m)  return 0;   
    else return 1;
}
int find_ans(int low , int heigh)
{
    int mid , ans;
    while (low < heigh)
    {
          mid = (low + heigh) /2; 
          int temp = ok(mid); 
          if( ok(mid) == 0 ) {  low = mid + 1; }
          else {   heigh = mid ;}
    }
    return heigh;
}
int main()
{
    int max;
    while ( scanf("%d%d",&n,&m) != EOF && n!=-1 && m!=-1)
    {
          int avg = m/n;
          max = 0;
          for(int i=0;i<n;i++)  
          {
               scanf("%d",&a[i]);
               if(a[i] > max) max = a[i];
          }
          if( n == m ) printf("%d\n",max);
          else
               printf("%d\n",find_ans(1, max));
    }
    return 0;
}
