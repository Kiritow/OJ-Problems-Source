#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 31;
struct Box{
    int dims[11];
}boxes[MAX];
bool g[MAX][MAX];
int dp[MAX], fa[MAX], n, k;
//check if box a can be nested into box b
bool can_be_nested(Box & a, Box & b, int len){
    for(int i = 0; i < len; ++i){
        if(a.dims[i] >= b.dims[i])return false;
    }
    return true;
}
int memoized_dfs(int i){
    if(dp[i] != 0)return dp[i];
    int max_len = 0;
    for(int j = 1; j <= k; ++j){
        if(g[i][j]){
            int next_len = memoized_dfs(j);
            if(next_len > max_len){
                max_len = next_len;
                fa[i] = j;
            }
        }
    }
    return dp[i] = max_len + 1;
}
int main(int argc, char const *argv[]){
    while(scanf("%d %d", &k, &n) == 2){
        memset(g, false, sizeof(g));
        for(int i = 1; i <= k; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%d", &boxes[i].dims[j]);
            }
            sort(boxes[i].dims, boxes[i].dims + n);
        }
        for(int i = 1; i <= k; ++i){
            for(int j = 1; j <= k; ++j){
                if(can_be_nested(boxes[j], boxes[i], n)){
                    g[i][j] = true;
                }
            }
        }
        vector<int> ans;
        for(int i = 1; i <= k; ++i){
            memset(dp, 0, sizeof(dp));
            memset(fa, 0, sizeof(fa));
            int length = memoized_dfs(i);
            if(length > ans.size()){
                ans.clear();
                int p = i;
                while(p != 0){
                    ans.push_back(p);
                    p = fa[p];
                }
            }
        }
        printf("%d\n", ans.size());
        for(int i = ans.size() - 1; i >= 0; --i){
            if(i < ans.size() - 1)printf(" ");
            printf("%d", ans[i]);
        }
        printf(" \n");
    }
    return 0;
}
