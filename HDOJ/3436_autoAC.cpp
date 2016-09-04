#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXD 100010
int N, Q, T, node, tx[MAXD], begin[MAXD], end[MAXD], nodep[MAXD];
int num[2 * MAXD], size[2 * MAXD], left[2 * MAXD], right[2 * MAXD], pre[2 * MAXD], key[2 * MAXD];
char b[MAXD][10];
int ob[MAXD];
int cmp(const void *_p, const void *_q)
{
    int *p = (int *)_p, *q = (int *)_q;
    return *p - *q;
}
void update(int cur)
{
    size[cur] = size[left[cur]] + size[right[cur]] + num[cur];
}
void newnode(int &cur, int k)
{
    cur = ++ node;
    size[cur] = num[cur] = end[k] - begin[k] + 1;
    key[cur] = k;
    nodep[k] = cur;
    left[cur] = right[cur] = 0;
}
void build(int &cur, int x, int y, int p)
{
    int mid = (x + y) / 2;
    newnode(cur, mid);
    pre[cur] = p;
    if(x == y)
        return ;
    if(x < mid)
        build(left[cur], x, mid - 1, cur);
    if(mid < y)
        build(right[cur], mid + 1, y, cur);
    update(cur);
}
void init()
{
    int i, j, k;
    scanf("%d%d", &N, &Q);
    k = 0;
    tx[k ++] = 0;
    for(i = 0; i < Q; i ++)
    {
        scanf("%s%d", b[i], &ob[i]);
        if(b[i][0] == 'T' || b[i][0] == 'Q')
            tx[k ++] = ob[i];
    }
    tx[k ++] = N;
    qsort(tx, k, sizeof(tx[0]), cmp);
    N = 0;
    for(i = 1; i < k; i ++)
        if(tx[i] != tx[i - 1])
        {
            if(tx[i] - tx[i - 1] > 1)
            {
                begin[N] = tx[i - 1] + 1, end[N] = tx[i] - 1;
                ++ N;
            }
            begin[N] = end[N] = tx[i];
            ++ N;
        }
    T = node = left[0] = right[0] = size[0] = num[0] = 0;
    build(T, 0, N - 1, 0);
}
void leftrotate(int x)
{
    int y = right[x], p = pre[x];
    right[x] = left[y];
    if(right[x])
        pre[right[x]] = x;
    left[y] = x;
    pre[x] = y;
    pre[y] = p;
    if(p == 0)
        T = y;
    else
        right[p] == x ? right[p] = y : left[p] = y;
    update(x);
}
void rightrotate(int x)
{
    int y = left[x], p = pre[x];
    left[x] = right[y];
    if(left[x])
        pre[left[x]] = x;
    right[y] = x;
    pre[x] = y;
    pre[y] = p;
    if(p == 0)
        T = y;
    else
        right[p] == x ? right[p] = y : left[p] = y;
    update(x);
}
void splay(int x, int goal)
{
    int y, z;
    for(;;)
    {
        if((y = pre[x]) == goal)
            break;
        if((z = pre[y]) == goal)
            right[y] == x ? leftrotate(y) : rightrotate(y);
        else
        {
            if(right[z] == y)
            {
                if(right[y] == x)
                    leftrotate(z), leftrotate(y);
                else
                    rightrotate(y), leftrotate(z);
            }
            else
            {
                if(left[y] == x)
                    rightrotate(z), rightrotate(y);
                else
                    leftrotate(y), rightrotate(z);
            }
        }
    }
    update(x);
}
int BS(int x)
{
    int max, mid, min;
    min = 0, max = N;
    for(;;)
    {
        mid = (max + min) / 2;
        if(mid == min)
            break;
        if(begin[mid] <= x)
            min = mid;
        else
            max = mid;
    }
    return mid;
}
int Delete(int &cur, int p)
{
    int k;
    if(cur == T || right[cur] == 0)
    {
        if(cur == T)
        {
            k = Delete(left[cur], cur);
            left[k] = left[T], right[k] = right[T];
            if(left[k])
                pre[left[k]] = k;
            if(right[k])
                pre[right[k]] = k;
            T = k;
            pre[T] = 0;
            update(T);
        }
        else
        {
            k = cur;
            if(left[k])
                pre[left[k]] = p;
            cur = left[k];
        }
        return k;
    }
    else
    {
        k = Delete(right[cur], cur);
        update(cur);
        return k;
    }
}
void Insert(int &cur, int k, int p)
{
    if(cur == 0)
    {
        newnode(cur, k);
        pre[cur] = p;
        return ;
    }
    Insert(left[cur], k, cur);
    update(cur);
}
void Top(int x)
{
    int k, cur;
    k = BS(x);
    cur = nodep[k];
    splay(cur, 0);
    if(left[T] == 0 || right[T] == 0)
    {
        T = left[T] + right[T];
        pre[T] = 0;
    }
    else
        Delete(T, 0);
    Insert(T, k, 0);
    splay(node, 0);
}
void Query(int x)
{
    int k, cur;
    k = BS(x);
    cur = nodep[k];
    splay(cur, 0);
    printf("%d\n", size[left[cur]] + 1);
}
int Search(int cur, int x)
{
    int ls = left[cur], rs = right[cur], k = key[cur];
    if(x <= size[ls])
        return Search(left[cur], x);
    else if(x <= size[ls] + num[cur])
        return begin[k] + (x - size[ls]) - 1;
    else
        return Search(right[cur], x - size[ls] - num[cur]);
}
void Rank(int x)
{
    printf("%d\n", Search(T, x));
}
void solve()
{
    int i, j, k;
    for(i = 0; i < Q; i ++)
    {
        if(b[i][0] == 'T')
            Top(ob[i]);
        else if(b[i][0] == 'Q')
            Query(ob[i]);
        else
            Rank(ob[i]);
    }
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        init();
        printf("Case %d:\n", tt + 1);
        solve();
    }
    return 0;
}
