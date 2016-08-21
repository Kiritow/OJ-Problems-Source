#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
int T, n, d, x, y;
map<int, vector<int> > mymap;
LL solve() {
    LL ans = 0;
    for(map<int, vector<int> >::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        sort(it->second.begin(), it->second.end());
        for(int i = 0, j = 0, n = it->second.size(); i < n; ++i) {
            while(j < n && it->second[i] + d > it->second[j]) ++j;
            ans += j - i - 1;
        }
    }
    int d2 = d * d;
    for(map<int, vector<int> >::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        for(vector<int>::iterator p = it->second.begin(); p != it->second.end(); ++p) {
            for(int i = 1, t = d; i < d; ++i) {
                while(i * i + t * t >= d2) --t;
                map<int, vector<int> >::iterator nx = mymap.find(it->first + i);
                if(nx != mymap.end()) {
                    ans += (upper_bound(nx->second.begin(), nx->second.end(), *p + t) - nx->second.begin()) -
                            (lower_bound(nx->second.begin(), nx->second.end(), *p - t) - nx->second.begin());
                }
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        mymap.clear();
        scanf("%d%d", &n, &d);
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            mymap[x].push_back(y);
        }
        printf("%I64d\n", solve());
    }
}
