#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
inline int getflen(int n) {
    int t = (int)ceil(n / 2.0);
    return n - t + 1;
}
inline int getslen(int n) {
    int s1 = n % 2 == 0 ? (n - 1) : n;
    int t1 = (int)floor(n/3.0 + 1/3.0) * 2 + 1;
    int ans = (s1 - t1) / 2 + 1;
    int s2 = (int)floor(n / 2.0 + 1 / 2.0) - 1;
    int t2 = (int)ceil(n/3.0);
    ans += s2 - t2 + 1;
    return ans;
}
inline int gettlen(int n) {
    int s1 = n;
    while(s1 % 3 == 0) {
        s1--;
    }
    int t1 = (int)floor(n/4.0 + 1/4.0) * 3 + 2;
    int s3 = s1 - 1;
    int t3 = (int)floor(n/4.0 + 1/4.0) * 3 + 1;
    int s2 = (int)floor(n/3.0 + 1/3.0) * 2 - 1;
    int t2 = (int)floor(n/4.0 + 1/4.0) * 2 + 1;
    int s4 = (int)ceil(n/3.0) - 1;
    int t4 = (int)ceil(n/4.0);
    int ans = 0;
    if(s1 % 3 == 1) {
        ans += 2;
        s1 -= 2;
        s3 -= 2;
        s4 -= 1;
    }
    ans += (s1 - t1) / 3 + 1;
    ans += (s3 - t3) / 3 + 1;
    ans += (s2 - t2) / 2 + 1;
    ans += s4 - t4 + 1;
    return ans;
}
inline void get_f(int n, int k, int &a, int &b) {
    a = 1;
    b = n - k + 1;
}
inline void get_s(int n, int k, int &a, int &b) {
    int s1 = n % 2 == 0 ? (n - 1) : n;
    int s2 = (int)floor(n / 2.0 + 1 / 2.0);
    if(k % 2 == 1) {
        a = 2;
        b = s1 - k + 1;
    }else {
        a = 1;
        b = s2 - k / 2;
    }
}
inline void get_t(int n, int k, int &a, int &b) {
    int s1 = n;
    while(s1 % 3 == 0) {
        s1--;
    }
    int s2 = (int)floor(n/3.0 + 1/3.0) * 2 - 1;
    int s3 = (s1 % 3 == 2) ? (s1 - 1) : (s1 - 2);
    int s4 = (int)ceil(n/3.0) - 1;
    if(k % 4 == 1) {
        a = 3;
        b = s1 - (k - 1) / 4 * 3;
    }else if(k % 4 == 3) {
        a = 3;
        b = s3 - (k - 3) / 4 * 3;
    }else if((k % 4 == 2) xor (s1 % 3 == 2)) {
        a = 1;
        if(k % 4 == 2) {
            b = s4 - (k - 2) / 4;
        }else {
            b = s4 - (k - 4) / 4;
        }
    }else {
        a = 2;
        if(k % 4 == 2) {
            b = s2 - (k - 2) / 4 * 2;
        }else {
            b = s2 - (k - 4) / 4 * 2;
        }
    }
}
pair<int, int> get_farey(int n, int k) {
    pair<int, int> ret;
    int fl = getflen(n);
    int sl = getslen(n);
    if(k <= fl) {
        get_f(n, k, ret.first, ret.second);
    }else if(k <= sl + fl) {
        get_s(n, k - fl, ret.first, ret.second);
    }else {
        get_t(n, k - fl - sl, ret.first, ret.second);
    }
    return ret;
}
int main() {
    int T, n, k;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        pair<int, int> ans = get_farey(n, k);
        printf("%d/%d\n", ans.first, ans.second);
    }
    return 0;
}
