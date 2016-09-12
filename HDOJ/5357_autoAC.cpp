#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
template<class Num>void read(Num &x)
{
    char c; int flag = 1;
    while((c = getchar()) < '0' || c > '9')
        if(c == '-') flag *= -1;
    x = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        x = (x<<3) + (x<<1) + (c-'0');
    x *= flag;
    return;
}
template<class Num>void write(Num x)
{
    if(x < 0) putchar('-'), x = -x;
    static char s[20];int sl = 0;
    while(x) s[sl++] = x%10 + '0',x /= 10;
    if(!sl) {putchar('0');return;}
    while(sl) putchar(s[--sl]);
}
const int maxn = 1e6 + 50, Mod = 1e9+7;
char str[maxn];
int T, n, a[maxn], b[maxn];
int pre[maxn], match[maxn];
long long ans[maxn];
int stack[maxn], top;
void prework()
{
    top = 0;
    for(int i = 1; i <= n; i++)
    {
        match[i] = pre[i] = 0;
        if(str[i] == '(')
            stack[++top] = i;
        else
        {
            if(top)
            {
                match[stack[top]] = i;
                match[i] = stack[top];
                if(top > 1) pre[match[i]] = stack[top - 1];
                stack[top--] = 0;
            }
        }
    }
}
void solve()
{
    a[0] = b[n + 1] = ans[0] = 0;
    for(int i = 1; i <= n; i++)
        a[i] = (str[i] == ')' && match[i])?(a[match[i] - 1] + 1):0;
    for(int i = n; i >= 1; i--)
        b[i] = (str[i] == '(' && match[i])?(b[i] = b[match[i] + 1] + 1):0;
    for(int i = 1; i <= n; i++)
         ans[i] = (str[i] == '(')?(ans[pre[i]] + ((long long)b[i]*a[match[i]] % Mod) % Mod):ans[match[i]];  
}
long long calcu()
{
    long long tot = 0;
    for(int i = 1; i <= n; i++)
        tot = tot + ans[i]*i % Mod;
    return tot; 
}
int main()
{
    read(T);
    while(T--)
    {
        scanf("%s", str + 1);
        n = strlen(str + 1);
        prework(), solve();
        write(calcu()), puts("");
    }
    return 0;            
}
