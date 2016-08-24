#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 22;
long long base[MAX_N];
void makeBase()
{
    base[0] = 1;
    for (int i = 1; i <= 18; ++i)
        base[i] = base[i-1] * 10;
}
bool dfs (long long n, int k);
bool test (long long n, int k, int nPart, long long curSum) 
{
    if (nPart == k)
        return ! dfs (curSum+n, k);      
    for (int i = 1; i < 20; ++i)
    {
        long long a = n % base[i];
        long long b = n / base[i];
        if (b == 0) break;
        if (test(b, k, nPart+1, curSum+a))
            return true;
    }
    return false;
}
bool dfs (long long n, int k)
{
    if (n < base[k-1]) return false;
    else return test(n, k, 1, 0);
}
int main ()
{
    makeBase();
    int k;
    long long n;
    while (cin >> n >> k)
        cout << dfs(n, k) << endl;
    return 0;
}
