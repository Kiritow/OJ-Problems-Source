#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS (1e-8)
double dp[1010];
using namespace std;
double cal(double a,double b,double pre,double p) {
 return (p-pre)/(1+pow(p-a,b));
}
double get_max(int a,double b,double pre) {
 double l = a+1 ,r = 1e10;
 while(abs(l-r)>EPS) {
 double mid = (l+r)/2.0,mmid = (r+mid)/2.0;
 if(cal(a,b,pre,mmid)<cal(a,b,pre,mid)) r = mmid;
 else l = mid;
 }
 int ans = l;
 return cal(a,b,pre,ans)>cal(a,b,pre,ans+1)?cal(a,b,pre,ans):cal(a,b,pre,ans+1);
}
double get(double a,double b,int n) {
 dp[0] = a;
 for(int i(1);i!=n;++i)
 dp[i] = dp[i-1] + get_max(a,b,dp[i-1]);
 return dp[n-1];
}
int main() {
 double a,b,n;
 int t(0);
 while(cin>>n) {
 if(n==0) break;
 cin>>a>>b;
 printf("Case %d: %.2lf\n",++t,get(a,b,n));
 }
 return 0;
}
