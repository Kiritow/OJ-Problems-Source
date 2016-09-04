#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 1001;
map<string, int> mp;
int n, k, top;
int num[LEN];
vector<int> tab[LEN];
int ch(string s){
    if(!mp.count(s)) mp[s] = top++;
    return mp[s];
}
int main()
{
    char str[1010];
    int tmp;
    while(scanf("%d%d", &k, &n) != EOF){
        if(!k && !n) break;
        for(int i=0; i<LEN; i++) tab[i].clear();
        top = 0; mp.clear();
        for(int i=0; i<n; i++){
            scanf("%s", &str);
            num[i] = ch(str);
            for(int j=0; j<k; j++){
                scanf("%d", &tmp);
                tmp --;
                tab[tmp].PB(i);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(tab[i].size() != k) ans ++;
            else{
                map<int, int> st;
                int cc = 0;
                for(int j=0; j<tab[i].size(); j++){
                    int x = tab[i][j], y = num[i];
                    if(num[x] == y || st.count(x)){
                        ans ++;break;
                    }else st[x] = 1;
                }
            }
        }
        if(ans == 0) puts("NO PROBLEMS FOUND");
        else if(ans == 1) puts("1 PROBLEM FOUND");
        else printf("%d PROBLEMS FOUND\n", ans);
    }
    return 0;
}
