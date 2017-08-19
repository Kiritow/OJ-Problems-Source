#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;
int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        long long n, m;
        long long ex = 0;
        cin >> n >> m;
        if (m < n - 1) {
            ex = n - m - 1;
            n = n - ex;
        }
        long long emax = n*(n - 1) / 2;
        long long dec = emax - m;
        if (dec < 0)
            dec = 0;
        long long ans;
        //cout << "emax=" << emax << endl;
        //cout << "dec =" << dec << endl;
        //cout << "ex  =" << ex << endl;
        if (ex > 0)
            ans = 2 * dec + n*(n - 1) + n*ex*(ex+n)+ex*(ex+n-1)*(ex+n);
        else
            ans = 2 * dec + n*(n - 1);
        cout << ans << endl;
    }
}