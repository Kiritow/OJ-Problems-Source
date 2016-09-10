#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#define LL long long
#define lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define BitCount(x) __builtin_popcount(x)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
using namespace std;
const int MAXN = 1e5 + 100;
const int MOD = 20071027;
typedef pair<int, int> pii;
typedef vector<int>::iterator viti;
typedef vector<pii>::iterator vitii;
char str[MAXN];
int cnt[30];
int main()
{
    //ROP;
    int n, i, j, last, T, k;
    scanf("%d", &T);
    while (T--)
    {
        MS(cnt, 0);
        int pos = 1;
        scanf("%s", str + 1);
        scanf("%d", &k);
        int len = strlen(str + 1);
        LL ans = 0;
        for (i = 1; i <= len; i++)
        {
            cnt[str[i] - 'a']++;
            while (cnt[str[i] - 'a'] > k)
            {
                cnt[str[pos] - 'a']--;
                pos++;
            }
            ans += i - pos + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
