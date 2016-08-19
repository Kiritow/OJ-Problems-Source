#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 3005
struct Tree
{
    int l, r;
} tree[maxn];
char st1[maxn], st2[maxn], temp[maxn], st[maxn];
bool operator<(const Tree &a, const Tree &b)
{
    int len = min(a.r - a.l, b.r - b.l);
    for (int i =0; i < len; i++)
        if (st[a.l + i] != st[b.l + i])
            return st[a.l + i] < st[b.l + i];
    return a.r - a.l < b.r - b.l;
}
void make(int l, int r, Tree *tree)
{
    int zcount =0;
    int tcount =0;
    int s = l;
    for (int i = l; i < r; i++)
    {
        if (st[i] =='0')
            zcount++;
        else
            zcount--;
        if (zcount ==0)
        {
            make(s +1, i, &tree[tcount]);
            tree[tcount].l = s;
            tree[tcount].r = i +1;
            tcount++;
            s = i +1;
        }
    }
    sort(tree, tree + tcount);
    s = l;
    for (int i =0; i < tcount; i++)
    {
        for (int j = tree[i].l; j < tree[i].r; j++)
            temp[j - tree[i].l + s] = st[j];
        s += tree[i].r - tree[i].l;
    }
    for (int i = l; i < r; i++)
        st[i] = temp[i];
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        gets(st);
        make(0, strlen(st), tree);
        strcpy(st1, st);
        gets(st);
        make(0, strlen(st), tree);
        strcpy(st2, st);
        if (strcmp(st1, st2) ==0)
            printf("same\n");
        else
            printf("different\n");
    }
    return 0;
}
