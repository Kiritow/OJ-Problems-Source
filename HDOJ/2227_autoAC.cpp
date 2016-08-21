#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100000+10;
const int mod = 1000000007;
int c[maxn];
int n;
struct Node{
    int value; 
    int index; 
}node[maxn];
bool cmp(Node a, Node b)
{
    if(a.value == b.value) return a.index < b.index;
    else return a.value < b.value;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int index, int value) 
{
    while(index <= n)
    {
        c[index] = (c[index]+value) % mod;
        index += lowbit(index);
    }
}
int sum(int index) 
{
    int ret = 0;
    while(index > 0)
    {
        ret = (ret+c[index])%mod;
        index -= lowbit(index);
    }
    return ret;
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(node, 0, sizeof(node));
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &node[i].value);
            node[i].index = i;
        }
        sort(node+1, node+n+1, cmp); 
        int tmp = 0;
        for(int i = 1; i <= n; i++)
        {
            tmp = sum(node[i].index)+1; 
            tmp %= mod;
            add(node[i].index, tmp); 
        }
        printf("%d\n", sum(n));
    }
    return 0;
}
