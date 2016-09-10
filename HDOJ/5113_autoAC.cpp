#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> vec;
typedef vector<vec> mat;
#define AA first
#define BB second
int T,N,M,K;
int m[10][10];
int c[100];
bool hasAns;
bool C(int x,int y,int c){
    int row = true, column = true;
    if( x-1>=1&&m[x-1][y]==c ) column = false;
    if( y-1>=1 && m[x][y-1]==c ) row = false;
    return row&&column;
}
void dfs(int x,int y,int cur){
    for(int i=1;i<=K;i++){
        if( c[i]>(cur+1)/2 ) return;
    }
    if(hasAns) return;
    if( x==N+1 ){
        hasAns = true;
        puts("YES");
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++ ){
                printf(j==M?"%d\n":"%d ",m[i][j]);
            }
        }
        return;
    }
    for(int i=1;i<=K;i++)if( c[i] ){
        if( C(x,y,i) ){
            c[i]--;
            m[x][y] = i;
            if( y==M ) dfs(x+1,1,cur-1);
            else dfs(x,y+1,cur-1);
            c[i]++;
            m[x][y] = 0;
        }
    }
}
int main(){
    scanf("%d",&T);
    for(int cases = 1; cases <= T; cases++){
        scanf("%d%d%d",&N,&M,&K);
        for(int i=1;i<=K;i++){
            scanf("%d",&c[i]);
        }
        hasAns = false;
        printf("Case #%d:\n",cases);
        dfs(1,1,N*M);
        if(!hasAns) puts("NO");
    }
    return 0;
}
