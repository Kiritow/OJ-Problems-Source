#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct item
{
    int num[4];
} a, b;
int prime[100], primenum, cost[10000];
int toint(item &a)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans = ans * 10 + a.num[i];
    return ans;
}
void makeprime()
{
    primenum = 1;
    prime[0] = 2;
    for (int i = 3; i < 100; i++)
    {
        bool ok = true;
        for (int j = 0; prime[j] * prime[j] <= i; j++)
            if (i % prime[j] == 0)
            {
                ok = false;
                break;
            }
        if (ok)
        {
            prime[primenum++] = i;
        }
    }
}
void init()
{
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < 4; i++)
    {
        char ch;
        scanf("%c", &ch);
        a.num[i] = ch - '0';
    }
    getchar();
    for (int i = 0; i < 4; i++)
    {
        char ch;
        scanf("%c", &ch);
        b.num[i] = ch - '0';
    }
    getchar();
}
bool isprime(int a)
{
    for (int i = 0; i < primenum && prime[i] * prime[i] <= a; i++)
        if (a % prime[i] == 0)
            return false;
    return true;
}
void work()
{
    cost[toint(a)] = 0;
    queue<item> q;
    q.push(a);
    while (!q.empty())
    {
        item temp = q.front();
        int costnow = cost[toint(temp)];
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = temp.num[i];
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (j == x)
                    continue;
                temp.num[i] = j;
                int inttemp = toint(temp);
                if (cost[inttemp] == -1 && isprime(inttemp))
                {
                    cost[inttemp] = costnow + 1;
                    if (inttemp == toint(b))
                    {
                        printf("%d\n", cost[inttemp]);
                        return;
                    }
                    q.push(temp);
                }
            }
            temp.num[i] = x;
        }
    }
}
int main()
{
    int t;
    makeprime();
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        init();
        if (toint(a) == toint(b))
            printf("0\n");
        work();
    }
    return 0;
}
