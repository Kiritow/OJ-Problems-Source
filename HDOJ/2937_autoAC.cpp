#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
char tg[10][10] = {
    " _ _ ",
    "|   |",
    "|_ _|"
};
struct Grid{
    char s[5][12];
    bool input(){
        for(int i = 0; i < 5; i ++) if(!gets(s[i])) return false;
        return true;
    }
    void output(){
        for(int i = 0; i < 5; i ++) printf("%s\n", s[i]);
        printf("\n");
    }
    bool move(int x, int y){
        for(int i = 0; i <= 2; i ++){
            for(int j = 0; j <= 4; j ++){
                if(i == 0 && (j == 0 || j == 2 || j == 4)) continue;
                if(s[x+i][y+j] == tg[i][j]) s[x+i][y+j] = '.';
                if(s[x+i][y+j] == '.') continue;
                return false;
            }
        }
        return true;
    }
    bool ok(){
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 9; j ++){
                if(s[i][j] != '.' && s[i][j] != ' ') return false;
            }
        }
        return true;
    }
}g[8];
bool dfs(int th){
    if(g[th].ok()) return true;
    if(th == 6) return false;
    for(int i = 0; i + 2 < 5; i ++){
        for(int j = 0; j + 4 < 9; j += 2){
            g[th+1] = g[th];
            if(g[th+1].move(i, j)){
                if(dfs(th+1)) return true;
            }
        }
    }
    return false;
}
int main() {
    int cas = 0;
    while(g[0].input()){
        printf("Case %d: ", ++cas);
        printf("%s\n", dfs(0) ? "Yes" : "No");
    }
    return 0;
}
