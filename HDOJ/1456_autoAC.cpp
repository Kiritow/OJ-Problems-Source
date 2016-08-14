#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
struct Order
{
    int s;
    int e;
    int p;
}ord[23];
int n, NumB, NumOrd;
int MaxEarn, CurEarn, off[8];
int cmp (const void *aa, const void *bb)
{
    struct Order *a=(Order*) aa;
    struct Order *b=(Order*) bb;
    if(a -> s != b -> s) return a -> s - b -> s;
    else return a -> e - a -> e;
}
void DFS (int num,int tolp)
{
    if (num == NumOrd)
    {
        if (MaxEarn < CurEarn) MaxEarn = CurEarn;
        return ;
    }
    else
    {
        if (num > 0)
            for (int i = ord[num - 1].s + 1; i <= ord[num].s; i++)
            {
                tolp -= off[i];
            }
        tolp += ord[num].p;
        if (tolp <= n)
        {
            CurEarn += (ord[num].e - ord[num].s) * ord[num].p;
            off[ord[num].e] += ord[num].p;
            DFS(num + 1, tolp);
            CurEarn -= (ord[num].e - ord[num].s) * ord[num].p;
            off[ord[num].e] -= ord[num].p;
        }
        tolp -= ord[num].p; 
        DFS (num + 1, tolp);
    }
    return ;
}
int main()
{
    while (scanf("%d %d %d", &n, &NumB, &NumOrd) && (n || NumB || NumOrd))
    {
        memset(off, 0, sizeof(off));
        MaxEarn = 0; CurEarn = 0;
        for (int i = 0; i < NumOrd; i++)
        {
            scanf("%d %d %d", &ord[i].s, &ord[i].e, &ord[i].p);
        }
        qsort (ord, NumOrd, sizeof(ord[0]), cmp);
        DFS(0,0);
        printf("%d\n", MaxEarn);
    }
    return 0;
}
