#include <cstdio>
#include <queue>
using namespace std;
bool vis[1000000];
int main(){
    int T, n;
    while (scanf("%d",&T)==1){
       while (T--){
            scanf("%d", &n);
            int temp, ans = 0;
            queue<int> que;
            while (n--){
                scanf("%d", &temp);
                while (vis[temp]){
                    vis[que.front()] = false;
                    que.pop();
                }
                que.push(temp);
                vis[temp] = true;
                if (que.size() > ans)
                    ans = que.size();
            }
            printf("%d\n", ans);
            while (que.size()){
                vis[que.front()] = false;
                que.pop();
            }
        }
    }
    return 0;
}
