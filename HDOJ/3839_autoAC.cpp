#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
int H,W;
char Map[220][440];
int vis[220][440];
int chr[220][440];
int wblc_cnt,bblc_cnt;
char hie[6]={'W','A','K','J','S','D'};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
map<int,bool> Hsh[80010];
int bccnt[80010];
char ans[80010];
int comp(const void *_a,const void *_b)
{
    char a=*(char *)_a;
    char b=*(char *)_b;
    return a-b;
}
void dfs1(int x,int y)
{
    vis[x][y]=wblc_cnt;
    int nx,ny;
    for(int i=0;i<4;i++){
        nx=dx[i]+x;
        ny=dy[i]+y;
        if(nx>=0&&nx<H&&ny>=0&&ny<W && !vis[nx][ny]  && Map[nx][ny]=='0')dfs1(nx,ny);
    }
}
void dfs2(int x,int y)
{
    chr[x][y]=bblc_cnt;
    int nx,ny;
    for(int i=0;i<4;i++){
        nx=dx[i]+x;
        ny=dy[i]+y;
        if(nx>=0&&nx<H&&ny>=0&&ny<W&&!chr[nx][ny]){
            if(Map[nx][ny]=='0'){
                if(Hsh[bblc_cnt].find(vis[nx][ny]) != Hsh[bblc_cnt].end())continue;
                Hsh[bblc_cnt].insert(pair<int,bool>(vis[nx][ny],true));
            }else dfs2(nx,ny);
        }
    }
}
int main()
{
    char str[60];
    int kase=1;
    while(~scanf("%d%d",&H,&W)&&(H+W)){
        printf("Case %d: ",kase++);
        getchar();
        memset(Map,0,sizeof(Map));
        memset(vis,0,sizeof(vis));
        memset(chr,0,sizeof(chr));
        for(int i=0;i<=4*W+8;i++)Map[0][i]=Map[H+1][i]='0';
        for(int i=1;i<=H;i++){
            gets(str);
            for(int j=0;j<4;j++)
                Map[i][j]=Map[i][4+W*4+j]='0';
            for(int j=0;j<W;j++){
                int x;
                if('0'<=str[j] && str[j]<='9')
                    x=str[j]-'0';
                else
                    x=10+str[j]-'a';
                for(int k=0;k<4;k++){
                    if(x & 1<<(3-k)) Map[i][4+j*4+k]='1';
                    else Map[i][4+j*4+k]='0';
                }
            }
        }
        W+=2;W*=4;
        H+=2;
        wblc_cnt=0;
        for(int i=0;i<H;i++)for(int j=0;j<W;j++)
            if(vis[i][j]==0 && Map[i][j]=='0'){
                wblc_cnt++;
                dfs1(i,j);
            }
        bblc_cnt=0;
        for(int i=0;i<H*W;i++) Hsh[i].clear();
        for(int i=0;i<H;i++)for(int j=0;j<W;j++)
            if(chr[i][j]==0 && Map[i][j]=='1'){
                bblc_cnt++;
                dfs2(i,j);
            }
        for(int i=1;i<=bblc_cnt;i++)
            bccnt[i]=Hsh[i].size();
        for(int i=1;i<=bblc_cnt;i++)
            ans[i]=hie[bccnt[i]-1];
        qsort(ans+1,bblc_cnt,sizeof(char),comp);
        ans[bblc_cnt+1]='\0';
        puts(ans+1);
    }
    return 0;
}
