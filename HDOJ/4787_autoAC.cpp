#pragma comment( linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define maxnode 511111
#define sigma_size 2
struct Trie{
    int ch[maxnode][sigma_size];
    bool val[maxnode];
    int f[maxnode];
    int sz;
    void init(){
        sz=1;
        memset(ch,0,sizeof(ch));
        memset(val, 0, sizeof(val));  
        memset(f,0,sizeof(f));
    }
    int idx(char c){ return c-'0'; }
    int insert(char *s){
        int u = 0;
        for(int i = 0; s[i] ;i++){
            int c = idx(s[i]);
            if(!ch[u][c])
                ch[u][c] = sz++;
            u = ch[u][c];
        }
        val[u] = 1;
        return u;
    }
    bool search(char *s){
        int u = 0;
        for(int i = 0; s[i] ;i++){
            int c = idx(s[i]);
            if(!ch[u][c]) return 0;
            u = ch[u][c];
        }
        return val[u];
    }
    void getFail(){
        queue<int> q;
        for(int i = 0; i<sigma_size; i++)
            if(ch[0][i]) q.push(ch[0][i]);  
        while(!q.empty()){
            int r = q.front(); q.pop();  
            for(int c = 0; c<sigma_size; c++){
                int u = ch[r][c];
                if(!u)continue;
                q.push(u);
                int v = f[r];
                while(v && ch[v][c] == 0) v = f[v]; 
                f[u] = ch[v][c];
            }
        }
    }
    int find(char *T){
        int j = 0, ans = 0;
        for(int i = 0; T[i] ; i++){
            int c = idx(T[i]);
            while(j && ch[j][c]==0) j = f[j];
            j = ch[j][c];
            int temp = j;
            while(temp){ 
                ans += val[temp];
                temp = f[temp];
            }
        }
        return ans;
    }
};
Trie ac, buf;
void dfs(int u, int v){
    for(int i = 0;i < 2;i++){
        if( buf.ch[v][i] )
        {
            int e2 = buf.ch[v][i];
            if(! ac.ch[u][i]) 
            { 
                memset(ac.ch[ac.sz], 0, sizeof(ac.ch[ac.sz]));
                ac.ch[u][i] = ac.sz++;
            }
            int e1 = ac.ch[u][i];
            ac.val[e1] |= buf.val[e2];
            dfs(e1, e2);
        }
    }
}
void join(){
    dfs(0, 0);
    buf.init();
    ac.getFail();
}
char s[6000000],temp[6000000];
int main(){
    int Cas = 1, T, n;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("Case #%d:\n",Cas++);
        ac.init();
        buf.init();
        int L = 0;
        while(n--){
            scanf("%s",temp);
            int len = strlen ( temp + 1 ) ; 
            s[0] = temp[0] ; 
            for (int i = 0 ; i < len ; i ++ )
                s[i+1] = temp[1+(i+L%len+len)%len] ;  
            s[len+1] = '\0';
            if(s[0] == '+'){
                if( buf.search(s+1) || ac.search(s+1) )continue;
                buf.insert(s+1);
                buf.getFail();
                if(buf.sz > 2000) join();
            }
            else
            {
                L = buf.find(s+1) + ac.find(s+1);
                printf("%d\n", L);
            }
        }
    }
    return 0;
}
