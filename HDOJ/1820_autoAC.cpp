#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
long long bishops(int n, int k)
{
  long long r1[9];
  long long r2[9];
  for (int i = 1; i <= n; ++i)
    r1[i] = i % 2 != 0 ? i : r1[i-1];
  for (int i = 1; i <= n-1; ++i)
    r2[i] = i % 2 != 0 ? i+1 : r2[i-1];
  long long c1[9][65] = {{0}};
  long long c2[9][65] = {{0}};
  for (int i = 0; i <= n; ++i)
    c1[i][0] = 1;
  for (int j = 1; j <= k; ++j)
    c1[0][j] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= k && j <= i; ++j)
      c1[i][j] = c1[i-1][j] + c1[i-1][j-1]*(r1[i] - j + 1);
  for (int i = 0; i <= n-1; ++i)
    c2[i][0] = 1;
  for (int j = 1; j <= k; ++j)
    c2[0][j] = 0;
  for (int i = 1; i <= n-1; ++i)
    for (int j = 1; j <= k && j <= i; ++j)
      c2[i][j] = c2[i-1][j] + c2[i-1][j-1]*(r2[i] - j + 1);
  long long r = 0;
  for (int i = 0; i <= k; ++i)
    r += c1[n][i] * c2[n-1][k-i];
  return r;
}
int main(int argc, char *argv[])
{
  for (int n, k; cin >> n >> k && !(n == 0 && k == 0); )
    cout << bishops(n, k) << endl;
  return 0;
}
