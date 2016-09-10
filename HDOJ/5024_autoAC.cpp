#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 102
char mat[N][N];
int maxn,n;
int dir1[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dir2[4][2] = {{1,1},{-1,1},{1,-1},{-1,-1}};
void solve1(int x,int y)
{
    int tmp[4];
    for(int i=0;i<4;i++){
        int xx=x,yy=y;
        tmp[i]=0;
        while(true){
            xx+=dir1[i][0];
            yy+=dir1[i][1];
            if(mat[xx][yy]!='#'&&xx>=0&&xx<n&&yy>=0&&yy<n){
                tmp[i]++;
            }
            else break;
        }
    }
    sort(tmp,tmp+4);
    maxn = max(maxn,tmp[2]+tmp[3]);
}
void solve2(int x,int y)
{
    int tmp[4];
    for(int i=0;i<4;i++){
        int xx=x,yy=y;
        tmp[i]=0;
        while(true){
            xx+=dir2[i][0];
            yy+=dir2[i][1];
            if(mat[xx][yy]!='#'&&xx>=0&&xx<n&&yy>=0&&yy<n){
                tmp[i]++;
            }
            else break;
        }
    }
    sort(tmp,tmp+4);
    maxn = max(maxn,tmp[2]+tmp[3]);
}
int main()
{
    while(~scanf("%d",&n)){
        if(n==0)
            break;
        maxn = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]!='#'){
                    solve1(i,j);
                    solve2(i,j);
                }
        printf("%d\n",maxn+1);
    }
    return 0;
}
