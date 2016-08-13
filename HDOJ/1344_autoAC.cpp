#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 8;
struct Traffic
{
    double pos;
    int g, y, r;
};
Traffic traffic[N];
int n;
bool input();
void solve();
int main()
{
    int t = 1;
    while (input()) {
        printf("Case %d:", t++);
        solve();
    }
    return 0;
}
bool input()
{
    scanf("%d", &n);
    if (n < 0) return false;
    for (int i = 0; i < n; i++) {
        scanf("%lf%d%d%d", &traffic[i].pos, &traffic[i].g, &traffic[i].y, &traffic[i].r);
    }
    return true;
}
void solve()
{
    vector<int> ans;
    for (int i = 30; i <= 60; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            int t = (int)(traffic[j].pos * 3600 / i);
            if (t % (traffic[j].g + traffic[j].y + traffic[j].r) >= traffic[j].g + traffic[j].y) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(i);
    }
    if (ans.empty()) {
        printf(" No acceptable speeds.\n");
    } else {
        bool first = true;
        for (size_ i = 0; i < ans.size(); i++) {
            size_ j = i;
            while (j + 1 < ans.size() && ans[j + 1] - ans[j] == 1) {
                j++;
            }
            if (first) {
                first = false;
                if (j - i >= 1) {
                    printf(" %d-%d", ans[i], ans[j]);
                } else {
                    printf(" %d", ans[i]);
                }
            } else {
                if (j - i >= 1) {
                    printf(", %d-%d", ans[i], ans[j]);
                } else {
                    printf(", %d", ans[i]);
                }
            }
            i = j;
        }
        printf("\n");
    }
}
