#include <cstdlib>   
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int N = 10000;
vector<int> v[N + 1];
int flag[N + 1];
int cnt;
void dfs(int x)
{
    if (flag[x]) return;
    flag[x] = 1;
    cnt++;
    for (int i = 0; i < v[x].size(); i++)
    {
        dfs(v[x][i]);
    }
}
int main()
{
    int ncase;
    while (cin >> ncase)
    {
        while (ncase--)
        {
            int n, m, l;
            cin >> n >> m >> l;
            for (int i = 1; i <= n; i++) v[i].clear();
            for (int i = 0; i < m; i++)
            {
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
            }
            MEM(flag, 0);
            cnt = 0;
            while (l--)
            {
                int x;
                cin >> x;
                dfs(x);
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
