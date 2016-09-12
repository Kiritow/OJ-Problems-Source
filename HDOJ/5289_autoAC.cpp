#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int a[100005];
multiset<int> s;
int main()
{
    int T;
    scanf("%d", &T);
    int n, k;
    while(T--) {
        s.clear();
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if(k == 0) {
            printf("0\n");
            continue;
        }
        s.insert(a[0]);
        int l = 0, r = 1;
        int cnt = 1;
        long long ans = 0;
        int minn, maxn;
        while(1) {
            if(s.size()) {
                minn = *s.begin();
                maxn = *s.rbegin();
                if(abs(a[r]-minn) < k && abs(a[r]-maxn) < k) {
                    ans += (long long)s.size();
                    s.insert(a[r]);
                    r++;
                    if(r == n) break;
                }
                else {
                    if(s.size()) {
                        s.erase(s.find(a[l]));
                    }
                    l++;
                }
            }
            else {
                l = r;
                s.insert(a[r]);
                r++;
                if(r == n) break;
            }
        }
        printf("%I64d\n", ans+n);
    }
    return 0;
}
