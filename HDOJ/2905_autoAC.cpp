#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int oo = 1000000000;
char s[10010], cards[2][50];
int dp[10010], nc[2], value[300];
void update(int& x, int y)
{
 if (y > x) x = y;
}
int lv(int u)
{
 int ret = 0;
 for (int i = 0; i < nc[u]; ++i) ret += value[cards[u][i]];
 return ret;
}
int hv(int u)
{
 int ret = 0, x = 0;
 for (int i = 0; i < nc[u]; ++i)
 if (cards[u][i] == 'A') ++x, ret += 11;
 else ret += value[cards[u][i]];
 while (ret > 21 && x > 0) ret -= 10, --x;
 return ret;
}
void getCard(int u, int& cur)
{
 cards[u][nc[u]++] = s[cur++];
}
int main()
{
 for (int i = '2'; i <= '9'; ++i) value[i] = i-'0';
 value['T'] = value['J'] = value['Q'] = value['K'] = 10;
 value['A'] = 1;
 int T, n, p, q, l[2];
 scanf("%d", &T);
 while (T--) {
 scanf("%d%d%d", &n, &p, &q);
 int cur = 0;
 while (cur < n) {
 scanf("%s", s+1+cur);
 cur += strlen(s+1+cur);
 }
 for (int i = 1; i <= n; ++i) dp[i] = -oo;
 dp[0] = 0;
 for (int i = 0; i < n; ++i) if(dp[i] != -oo) {
 if (i+4 > n) {
 update(dp[n], dp[i]);
 continue;
 }
 int cur = i + 1;
 nc[0] = nc[1] = 0;
 getCard(0, cur);
 getCard(1, cur);
 getCard(0, cur);
 getCard(1, cur);
 l[0] = value[cards[0][0]]+value[cards[0][1]];
 while(1) {
 if (l[0] > 21) {
 update(dp[cur-1], dp[i] - p);
 break;
 }
 int pre = cur;
 nc[1] = 2;
 while (pre <= n && hv(1) < 17) getCard(1, pre);
 if (hv(1) < 17) update(dp[n], dp[i]);
 else {
 int h[2] = {hv(0), hv(1)};
 if (lv(1) > 21) update(dp[pre-1], dp[i] + q);
 else if (h[0] > h[1]) update(dp[pre-1], dp[i] + q);
 else if (h[0] < h[1]) update(dp[pre-1], dp[i] - p);
 else update(dp[pre-1], dp[i]);
 }
 if (cur <= n) {
 l[0] += value[s[cur]];
 getCard(0, cur);
 }
 else {
 update(dp[n], dp[i]);
 break;
 }
 }
 }
 printf("%d\n", dp[n]);
 }
 return 0;
}
