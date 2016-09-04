#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=250;
int n;
int head;
int tail;
int Start;
int Finish;
int link[N];     
int Father[N];   
int Base[N];     
int Q[N];
bool mark[N];
bool mat[N][N];
bool InBlossom[N];
bool in_Queue[N];
void BlossomContract(int x,int y){
    memset(mark,0,sizeof(mark));
    memset(InBlossom,0,sizeof(InBlossom));
    #define pre Father[link[i]]
    int lca,i;
    for (i=x;i;i=pre) {i=Base[i]; mark[i]=true; }
    for (i=y;i;i=pre) {i=Base[i]; if (mark[i]) {lca=i; break;} }  
    for (i=x;Base[i]!=lca;i=pre){
        if (Base[pre]!=lca) Father[pre]=link[i]; 
        InBlossom[Base[i]]=true;
        InBlossom[Base[link[i]]]=true;
    }
    for (i=y;Base[i]!=lca;i=pre){
        if (Base[pre]!=lca) Father[pre]=link[i]; 
        InBlossom[Base[i]]=true;
        InBlossom[Base[link[i]]]=true;
    }
    #undef pre
    if (Base[x]!=lca) Father[x]=y;    
    if (Base[y]!=lca) Father[y]=x;
    for (i=1;i<=n;i++)
      if (InBlossom[Base[i]]){
          Base[i]=lca;
          if (!in_Queue[i]){
              Q[++tail]=i;
              in_Queue[i]=true;     
          }
      }
}
void Change(){
    int x,y,z;
    z=Finish;
    while (z){
        y=Father[z];
        x=link[y];
        link[y]=z;
        link[z]=y;
        z=x;
    }
}
void FindAugmentPath(){
    memset(Father,0,sizeof(Father));
    memset(in_Queue,0,sizeof(in_Queue));
    for (int i=1;i<=n;i++) Base[i]=i;
    head=0; tail=1;
    Q[1]=Start;
    in_Queue[Start]=1;
    while (head!=tail){
        int x=Q[++head];
        for (int y=1;y<=n;y++)
          if (mat[x][y] && Base[x]!=Base[y] && link[x]!=y)   
            if ( Start==y || link[y] && Father[link[y]] )    
                BlossomContract(x,y);
            else if (!Father[y]){
                Father[y]=x;
                if (link[y]){
                    Q[++tail]=link[y];
                    in_Queue[link[y]]=true;
                }
                else{
                    Finish=y;
                    Change();
                    return;
                }
            }
    }
}
void Edmonds(){
    memset(link,0,sizeof(link));
    for (Start=1;Start<=n;Start++)
      if (link[Start]==0)
        FindAugmentPath();
}
int MaxMatch()
{
    Edmonds();
    int cnt=0;
    for (int i=1;i<=n;i++)
      if (link[i]) cnt++;
    return cnt;
}
void output(){
    memset(mark,0,sizeof(mark));
    int cnt=0;
    for (int i=1;i<=n;i++)
      if (link[i]) cnt++;
    printf("%d\n",cnt);
    for (int i=1;i<=n;i++)
      if (!mark[i] && link[i]){
          mark[i]=true;
          mark[link[i]]=true;
          printf("%d %d\n",i,link[i]);
      }
}
char str[50][50];
const int dx[]={-1,-1,-1,1,1,1,0,0,2,-2,2,-2,2,-2,2,-2,1,-1,-1,1};
const int dy[]={-1,1,0,0,1,-1,-1,1,2,2,-2,-2,1,-1,-1,1,2,-2,2,-2};
int main()
{
    int ci,pl=1;scanf("%d",&ci);
    while(ci--)
    {
        int r,c;scanf("%d%d",&r,&c);
        n=r*c;
        for(int i=0;i<r;i++) scanf("%s",str[i]);
        int maxMatch,maxMatchK;
        memset(mat,0,sizeof(mat));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int p1=i*c+j+1;
                if(str[i][j]=='#'||str[i][j]=='K') continue;
                for(int k=0;k<20;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0&&x<r&&y>=0&&y<c){
                        if(str[x][y]=='#'||str[x][y]=='K') continue;
                        int p2=x*c+y+1;
                        mat[p1][p2]=1;
                    }
                }
            }
        }
        maxMatch=MaxMatch();
        memset(mat,0,sizeof(mat));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int p1=i*c+j+1;
                if(str[i][j]=='#') continue;
                for(int k=0;k<24;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0&&x<r&&y>=0&&y<c){
                        if(str[x][y]=='#') continue;
                        int p2=x*c+y+1;
                        mat[p1][p2]=1;
                    }
                }
            }
        }
        maxMatchK=MaxMatch();
        if(maxMatch==maxMatchK)
             printf("Case #%d: daizhenyang lose\n",pl++);
        else printf("Case #%d: daizhenyang win\n",pl++);
    }
    return 0;
}
