#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
int x[100005], y[100005];
vector<int> s1, s2;
void gao(int *p, vector<int>& V) {
 sort(p, p+n);
 V.clear();
 p[n] = -1;
 int cnt = 1;
 for(int i=0; i<n; i++) {
 if(p[i] != p[i+1]) {
 V.push_back(cnt);
 cnt = 1;
 } else cnt ++;
 }
 for(int i=0; i<V.size(); i++) {
 }
}
int ans;
vector<int> v;
void dfs(int pi, int ni, int cur) {
 if(pi == k || ni == v.size()) {
 cur += (k - pi) * abs(n);
 if(ans > cur) ans = cur;
 return ;
 }
 int sum = (ni == 0) ? 0 : v[ni-1];
 if(pi == k-1) {
 dfs(pi+1, v.size(), cur+abs(v[v.size()-1] - sum - n));
 return ;
 }
 int id = lower_bound(v.begin(), v.end(), n + sum) - v.begin();
 id --;
 if(ni <= id && id < v.size()) dfs(pi+1, id+1, cur+abs(v[id] - sum - n));
 id ++;
 if(ni <= id && id < v.size()) dfs(pi+1, id+1, cur+abs(v[id] - sum - n));
}
int solve(vector<int> V) {
 ans = 1000000;
 v = V;
 for(int i=1; i<v.size(); i++) {
 v[i] += v[i-1];
 }
 for(int i=0; i<v.size(); i++) {
 v[i] *= k;
 }
 dfs(0, 0, 0);
 return ans;
}
int gcd(int x, int y) {
 while(x%=y^=x^=y^=x);
 return y;
}
int main()
{
 int kase = 0;
 while(scanf("%d%d", &n, &k) == 2 && n && k) {
 for(int i=0; i<n; i++) {
 scanf("%d%d", &x[i], &y[i]);
 }
 gao(x, s1);
 gao(y, s2);
 int ans = solve(s1);
 ans = min(ans, solve(s2));
 if(ans == 0) {
 printf("%d. 0/1\n", ++kase);
 continue;
 }
 k *= k;
 int g = gcd(ans, k);
 ans /= g; k/= g;
 printf("%d. %d/%d\n", ++kase, ans, k);
 }
 return 0;
}
