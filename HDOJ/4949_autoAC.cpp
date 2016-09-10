#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define HASH 100007
#define STATE 500010
#define maxd 15
int maze[maxd][maxd];
int code[maxd];
int n,m;
struct HASHMAP{
    int head[HASH];
    int state[STATE],nxt[STATE];
    int f[STATE];
    int sz;
    void clear(){sz=0;memset(head,-1,sizeof(head));}
    void push(int st,int ans){
        int h=st%HASH;
        for(int i=head[h];i!=-1;i=nxt[i]){
            if(st==state[i]){
                f[i] = f[i]<ans?f[i]:ans;
                return ;
            }
        }
        state[sz]=st,nxt[sz]=head[h],f[sz]=ans;
        head[h]=sz++;
    }
}hm[2];
void decode(int st){
    for(int i=m;i>=0;--i) code[i]=st&3,st>>=2;
}
int encode(){
    int ret=0;
    for(int i=0;i<=m;++i) ret=ret<<2|code[i];
    return ret;
}
void shift(){
    for(int i=m;i;--i) code[i]=code[i-1];
    code[0]=0;
}
int ans;
int zo,oz,oo;
void dpblank(int i,int j,int cur){
    int mv = j==m?2:0;
    int all = (1<<(2*(m+1)-mv) ) -1;
    for(int k=0;k<hm[cur].sz;++k){
        int st = hm[cur].state[k];
        int left = st&(oo>>(2*(j-1))), up = st&(oo>>(2*j));
        int L = left>>(2*(m-j+1)), U = up>>(2*(m-j));
        int cnt = ((L>>1)+(U>>1))&1;
        if(i==1 || U==2 || maze[i-1][j]==U){
            int st2 = st^left^up;
            if(cnt) st2 = st2 | (zo>>(2*(j-1))) | (zo>>(2*j));
            hm[cur^1].push((st2>>mv)&all, hm[cur].f[k]);
        }
        if(hm[cur].f[k]+2<ans)
        if(i==1 || U==2 || maze[i-1][j]==U){
            int st2 = st^left^up;
            if(!cnt) st2 = st2 | (zo>>(2*(j-1))) | (zo>>(2*j));
            hm[cur^1].push((st2>>mv)&all, hm[cur].f[k]+2);
        }
        if(hm[cur].f[k]+1<ans)
        if(i==1 || U==2 || maze[i-1][j]!=U){
            int st2 = st^left^up;
            if(j>1 && L!=2) st2 = st2 ^ (zo>>(2*(j-2)));
            st2 = st2 | (oz>>(2*(j-1))) | (oz>>(2*j));
            hm[cur^1].push((st2>>mv)&all, hm[cur].f[k]+1);
        }
    }
}
void solve(){
    zo = 1<<(2*m);
    oz = 2<<(2*m);
    oo = 3<<(2*m);
    int cur=0;
    hm[0].clear();
    hm[0].push(0,0);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            hm[cur^1].clear();
            dpblank(i,j,cur);
            cur^=1;
        }
    }
    for(int k=0;k<hm[cur].sz;++k){
        bool yes=true;
        decode(hm[cur].state[k]);
        for(int j=1;j<=m;++j){
            if(code[j]!=2 && code[j]!=maze[n][j]){
                yes=false;
                break;
            }
        }
        if(yes) ans = ans<hm[cur].f[k]?ans:hm[cur].f[k];
    }
}
int main(){
    int ca=0;
    while(~scanf("%d%d",&n,&m) && n){
        printf("Case #%d: ",++ca);
        ans=0;
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
            scanf("%1d",maze[i]+j), ans+=maze[i][j];
        ans*=2;
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
