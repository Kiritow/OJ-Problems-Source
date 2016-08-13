#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#include <ctype.h>
#include <set>
#include <map>
#include <iomanip>
#define INIT(x,y) memset(x,y,sizeof(x))
#define INF 0x7fffffff
#define FAIL {puts("Hat cannot buy tea.");continue;}
using namespace std;
int n, t1, t2, t3, a1, a2, a3;
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> t1 >> t2 >> t3)
    {
        if (!n && !t1 && !t2 && !t3) break;
        if (t1 + 5 * t2 + 10 * t3 < n) FAIL
        if ((t1 == 0) && (t2 == 0) && (n % 10)) FAIL
        if ((t1 == 0) && (n % 5)) FAIL
        a1 = a2 = a3 = 0;
        if (t2)
        {
            if (t1 < n % 5) FAIL
            a1 = n % 5 + min(n - n % 5, (t1 - n % 5) / 5 * 5);
            n -= a1;
            a2 = (n % 10 == 5) ? 1 : 0;
            a2 += min((n - 5 * a2) / 10 * 2, (t2 - a2) / 2 * 2);
            n -= a2 * 5;
        }
        else
        {
            if (t1 < n % 10) FAIL
            a1 = n % 10 + min(n - n % 10, (t1 - n % 10) / 10 * 10);
            a2 = 0;
            n -= a1;
        }
        a3 = min(n / 10, t3);
        cout << a1 << " YiJiao, " << a2 << " WuJiao, and " << a3 << " ShiJiao" << endl;
    }
}
