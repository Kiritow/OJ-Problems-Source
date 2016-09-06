#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define D(x)
const int MAX_CHILD_NUM = 26;
const int MAX_NODE_NUM = 3 * (int)1e5 + 10;
const int MAX_LEN = 3 * (int)1e5 + 10;
const int MAX_N = 2 * (int)1e4 + 10;
#define MAX_EDGE_NUM MAX_NODE_NUM * 2
struct Edge
{
    int v, next;
    Edge()
    {}
    Edge(int v, int next):v(v), next(next)
    {}
} edge[MAX_EDGE_NUM];
int head[MAX_NODE_NUM];
int edge_cnt;
void init_edge()
{
    memset(head, -1, sizeof(head));
    edge_cnt = 0;
}
void add_edge(int u, int v)
{
    edge[edge_cnt] = Edge(v, head[u]);
    head[u] = edge_cnt++;
}
struct Trie
{
    int next[MAX_NODE_NUM][MAX_CHILD_NUM];
    int fail[MAX_NODE_NUM];
    int count[MAX_NODE_NUM];
    int node_cnt;
    int root;
    bool vis[MAX_NODE_NUM]; //set it to false
    void init()
    {
        node_cnt = 0;
        root = newnode();
    }
    int newnode()
    {
        for (int i = 0; i < MAX_CHILD_NUM; i++)
            next[node_cnt][i] = -1;
        count[node_cnt++] = 0;
        return node_cnt - 1;
    }
    int get_id(char a)
    {
        return a - 'a';
    }
    void insert(char buf[], int index)
    {
        int now = root;
        for (int i = 0; buf[i]; i++)
        {
            int id = get_id(buf[i]);
            if (next[now][id] == -1)
                next[now][id] = newnode();
            now = next[now][id];
        }
        count[now] = index;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for (int i = 0; i < MAX_CHILD_NUM; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < MAX_CHILD_NUM; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void build_fail_tree()
    {
        init_edge();
        for (int i = 1; i < node_cnt; i++)
        {
            add_edge(i, fail[i]);
            add_edge(fail[i], i);
        }
    }
}ac;
const int MAX_INTERVAL = MAX_LEN;
struct SegmentTree
{
    struct Node
    {
        int l, r;
        Node *pleft, *pright;
        int value;
    }tree[MAX_INTERVAL *4];
    int node_cnt;
    void init()
    {
        node_cnt = 0;
    }
    Node* new_node()
    {
        node_cnt++;
        return tree + node_cnt;
    }
    void build_tree(Node *proot, int s, int e)
    {
        proot->l = s;
        proot->r = e;
        proot->value = 0;
        if (s == e)
        {
            proot->pleft = proot->pright = NULL;
            return;
        }
        int mid = (s + e) / 2;
        build_tree(proot->pleft = new_node(), s, mid);
        build_tree(proot->pright = new_node(), mid + 1, e);
    }
    void pull_up(Node *proot)
    {
    }
    void push_down(Node *proot)
    {
    }
    void update(Node *proot, int start, int end, int value)
    {
        if (start > proot->r || end < proot->l)
            return;
        start = max(start, proot->l);
        end = min(end, proot->r);
        if (start == proot->l && end == proot->r)
        {
            proot->value = max(proot->value, value);
            return;
        }
        push_down(proot);
        update(proot->pleft, start, end, value);
        update(proot->pright, start, end, value);
        pull_up(proot);
    }
    int query(Node *proot, int start, int end)
    {
        int ret = proot->value;
        if (start > proot->r || end < proot->l)
            return 0;
        start = max(start, proot->l);
        end = min(end, proot->r);
        if (start == proot->l && end == proot->r)
        {
            return ret;
        }
        push_down(proot);
        ret = max(ret, query(proot->pleft, start, end));
        ret = max(ret, query(proot->pright, start, end));
        pull_up(proot);
        return ret;
    }
}tree;
char st[MAX_LEN];
int pos[MAX_N];
int dfn[MAX_LEN][2];
int dfn_cnt;
int n;
int weight[MAX_N];
void dfs(int u, int parent)
{
    dfn[u][0] = ++dfn_cnt;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != parent)
        {
            dfs(v, u);
        }
    }
    dfn[u][1] = dfn_cnt;
}
int work()
{
    int ret = 0;
    tree.init();
    tree.build_tree(tree.tree, 0, dfn_cnt);
    for (int i = 0; i < n; i++)
    {
        int u = ac.root;
        int temp = 0;
        for (int j = pos[i]; j < pos[i + 1]; j++)
        {
            u = ac.next[u][ac.get_id(st[j])];
            temp = max(temp, tree.query(tree.tree, dfn[u][0], dfn[u][0]) + weight[i]);
        }
        tree.update(tree.tree, dfn[u][0], dfn[u][1], temp);
        ret = max(ret, temp);
    }
    return ret;
}
void input()
{
    scanf("%d", &n);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", st + temp, &weight[i]);
        pos[i] = temp;
        ac.insert(st + temp, i);
        int len = strlen(st + temp);
        temp += len;
    }
    pos[n] = temp;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        ac.init();
        input();
        ac.build();
        ac.build_fail_tree();
        dfn_cnt = 0;
        dfs(0, -1);
        printf("Case #%d: %d\n", i, work());
    }
    return 0;
}
