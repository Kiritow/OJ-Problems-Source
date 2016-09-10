#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int s,t,nxt ; 
}e[2500005] ;
int m,n,head[5005],cnt,match[5005],vis[5005] ;
int find(int s)
{
    for(int i=head[s] ;i!=-1 ;i=e[i].nxt)
    {
        int tt=e[i].t ;
        if(!vis[tt])
        {
            vis[tt]=1 ;
            if(match[tt]==-1 || find(match[tt]))
            {
                match[tt]=s ;
                return 1 ;
            }
        }
    }
    return 0 ;
}
int cr,cc;
int max_match()
{
    int ans=0 ;
    memset(match,-1,sizeof(match)) ;
    for(int i=1 ;i<cr ;i++)
    {
        memset(vis,0,sizeof(vis)) ;
        ans+=find(i);
    }
    return ans;
}
void add(int s,int t) {e[cnt].s=s ;e[cnt].t=t ;e[cnt].nxt=head[s] ;head[s]=cnt++ ;}
char M[55][55];
int mpr[55][55],mpc[55][55];
void read_graph()
{
    memset(head,-1,sizeof(head)) ;
    cnt=0 ;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(M[i][j]=='*')
                add(mpr[i][j],mpc[i][j]+cr);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",M[i]);
        }
        memset(mpr,-1,sizeof(mpr));
        memset(mpc,-1,sizeof(mpc));
        cr=cc=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='*' && mpr[i][j]==-1){         
                    for(int k=j;(M[i][k]=='*' || M[i][k]=='o') && k<m;k++)
                        mpr[i][k]=cr; 
                    cr++;
                }
                if(M[j][i]=='*' && mpc[j][i]==-1){          
                    for(int k=j;(M[k][i]=='*' || M[k][i]=='o') && k<n;k++)
                        mpc[k][i]=cc;
                    cc++;
                }
            }
        }
        read_graph();
        printf("%d\n",max_match());
    }
    return 0;
}
