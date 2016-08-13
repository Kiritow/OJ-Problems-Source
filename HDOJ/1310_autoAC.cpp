#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
#define ONLINE_JUDGE
#define MAXN 125
#define INF 0xfffffff
int nn;
int dis[MAXN][MAXN];
string buf[MAXN];
bool visit[5];
map<string, int> tb;
int a[MAXN];
int myabs(int x) {
    return x<0 ? -x:x;
}
void init() {
    string s = "ABCDE";
    nn = 0;
    int i, j, k, p;
    int sum, tmp;
    do {
        buf[nn] = s;
        tb[s] = nn++;
    } while (next_permutation(s.begin(), s.end()));
    for (i=0; i<nn; ++i) {
        dis[i][i] = 0;
        for (j=i+1; j<nn; ++j) {
            sum = 0;
            memset(visit, false, sizeof(visit));
            for (k=0; k<5; ++k) {
                for (p=0; p<5; ++p) {
                    if (buf[j][p] == buf[i][k])
                        break;
                    else if (!visit[buf[j][p]-'A'])
                        ++sum;
                }
                visit[buf[i][k]-'A'] = true;
            }
            dis[i][j] = dis[j][i] = sum;
        }
    }
}
int main() {
    int n;
    int i, j, k, tmp;
    int    v, mmin, sum;
    string s;
    ios::sync_with_stdio(false);
    init();
    while (cin>>n && n) {
        for (i=0; i<n; ++i) {
            cin >>s;
            a[i] = tb[s];
        }
        mmin = INF;
        for (i=0; i<nn; ++i) {
            sum = 0;
            for (j=0; j<n; ++j)
                sum += dis[i][a[j]];
            if (sum < mmin) {
                v = i;
                mmin = sum;
            }
        }
        printf("%s is the median ranking with value %d.\n", buf[v].c_str(), mmin);
    }
    return 0;
}
