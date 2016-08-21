#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<string>
#include<vector>
#include<queue>
#include<list>
using namespace std;
typedef long long lld;
typedef unsigned int ud;
#define INF_MAX 0x3f3f3f3f
#define eatline() char chch;while((chch=getchar())!='\n')continue;
#define MemsetMax(a) memset(a,0x3f,sizeof a)
#define MemsetZero(a) memset(a,0,sizeof a)
#define MemsetMin(a) memset(a,-1,sizeof a)
#define MemsetFalse(a) MemsetZero(a)
#define PQ priority_queue
#define Q queue
#define maxn 100005
#define maxm 1000005
int c[maxn];
int Rank[maxm];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &Rank[i]);
        sort(Rank + 1, Rank + 1 + m);
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= Rank[i]; j++)
            {
                if (c[j] > 0)
                {
                    c[j]--;
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
