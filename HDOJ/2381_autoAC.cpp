#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <sstream>
#include <string>
using namespace std;
#define out(X) cerr << #X << ": " << (X) << endl
#define SZ(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define REP(I,N) for (int I = 0; I < (N); ++I)
#define FOR(I,L,H) for (int I = (L); I < (H); ++I)
#define MP(X,Y) make_pair((X),(Y))
#define PB push_back
#define ALL(X) X.begin(), X.end()
template <typename T> inline bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T> inline bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
typedef long long lint;
const double EPS = 1e-9;
int sgn(const double &x) {return (int)((x > EPS) - (x < -EPS));}
int T,N;
double tot,p;
vector<double> bef,aft,init;
int check(const double &mid) {
 bef.clear();
 aft.clear();
 for(int i = 0 ; i < N ; i++) {
 bef.push_back(init[i]);
 }
 if (sgn(mid) != 0) bef.push_back(mid);
 while(SZ(bef) > 1) {
 sort(ALL(bef));
 aft.clear();
 aft.push_back((bef[0] + bef[1]) / (1 - p));
 for(int i = 2 ; i < SZ(bef) ; i++) {
 aft.push_back(bef[i]);
 }
 bef = aft;
 }
 if (sgn(bef[0] - tot) > 0) {
 return -1;
 }
 return 1;
}
int main() {
 scanf("%d",&T);
 while(scanf("%lf%lf%d",&tot,&p,&N) == 3) {
 p /= 100.0;
 init.clear();
 for(int i = 0 ; i < N ; i++) {
 double w;
 scanf("%lf",&w);
 init.push_back(w);
 }
 double ans = -1;
 double l = 0.0 ,r = tot,mid;
 for(int cnt = 0 ; cnt < 200 ; cnt++){
 mid = (l + r) / 2;
 if (check(mid) != -1) {
 l = mid + EPS;
 ans = mid;
 }
 else r = mid - EPS;
 }
 if (sgn(ans + 1) <= 0) {
 printf("%d\n",-1);
 continue;
 }
 printf("%.4f\n", ans); 
 }
 return 0;
}
