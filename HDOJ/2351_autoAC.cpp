#include <stack>
#include <cstdio>
#include <list>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 110;
const int MOD = 1e9 + 7;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef pair<int, int> pii;
struct NUM
{
    int sum, multiple, num, square, cube, quad;
}arr[MAXN];
void Handle(NUM &num)
{
    int tmp = num.num, curNum = num.num;
    int sum = 0, multiple = 1;
    while (tmp)
    {
        sum += tmp % 10;
        multiple *= tmp % 10;
        tmp /= 10;
    }
    num.sum = sum; num.multiple = multiple;
    num.square = curNum <= 1000 ? curNum*curNum : -1;
    num.quad = curNum <= 100 ? curNum*curNum*curNum*curNum : -1;
    num.cube = curNum <= 100 ? curNum*curNum*curNum : -1;
}
set<int> cube, square, quad;
int ansCnt;
void Init() 
{
    for (int i = 1; i <= 1000; i++)
    {
        square.insert(i*i);
        if (i <= 100) cube.insert(i*i*i), quad.insert(i*i*i*i);
    }
}
bool isPrime(int num)
{
    if (num == 1) return false;
    if (num == 2) return true;
    for (int i = 2; i <= (int)sqrt(num+0.5); i++)
        if (num % i == 0) return false;
    return true;
}
int n, cnt[MAXN];
void Solve(const int &cur)
{
    cnt[cur] = 0;
    int curNum = arr[cur].num;
    const NUM &num = arr[cur];
    for (int i = 0; i < n; i++)
    {
        if (i == cur) continue;
        NUM &k = arr[i];
        if (k.num % curNum == 0) cnt[cur]++;   
        if (curNum % k.num == 0) cnt[cur]++;    
        if (k.square == curNum) cnt[cur]++;    
        if (k.cube == curNum) cnt[cur]++;       
        if (k.quad == curNum) cnt[cur]++;       
        if (curNum % k.sum == 0) cnt[cur]++;        
        if (k.multiple != 0 && curNum % k.multiple == 0) cnt[cur]++;           
    }
    if (square.count(curNum)) cnt[cur]++;       
    if (cube.count(curNum)) cnt[cur]++;        
    if (quad.count(curNum)) cnt[cur]++;        
    if (curNum % num.sum == 0) cnt[cur]++;      
    if (num.multiple != 0 && curNum % num.multiple == 0) cnt[cur]++;   
    if (isPrime(curNum)) cnt[cur]++;    
    ansCnt = max(ansCnt, cnt[cur]);
}
int main()
{
    Init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ansCnt = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i].num);
            Handle(arr[i]);
        }
        for (int i = 0; i < n; i++) Solve(i);
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (ansCnt == cnt[i]) ans.PB(arr[i].num);
        sort(ans.begin(), ans.end());
        printf("DATA SET #%d\n", ++cases);
        for (int i = 0; i < SZ(ans); i++) printf("%d\n", ans[i]);
    }
    return 0;
}
