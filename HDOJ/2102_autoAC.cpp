#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,t;
int gx[]={1,0,-1,0},gy[]={0,1,0,-1};
char map[3][20][20];
bool found,mark[3][20][20];
bool can(int x,int y,int z){
    if(x<0||x>=m||y<0||y>=n||mark[z][y][x])
        return false;
    return true;
}
void dfs(int x,int y,int z,int s){
    if(map[z][y][x]=='P'){
        if(s<=t)
            found=true;
        return ;
    }
    for(int i=0;i<4;i++){
        if(s>t||found)
            return ;
        if(can(x+gx[i],y+gy[i],z)){
            if(map[z][y+gy[i]][x+gx[i]]=='#'&&(map[!z][y+gy[i]][x+gx[i]]=='.'||map[!z][y+gy[i]][x+gx[i]]=='P')&&!mark[!z][y+gy[i]][x+gx[i]]){
                mark[z][y][x]=1;
                dfs(x+gx[i],y+gy[i],z^1,s+1);
                mark[z][y][x]=0;
            }
            else if(map[z][y+gy[i]][x+gx[i]]=='.'||map[z][y+gy[i]][x+gx[i]]=='P'){
                mark[z][y][x]=1;
                dfs(x+gx[i],y+gy[i],z,s+1);
                mark[z][y][x]=0;
            }
        }
    }
}
int main(){
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&t);
        for(i=0;i<2;i++)
            for(j=0;j<n;j++)
                scanf("%s",map[i][j]);
            found=false;
            memset(mark,0,sizeof(mark));
            mark[0][0][0]=1;
            dfs(0,0,0,0);
            if(found)
                printf("YES\n");
            else printf("NO\n");
    }
    return 0;
}
