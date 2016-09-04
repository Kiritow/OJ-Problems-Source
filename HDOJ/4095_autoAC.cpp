#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
const int N = 100005;
typedef __int64 ll;
struct node
{
    int l,r,f,key,value;
    friend bool operator <(const struct node a,const struct node b)
    {
        return a.key < b.key;
    }
}lcm[N];
int n,m,root,num,maxdp;
int stack[N];
int dep[N];
int head[N];
struct nd
{
    int to,next;
}g[N];
void add(int s,int e)
{
    g[num].to = e;
    g[num].next = head[s];
    head[s] = num ++;
}
int build()
{
    int top = -1;
    int i,j;
    top = -1;
    for(i = 1;i <= n;i ++)
    {
        j = top;
        while(j >= 0 && lcm[stack[j]].value > lcm[i].value)
            j --;
        if(j != -1)
        {
            lcm[i].f = stack[j];
            lcm[stack[j]].r = i;
        }
        if(j < top)
        {
            lcm[stack[j + 1]].f = i;
            lcm[i].l = stack[j + 1];
        }
        stack[++ j] = i;
        top = j;
    }
    lcm[stack[0]].f = -1;
    return stack[0];
}
void bfs(int root,int dp)
{
    int front,rear;
    front = rear = 0;
    dep[root] = dp;
    add(dp,root);
    stack[rear ++] = root;
    while(front != rear)
    {
        int cur = stack[front ++];
        if(lcm[cur].l > 0)
        {
            dep[lcm[cur].l] = dep[cur] + 1;
            add(dep[cur] + 1,lcm[cur].l);
            stack[rear ++] = lcm[cur].l;
            if(maxdp < dep[cur] + 1)
                maxdp = dep[cur] + 1;
        }
        if(lcm[cur].r > 0)
        {
            dep[lcm[cur].r] = dep[cur] + 1;
            add(dep[cur] + 1,lcm[cur].r);
            stack[rear ++] = lcm[cur].r;
            if(maxdp < dep[cur] + 1)
                maxdp = dep[cur] + 1;
        }
    }
}
char ans[205][N + 205];
void print(ll l,ll r,ll u,ll d)
{
    ll i,j,k;
    for(i = u;i <= d;i ++)
    {
        memset(ans[i - u],0,sizeof(ans[i - u]));
        if(i & 1)
        {
            for(j = head[(i + 1)>>1];~j;j = g[j].next)
            {
                ans[i - u][g[j].to] = 'o';
                if(lcm[g[j].to].l != -1)
                {
                    ans[i - u][lcm[g[j].to].l] = '+';
                    for(k = lcm[g[j].to].l + 1;k < g[j].to;k ++)
                        ans[i - u][k] = '-';
                }
                if(lcm[g[j].to].r != -1)
                {
                    ans[i - u][lcm[g[j].to].r] = '+';
                    for(k = lcm[g[j].to].r - 1;k > g[j].to;k --)
                        ans[i - u][k] = '-';
                }
            }
        }
        else
        {
            for(j = head[i>>1];~j;j = g[j].next)
            {
                if(lcm[g[j].to].l != -1)
                    ans[i - u][lcm[g[j].to].l] = '|';
                if(lcm[g[j].to].r != -1)
                    ans[i - u][lcm[g[j].to].r] = '|';
            }
        }
    }
    for(i = 0;i <= d - u;i ++)
    {
        bool fuck = false;
        for(j = l;j <= r;j ++)
            if(ans[i][j])
            {
                fuck = true;
                break;
            }
        if(fuck == false)
            continue;
        for(j = l;j <= r;j ++)
            if(ans[i][j])
                putchar(ans[i][j]);
            else
                putchar(' ');
        putchar(10);
    }
}
void rush()
{
    ll l,r,u,d;
    scanf("%d",&m);
    while(m --)
    {
        scanf("%I64d%I64d%I64d%I64d",&u,&l,&d,&r);
        d = u + d - 1;
        r = l + r - 1;
        if(d > maxdp + maxdp-1)
            d = maxdp + maxdp-1;
        print(l,r,u,d);
        printf("\n");
    }
}
int main()
{
    int i,t,cas = 0;
    scanf("%d",&t);
    while(t --)
    {
        scanf("%d",&n);
        for(i = num = 1;i <= n;i ++)
        {
            lcm[i].l = lcm[i].r = lcm[i].f = -1;
            head[i] = -1;
            scanf("%d",&lcm[i].key);
            lcm[i].value = i;
        }
        sort(lcm + 1,lcm + 1 + n);
        root = build();
        maxdp = 1;
        bfs(root,1);
        printf("Case #%d:\n",++cas);
        rush();
    }
    return 0;
}
