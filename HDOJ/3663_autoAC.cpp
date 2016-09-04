#include <iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
const int N = 61;
const int M = N * 15 * 6 * N + 10;
int n,m,D;
int s[M],h[M],u[M],d[M],l[M],r[M],col[M],row[M],ans[M],aans[N][3];
int num;
bool flag[N][N];
map<int,int>lcm;
bool vis[N];
bool ok;
int idx[6][6] = {
    {0,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,2,6,0,0,0},
    {0,3,7,10,0,0},
    {0,4,8,11,13,0},
    {0,5,9,12,14,15},
};
void init()
{
    int i,c;
    memset(h,0,sizeof(h));
    memset(s,0,sizeof(s));
    memset(vis,false,sizeof(vis));
    memset(flag,false,sizeof(flag));
    c = D * n;
    for(i = 0;i <= c;i ++)
    {
        u[i] = d[i] = i;
        l[i] = (i + c) % (c + 1);
        r[i] = (i + 1) % (c + 1);
    }
    num = c + 1;
    lcm.clear();
    lcm[1] = 11;
    lcm[2] = 12;lcm[6] = 22;
    lcm[3] = 13;lcm[7] = 23;lcm[10] = 33;
    lcm[4] = 14;lcm[8] = 24;lcm[11] = 34;lcm[13] = 44;
    lcm[5] = 15;lcm[9] = 25;lcm[12] = 35;lcm[14] = 45;lcm[15] = 55;
}
void insert(int i,int j)
{
    if(h[i])
    {
        r[num] = h[i];
        l[num] = l[h[i]];
        l[r[num]] = num;
        r[l[num]] = num;
    }
    else
        h[i] = l[num] = r[num] = num;
    s[j] ++;
    u[num] = u[j];
    d[num] = j;
    d[u[j]] = num;
    u[j] = num;
    col[num] = j;
    row[num] = i;
    num ++;
}
void remove(int x)
{
    int i,j;
    l[r[x]] = l[x];
    r[l[x]] = r[x];
    for(i = d[x];i != x;i = d[i])
        for(j = r[i];j != i;j = r[j])
        {
            u[d[j]] = u[j];
            d[u[j]] = d[j];
            s[col[j]] --;
        }
}
void resume(int x)
{
    int i,j;
    for(i = u[x];i != x;i = u[i])
        for(j = l[i];j != i;j = l[j])
        {
            s[col[j]] ++;
            u[d[j]] = d[u[j]] = j;
        }
    l[r[x]] = r[l[x]] = x;
}
void dfs(int k)
{
    if(ok)
        return;
    int i,j;
    if(!r[0])
    {
        ok = true;
        memset(aans,0,sizeof(aans));
        for(i = 0;i < k;i ++)
        {
            int ii = (ans[i] - 1)/15 + 1;
            int jj = ans[i] - (ii - 1) * 15;
            aans[ii][0] = lcm[jj]/10;
            aans[ii][1] = lcm[jj]%10;
        }
        for(i = 1;i <= n;i ++)
            printf("%d %d\n",aans[i][0],aans[i][1]);
        return;
    }
    int mx = M;
    int c;
    for(i = r[0];i;i = r[i])
    {
        if(s[i] < mx)
        {
            mx = s[i];
            c = i;
        }
    }
    remove(c);
    int tmp;
    for(i = d[c];i != c;i = d[i])
    {
        tmp = (row[i] - 1)/15 + 1;
        if(vis[tmp] == true)
            continue;
        vis[tmp] = true;
        ans[k] = row[i];
        for(j = r[i];j != i;j = r[j])
            remove(col[j]);
        dfs(k + 1);
        if(ok)
            return;
        for(j = l[i];j != i;j = l[j])
            resume(col[j]);
        vis[tmp] = false;
    }
    resume(c);
}
int main()
{
    int a,b,i,j,ii,jj,st,ed;
    while(scanf("%d",&n) != EOF)
    {
        scanf("%d%d",&m,&D);
        init();
        while(m --)
        {
            scanf("%d%d",&a,&b);
            flag[a][b] = flag[b][a] = true;
        }
        for(i = 1;i <= n;i ++)
            flag[i][i] = true;
        for(i = 1;i <= n;i ++)
        {
            scanf("%d%d",&st,&ed);
            int base = (i - 1) * 15;
            for(ii = st;ii <= ed;ii ++)
            {
                for(jj = st;jj <= ii;jj ++)
                {
                    for(j = 1;j <= n;j ++)
                        if(flag[i][j] == true)
                        {
                            for(int ai = jj;ai <= ii;ai ++)
                                insert(base + idx[ii][jj],(j - 1) * D + ai);
                        }
                }
            }
        }
        ok = false;
        dfs(0);
        if(ok == false)
            puts("No solution");
        puts("");
    }
    return 0;
}
