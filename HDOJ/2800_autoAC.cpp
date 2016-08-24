#include<iostream>
using namespace std;
int main()
{
 int n;
 while(scanf("%d",&n)!=EOF&&n)
 {
  printf("%d\n",(n+1)>>1);
 }
}
