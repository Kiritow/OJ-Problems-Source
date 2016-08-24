#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n, w;
int data[1000];
int interval [1000];
void solve()
{
 int k = 0;
 double sum = 0.01;
 sort(data + 1, data + n + 1);
 while(!(data[n] >= k*w && data[n] <= (k+1)*w-1))
 {
 k++;
 }
 memset(interval, 0, sizeof(interval));
 for(int i = 1; i <= n; i++)
 {
 int kk = 0;
 while(kk <= k)
 {
 if(data[i] >= kk*w && data[i] <= (kk+1)*w-1)
 {
 interval[kk] ++;
 break;
 }
 else
 {
 kk++;
 }
 }
 }
 int max = 0;
 for(int i = 0; i <= k; i++)
 {
 if(max < interval[i])
 {
 max = interval[i];
 }
 }
 for(int i = 0; i <= k; i++)
 {
 sum += ((double)interval[i]) / ((double)max) * (k-i) / k;
 }
 printf("%.6lf\n", sum);
}
int main()
{
 while(1)
 {
 scanf("%d%d", &n, &w);
 if(n == 0 && w == 0)
 {
 break;
 }
 else
 {
 for(int i = 1; i <= n; i++)
 {
 scanf("%d", &data[i]);
 }
 }
 solve();
 }
 return 0;
}
