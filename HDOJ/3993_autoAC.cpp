#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
int a[20];
int b[20];
int main(){
 int test,n;
 scanf("%d",&test);
 while (test--){
 scanf("%d",&n);
 for (int i=0;i<n;i++)
 scanf("%d",&a[i]);
 for (int j=0;j<n;j++)
 scanf("%d",&b[j]);
 int ans=0;
 for (int i=0;i<n;i++)
 for (int j=0;j<n;j++)
 if (b[i]>a[j]) ans+=3;
 printf("%.6lf\n",ans*1.0/n);
 }
 return 0;
}
