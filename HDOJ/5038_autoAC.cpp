#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
vector <int> g[10005];
int fun(int x) {
    return 10000 - (100 - x) * (100 - x);
}
int main()
{
    int n, w, T, cas = 0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        set <int> s;
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++) {
            scanf("%d", &w);
            int grade = fun(w);
            s.insert(grade);
            g[grade].push_back(w);
        }
        set <int> ::iterator it;
        vector <int> v;
        for(it = s.begin(); it != s.end(); it++) {
            v.push_back(g[*it].size());
        }
        sort(v.begin(), v.end());
        int ssize = v.size();
        int cnt = 0;
        for(int i = ssize - 1; i >= 0; i--) {
            if(v[i] == v[ssize-1])
                cnt++;
        }
        printf("Case #%d:\n", ++cas);
        if(cnt == 1) {
            for(it = s.begin(); it != s.end(); it++)
            if(g[*it].size() == v[ssize-1]) {
                printf("%d\n", *it);
                break;
            }
        }
        else {
            if(cnt == ssize)
                printf("Bad Mushroom\n");
            else {
                vector <int> ans;
                for(it = s.begin(); it != s.end(); it++) {
                    int tmp = *it;
                    if(g[tmp].size() == v[ssize-1]) {
                        ans.push_back(tmp);
                    }
                }
                sort(ans.begin(), ans.end());
                int z = ans.size();
                for(int i = 0; i < z - 1; i++)
                    printf("%d ", ans[i]);
                printf("%d\n", ans[z-1]);
            }
        }
    }
    return 0;
}
