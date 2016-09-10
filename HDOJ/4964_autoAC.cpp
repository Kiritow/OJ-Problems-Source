#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
char str[100], ans[10010];
int len;
int getmatch(int l)
{
    int p = 1;
    for (int r = l + 1; ; r++)
    {
        if (str[r] == '(') p++;
        else if (str[r] == ')') p--;
        if (p == 0) return r;
    }
}
string getStr(int &w)
{
    string ret = "";
    while (islower(str[w]) or isupper(str[w]) or isdigit(str[w]))
        ret += str[w++];
    return ret;
}
void getHtmltag(int &w, string &s1, string &s2)
{
    string name = "", id = "", cla = "";
    name = getStr(w);           
    while (str[w] == '#' || str[w] == '.')
    {
        if (str[w] == '#') id = getStr(++w);
        else
        {
            if (cla != "") cla += ' ';
            cla += getStr(++w);
        }
    }
    s1 = "<" + name;
    if (id != "")
        s1 += " id=\""+ id + "\"";
    if (cla != "")
        s1 += " class=\""+ cla + "\"";
    s1 += ">";
    s2 = "</" + name + ">";
}
string solve(int l, int r)
{
    if (l > r) return "";
    if (str[l] == '(')         
    {
        int k = getmatch(l);
        return solve(l + 1, k - 1) + solve(k + 1, r);
    }
    else
    {
        string s1, s2, s3, ret;
        getHtmltag(l, s1, s2);
        int k = 0;
        if (str[l] == '*')
        {
            l++;
            while (isdigit(str[l]))
                k = k * 10 + str[l++] - '0';
        }
        else k = 1;
        s3 = solve(l + 1, r);      
        ret = "";
        while (k--)
            ret += s1 + s3 + s2;
        return ret;
    }
}
int main()
{
    int T;
    read(T);
    while (T --)
    {
        scanf("%s", str);
        cout<<solve(0, strlen(str) - 1)<<endl;
    }
    return 0;
}
