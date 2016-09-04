#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>
using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::stringstream;
using std::make_pair;
using std::getline;
using std::greater;
using std::endl;
using std::multimap;
using std::deque;
using std::random_shuffle;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PAIR;
typedef multimap<int, int> MMAP;
typedef LL TY;
const int MAXN(10010);
const int MAXM(5010);
const int MAXE(10010);
const int MAXK(6);
const int HSIZE(13131);
const int SIGMA_SIZE(26);
const int MAXH(19);
const int INFI((INT_MAX-1) >> 1);
const ULL BASE(31);
const LL LIM(10000000);
const int INV(-10000);
const int MOD(65521);
template<typename T> void checkmax(T &a, T b){if(b > a) a = b;}
template<typename T> void checkmin(T &a, T b){if(b < a) a = b;}
template<typename T> T ABS(const T &a){return a < 0? -a: a;}
int pre[21][10][MAXN], opt[21][10][MAXN];
int MM;
struct HASH_MAP
{
    int first[HSIZE], value[MAXN], next[MAXN];
    LL state[MAXN];
    int size;
    void init()
    {
        memset(first, -1, sizeof(first));
        size = 0;
    }
    void insert(LL ts, int tv, int x, int y, int pid, int op)
    {
        int h = ts%HSIZE;
        for(int i = first[h]; ~i; i = next[i])
            if(state[i] == ts)
            {
                if(tv > value[i])
                {
                    pre[x][y][i] = pid;
                    opt[x][y][i] = op;
                    value[i] = tv;
                }
                return ;
            }
        checkmax(MM, size);
        pre[x][y][size] = pid;
        opt[x][y][size] = op;
        state[size] = ts;
        value[size] = tv;
        next[size] = first[h];
        first[h] = size++;
    }
} hm[2];
HASH_MAP *cur, *last;
int N, M;
int code[11], path[11];  
int Num[8];
char mp[21][15];
void decode(LL ts)
{
    for(int i = 0; i <= M; ++i)
    {
        code[i] = ts&7;
        path[i] = ts&8;
        ts >>= 4;
    }
}
LL encode()
{
    LL ret = 0;
    memset(Num, -1, sizeof(Num));
    int cnt = 0;
    for(int i = M; i >= 0; --i)
        if(code[i] == 0)
            ret = (ret << 4)|path[i];
        else
        {
            if(Num[code[i]] == -1) Num[code[i]] = ++cnt;
            ret = (ret << 4)|Num[code[i]]|path[i];
        }
    return ret;
}
void updata(int x, int y, int tv, int pid)
{
    int lc = (y == 0)? 0: code[y];
    int uc = (x == 0)? 0: code[y+1];
    int lp = (y == 0)? 0: path[y-1];
    int up = (x == 0)? 0: path[y+1];
    if(mp[x][y] == 'S' || mp[x][y] == 'T')
    {
        if(lc == 0 && uc == 0)
        {
            if(lp || up) return;
            if(x < N-1)
            {
                path[y] = 8;
                code[y] = 7;
                code[y+1] = 0;
                cur->insert(encode(), tv+1, x, y, pid, 1);
            }
            if(y < M-1)
            {
                path[y] = 8;
                code[y] = 0;
                code[y+1] = 7;
                cur->insert(encode(), tv+1, x, y, pid, 1);
            }
        }
        else
            if(lc == 0 || uc == 0)
            {
                if(lc)
                {
                    if(up) return;
                    path[y] = 8;
                    code[y] = code[y+1] = 0;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
                else
                {
                    if(lp) return;
                    path[y] = 8;
                    code[y] = code[y+1] = 0;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
            }
        return;
    }
    if(mp[x][y] == 'B')
    {
        if(lc == 0 && uc == 0)
        {
            path[y] = 0;
            code[y] = code[y+1] = 0;
            cur->insert(encode(), tv, x, y, pid, 0);
        }
        return;
    }
    if(lc == 0 && uc == 0)
    {
        path[y] = 0;
        code[y] = code[y+1] = 0;
        cur->insert(encode(), tv, x, y, pid, 0);
        if(x == N-1 || y == M-1) return;
        if(lp || up) return;
        path[y] = 8;
        code[y] = code[y+1] = 7;
        cur->insert(encode(), tv+1, x, y, pid, 1);
    }
    else
        if(lc == 0 || uc == 0)
        {
            if(lc)
            {
                if(up) return;
                if(x < N-1)
                {
                    path[y] = 8;
                    code[y] = lc;
                    code[y+1] = 0;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
                if(y < M-1)
                {
                    path[y] = 8;
                    code[y] = 0;
                    code[y+1] = lc;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
            }
            else
            {
                if(lp) return;
                if(x < N-1)
                {
                    path[y] = 8;
                    code[y] = uc;
                    code[y+1] = 0;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
                if(y < M-1)
                {
                    path[y] = 8;
                    code[y] = 0;
                    code[y+1] = uc;
                    cur->insert(encode(), tv+1, x, y, pid, 1);
                }
            }
        }
        else
            if(lc != uc)
            {
                path[y] = 8;
                for(int i = 0; i <= M; ++i)
                    if(code[i] == uc) code[i] = lc;
                code[y] = code[y+1] = 0;
                cur->insert(encode(), tv+1, x, y, pid, 1);
            }
}
void solve()
{
    cur = hm;
    last = hm+1;
    last->init();
    last->insert(0, 0, 0, 0, 0, 0);
    for(int i = 0; i < N; ++i)
    {
        int sz = last->size;
        for(int j = 0; j < sz; ++j)
            last->state[j] <<= 4;
        for(int j = 0; j < M; ++j)
        {
            cur->init();
            sz = last->size;
            for(int k = 0; k < sz; ++k)
            {
                decode(last->state[k]);
                updata(i, j, last->value[k], k);
            }
            swap(cur, last);
        }
    }
    int ans = 0, id;
    for(int i = 0; i < last->size; ++i)
    {
        decode(last->state[i]);
        bool flag(true);
        for(int j = 0; j <= M; ++j)
            if(code[j])
            {
                flag = false;
                break;
            }
        if(flag)
        {
            if(last->value[i] > ans)
            {
                ans = last->value[i];
                id = i;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(mp[i][j] == '.')
                mp[i][j] = 'W';
    for(int i = N-1; i >= 0; --i)
        for(int j = M-1; j >= 0; --j)
        {
            if(mp[i][j] == 'W' && opt[i][j][id]) mp[i][j] = '.';
            id = pre[i][j][id];
        }
    printf("%d\n", ans);
    for(int i = 0; i < N; ++i)
        printf("%s\n", mp[i]);
    printf("\n");
}
int main()
{
    int TC, n_case(0);
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; ++i)
            scanf("%s", mp[i]);
        printf("Case %d: ", ++n_case);
        solve();
    }
    return 0;
}
