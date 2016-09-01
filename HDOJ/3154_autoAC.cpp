#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
typedef long long LL;
typedef pair<int, char>PII;
typedef pair<PII, int>PII2;
PII in[20];
int n;
int maxSolve = 0, minnTime;
PII order[20];
PII ans[20];
void search(int a, int b, int c, int at, int t)
{
 if(a > 300) return ;
 if(b > 300) return ;
 if(c > 300) return ;
 if(at > maxSolve)
 {
 maxSolve = at;
 minnTime = t;
 for(int i = 0; i < at; i++ )
 ans[i] = order[i];
 }
 else if(at == maxSolve)
 {
 if(t < minnTime)
 {
 minnTime = t;
 for(int i = 0; i < at; i++ )
 ans[i] = order[i];
 }
 else if(t == minnTime)
 {
 sort(ans, ans + maxSolve);
 PII temp[20];
 for(int i = 0; i < maxSolve; i++ ) temp[i] = order[i];
 sort(temp, temp + maxSolve);
 int swap = 0;
 for(int i = 0; i < maxSolve; i++ )
 {
 if(temp[i].second < ans[i].second)
 {
 swap = 1;
 break;
 }
 else if(temp[i].second > ans[i].second)
 {
 break;
 }
 }
 if(swap)
 {
 for(int i = 0; i < maxSolve; i++ ) ans[i] = temp[i];
 }
 }
 }
 if(at == n) return ;
 order[at] = PII(a + in[at].first, in[at].second);
 search(a + in[at].first, b, c, at + 1, t + a + in[at].first);
 order[at] = PII(b + in[at].first, in[at].second);
 search(a, b + in[at].first, c, at + 1, t + b + in[at].first);
 order[at] = PII(c + in[at].first, in[at].second);
 search(a, b, c + in[at].first, at + 1, t + c + in[at].first);
}
class Solve
{
 public:
 void main2()
 {
 cin >> n;
 for(int i = 0; i < n; i++ )
 {
 cin >> in[i].first;
 in[i].second = 'A' + i;
 }
 sort(in, in + n);
 maxSolve = 1;
 minnTime = in[0].first;
 order[0] = PII(in[0].first, in[0].second);
 search(in[0].first, 0, 0, 1, in[0].first);
 sort(ans, ans + maxSolve);
 for(int i = 0; i < maxSolve; i++ ) printf("%c ", ans[i].second);
 printf("%d %d\n", maxSolve, minnTime);
 }
};
int main()
{
 int Test;
 scanf("%d", &Test);
 for(int t = 1; t <= Test; t++ )
 {
 Solve ___test;
 printf("Data set %d: ", t);
 ___test.main2();
 }
return 0;
}
