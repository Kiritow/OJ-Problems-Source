#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#define LL long long
#define _LL __int64
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
char map[17][17];
int sta[17],tmp[17];
int bit[17];
int ans;
void cal()
{
    bit[0] = 1;
    for(int i = 1; i < 17; i++)
        bit[i] = (bit[i-1] << 1);
}
void input()
{
    memset(sta,0,sizeof(sta)); 
    if(n >= m)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s",map[i]);
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] == 'X')
                    sta[i] = (sta[i] << 1) + 1;
                else sta[i] <<= 1;
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s",map[i]);
            for(int j = 0; j < m; j++)
            {
                if(map[i][j] == 'X')
                    sta[j] = (sta[j] << 1) + 1;
                else sta[j] <<= 1;
            }
        }
        swap(n,m);
    }
}
void solve()
{
    int step;
    ans = INF;
    for(int i = 0; i < (1<<m); i++)
    {
        memcpy(tmp,sta,sizeof(sta));
        step = 0;
        for(int j = 0; j < m && step < ans; j++)
        {
            if(bit[j]&i)
            {
                step++;
                if(j > 0)
                    tmp[0] ^= bit[j-1];
                if(j < m-1)
                    tmp[0] ^= bit[j+1];
                tmp[0] ^= bit[j];
                tmp[1] ^= bit[j];
            }
        }
        for(int j = 1; j < n && step < ans; j++)
        {
            for(int k = 0; k < m && step < ans; k++)
            {
                if(bit[k]&tmp[j-1])
                {
                    step++;
                    if(k > 0)
                        tmp[j] ^= bit[k-1];
                    if(k < m-1)
                        tmp[j] ^= bit[k+1];
                    tmp[j] ^= bit[k];
                    tmp[j+1] ^= bit[k];
                }
            }
        }
        if(!tmp[n-1])
            ans = min(ans,step);
    }
}
int main()
{
    cal();
    while(~scanf("%d %d",&n,&m))
    {
        if(n == 0 && m == 0) break;
        input();
        solve();
        if(ans == INF)
            printf("Damaged billboard.\n");
        else printf("You have to tap %d tiles.\n",ans);
    }
    return 0;
}
