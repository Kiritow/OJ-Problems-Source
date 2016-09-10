#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<set>
#include<map>
using namespace std;
const int maxn = 200000 + 5;
const int INF = 1000000000;
const int Mod = 1000000000 + 7;
typedef long long LL;
typedef pair<LL, LL> P;
struct Node{
    LL x, y;
    int num;
    Node(){}
    Node(LL x, LL y, int num){
        this -> x = x;
        this -> y = y;
        this -> num = num;
    }
};
map<LL, set<int> > Mx, My;
set<int>::iterator it;
int fa[maxn];
Node pos[maxn];
int cnt;
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        Mx.clear();
        My.clear();
        for(int i = 1;i <= n;i++){
            LL x, y;
            scanf("%I64d%I64d", &x, &y);
            pos[i] = Node(x, y, 1);
            fa[i] = i;
            Mx[x].insert(i);
            My[y].insert(i);
        }
        cnt = n+1;
        int t;
        scanf("%d", &t);
        LL lastans = 0;
        while(t--){
            char str[5];
            scanf("%s", str);
            if(str[0]=='Q'){
                int x;
                scanf("%d", &x);
                x = x^lastans;
                int X = Find(x);
                Node& tem = pos[X];
                LL row = tem.x;
                LL col = tem.y;
                int num = tem.num;
                lastans = 0;
                int total = 0;
                for(it = Mx[row].begin();it != Mx[row].end();it++){
                    Node& tem = pos[*it];
                    LL y = tem.y;
                    My[y].erase(*it);
                    int num = tem.num;
                    LL der = abs(y-col)%Mod;
                    lastans = (lastans + (der*der)%Mod * num) % Mod;
                    fa[*it] = cnt;
                    total += num;
                }
                for(it = My[col].begin();it != My[col].end();it++){
                    Node& tem = pos[*it];
                    LL x = tem.x;
                    Mx[x].erase(*it);
                    int num = tem.num;
                    LL der = (abs(x-row))%Mod;
                    lastans = (lastans + (der*der)%Mod*num) % Mod;
                    fa[*it] = cnt;
                    total += num;
                }
                fa[cnt] = cnt;
                pos[cnt] = Node(row, col, total);
                Mx[row].clear();
                My[col].clear();
                Mx[row].insert(cnt);
                My[col].insert(cnt);
                cnt++;
                printf("%I64d\n", lastans);
            }
            else{
                int x;
                LL d;
                scanf("%d%I64d", &x, &d);
                x = x^lastans;
                int X = Find(x);
                Node& tem = pos[X];
                LL nx = tem.x;
                LL ny = tem.y;
                tem.num--;
                if(tem.num==0){
                    Mx[nx].erase(X);
                    My[ny].erase(X);
                }
                if(str[0]=='U'){
                    nx -= d;
                }
                else if(str[0]=='L'){
                    ny -= d;
                }
                else if(str[0]=='D'){
                    nx += d;
                }
                else{
                    ny += d;
                }
                fa[x] = x;
                pos[x] = Node(nx, ny, 1);
                Mx[nx].insert(x);
                My[ny].insert(x);
            }
        }
    }
    return 0;
}
