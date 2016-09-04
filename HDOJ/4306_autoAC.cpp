#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 305;
const int MAXM = 100010;
struct Edge
{
    int v, next;
} shift[MAXN*MAXN*2], edge[MAXN*MAXN*4];
int shiftNumber, edgeNumber;
int shiftHead[MAXN*MAXN*2], edgeHead[MAXN*MAXN*2];
int a[MAXN][MAXN], b[MAXN][MAXN];
int al[MAXN*MAXN], bl[MAXN*MAXN];
int ta[MAXN], tb[MAXN];
int na[MAXM], nb[MAXM];
int pa[MAXM][2], pb[MAXM][2];
bool va[MAXM], vb[MAXM];
int n, nn, ca, cb;
int differ[MAXN*MAXN], differNumber;
int maxNumber;
bool inStack[MAXN*MAXN*2];
int dfn[MAXN*MAXN*2], low[MAXN*MAXN*2];
int stack[MAXN*MAXN*2], belong[MAXN*MAXN*2];
int top, index, componentNumber;
inline int min(int x, int y)
{
    return x < y ? x : y;
}
inline int max(int x, int y)
{
    return x > y ? x : y;
}
inline void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
inline int getPosition(int x, int y)
{
    return x * n + y;
}
inline int getRow(int pos)
{
    return pos / n;
}
inline int getColumn(int pos)
{
    return pos % n;
}
void clearEdges()
{
    shiftNumber = 0;
    edgeNumber = 0;
    memset(shiftHead, -1, sizeof(shiftHead));
    memset(edgeHead, -1, sizeof(edgeHead));
}
inline void addShift(int u, int v)
{
    shift[shiftNumber].v = v;
    shift[shiftNumber].next = shiftHead[u];
    shiftHead[u] = shiftNumber ++;
}
inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = edgeHead[u];
    edgeHead[u] = edgeNumber ++;
}
void transpose()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            swap(a[i][j], a[j][i]);
            swap(b[i][j], b[j][i]);
        }
    }
}
void getDifference()
{
    differ[al[0]] = 0;
    differNumber = 1;
    for(int i=1; i<nn; ++i)
    {
        if(al[i] != al[i-1])
        {
            differ[al[i]] = differNumber ++;
        }
    }
}
void getNumberPosition()
{
    memset(na, 0, sizeof(na));
    memset(nb, 0, sizeof(nb));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            pa[a[i][j]][na[a[i][j]]++] = getPosition(i, j);
            pb[b[i][j]][nb[b[i][j]]++] = getPosition(i, j);
        }
    }
}
bool isUnreachable()
{
    sort(al, al + nn);
    sort(bl, bl + nn);
    for(int i=0; i<nn; ++i)
    {
        if(al[i] != bl[i])
        {
            return true;
        }
    }
    return false;
}
bool isReachableByOneStep()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            ta[j] = a[i][j];
            tb[j] = b[i][j];
        }
        sort(ta, ta + n);
        sort(tb, tb + n);
        for(int j=0; j<n; ++j)
        {
            if(ta[j] != tb[j])
            {
                return false;
            }
        }
    }
    return true;
}
int myStack[MAXN * MAXN * 8];
int myStackTop;
void push(int x)
{
    myStack[myStackTop ++] = x;
}
int pop()
{
    return myStack[-- myStackTop];
}
bool isEmpty()
{
    return myStackTop == 0;
}
void dfs(int x, int depth)
{
    int i, t;
    myStackTop = 0;
start:
    dfn[x] = low[x] = index ++;
    inStack[x] = true;
    stack[top++] = x;
    for(i=edgeHead[x]; i!=-1; i=edge[i].next)
    {
        if(dfn[edge[i].v] == -1)
        {
            push(x);
            push(depth);
            push(i);
            push(t);
            x = edge[i].v;
            depth = depth + 1;
            goto start;
ret:
            low[x] = min(low[x], low[edge[i].v]);
        }
        else if(inStack[edge[i].v])
        {
            low[x] = min(low[x] ,dfn[edge[i].v]);
        }
    }
    if(dfn[x] == low[x])
    {
        do
        {
            t = stack[--top];
            inStack[t] = false;
            belong[t] = componentNumber;
        }
        while(t != x);
        ++ componentNumber;
    }
    if(isEmpty())
    {
        return;
    }
    t = pop();
    i = pop();
    depth = pop();
    x = pop();
    goto ret;
}
void tarjan()
{
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    top = index = componentNumber = 0;
    for(int i=0; i<differNumber*2; ++i)
    {
        if(dfn[i] == -1)
        {
            dfs(i, 0);
        }
    }
}
bool isReachableByTwoStep()
{
    clearEdges();
    for(int i=1; i<=maxNumber; ++i)
    {
        if(na[i] == 1)
        {
            addShift(getPosition(getRow(pa[i][0]), getColumn(pb[i][0])), differ[i]<<1);
            addShift(getPosition(getRow(pa[i][0]), getColumn(pb[i][0])), (differ[i]<<1) + 1);
        }
        else if(na[i] == 2)
        {
            addShift(getPosition(getRow(pa[i][0]), getColumn(pb[i][1])), differ[i]<<1);
            addShift(getPosition(getRow(pa[i][0]), getColumn(pb[i][0])), (differ[i]<<1) + 1);
            addShift(getPosition(getRow(pa[i][1]), getColumn(pb[i][0])), differ[i]<<1);
            addShift(getPosition(getRow(pa[i][1]), getColumn(pb[i][1])), (differ[i]<<1) + 1);
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            for(int k=shiftHead[getPosition(i, j)]; k!=-1; k=shift[k].next)
            {
                for(int l=shift[k].next; l!=-1; l=shift[l].next)
                {
                    if((shift[k].v ^ 1) == shift[l].v)
                    {
                        continue;
                    }
                    addEdge(shift[k].v, shift[l].v ^ 1);
                    addEdge(shift[l].v, shift[k].v ^ 1);
                }
            }
        }
    }
    tarjan();
    for(int i=0; i<differNumber; ++i)
    {
        if(belong[i<<1] == belong[(i<<1)+1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1; cas<=caseNumber; ++cas)
    {
        scanf("%d%d%d", &n, &ca, &cb);
        nn = n * n;
        bool isSame = true;
        maxNumber = 0;
        for(int i=0,k=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                scanf("%d", &a[i][j]);
                al[k++] = a[i][j];
                maxNumber = max(maxNumber, a[i][j]);
            }
        }
        for(int i=0,k=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                scanf("%d", &b[i][j]);
                bl[k++] = b[i][j];
                if(a[i][j] != b[i][j])
                {
                    isSame = false;
                }
            }
        }
        printf("Case #%d: ", cas);
        if(isSame)
        {
            printf("0\n");
        }
        else
        {
            if(isUnreachable())
            {
                printf("Take off the shoes!\n");
            }
            else
            {
                int ans = min(ca * 2 + cb, cb * 2 + ca);
                if(isReachableByOneStep())
                {
                    ans = ca;
                }
                transpose();
                if(ans > cb)
                {
                    if(isReachableByOneStep())
                    {
                        ans = cb;
                    }
                }
                if(ans > ca + cb)
                {
                    getDifference();
                    getNumberPosition();
                    if(isReachableByTwoStep())
                    {
                        ans = ca + cb;
                    }
                    else
                    {
                        transpose();
                        getNumberPosition();
                        if(isReachableByTwoStep())
                        {
                            ans = ca + cb;
                        }
                    }
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
