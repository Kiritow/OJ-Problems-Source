#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define Keytree (ch[ ch[root][1] ][0])
const int maxn = 100010;
struct node {
    int num,id;
}in[maxn];
int id[maxn];
int cmp(node a,node b){
    if(a.num!=b.num) return a.num<b.num;
    return a.id<b.id;
}
struct SplayTree{
    int tot,root;
    int pre[maxn];
    int size[maxn];
    int ch[maxn][2];
    inline void Rotate(int x, int c) {    
        int y = pre[x];
        pushdown(y);
        pushdown(x);
        ch[y][!c] = ch[x][c];
        if ( ch[x][c] )    pre[ ch[x][c] ] = y;
        pre[x] = pre[y];
        if ( pre[y] )    ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
        ch[x][c] = y;
        pre[y] = x;
        pushup(y);
    }
    inline void Splay(int x, int f) {  
        pushdown(x);
        while ( pre[x] != f ) {
            int y = pre[x], z = pre[y];
            pushdown(z);    pushdown(y);    pushdown(x);    
            if ( pre[ pre[x] ] == f ) {
                Rotate(x, ch[pre[x]][0] == x);
            }
            else {
                if ( ch[z][0] == y ) {
                    if ( ch[y][0] == x ) 
                        Rotate(y, 1), Rotate(x, 1);
                    else 
                        Rotate(x, 0), Rotate(x, 1);
                }
                else {
                    if ( ch[y][0] == x ) 
                        Rotate(x, 1), Rotate(x, 0);
                    else 
                        Rotate(y, 0), Rotate(x, 0);
                }
            }
        }
        pushup(x);
        if ( f == 0 )    root = x;
    }
    inline void Select(int k, int f) { 
        int x = root;
        while ( 1 ) {
            pushdown(x);
            if ( k == size[ ch[x][0] ] + 1 ) 
                break;
            if ( k <= size[ ch[x][0] ] )
                x = ch[x][0];
            else {
                k -= (size[ ch[x][0] ] + 1);
                x = ch[x][1];
            }
        } 
        Splay(x, f);
    }
    inline void del_root(){
        int t=root;
        if(ch[root][1]) {
            root=ch[root][1];
            Select(1,0);
            ch[root][0]=ch[t][0];
            if(ch[t][0]) pre[ch[t][0]]=root;
        }
        else 
            root=ch[root][0];
        pre[root]=0;
        pushup(root);
    }
    inline void pushup(int x){
        size[x]=size[ ch[x][0] ] + size[ ch[x][1] ] +1;
    }
    inline void pushdown(int x){
        if(flip[x]){
            flip[x]=0;
            flip[ch[x][0]]^=1;
            flip[ch[x][1]]^=1;
            swap(ch[x][0],ch[x][1]);
        }
    }
    void Newnode(int &x,int f){
        x=++tot;
        pre[x]=f;
        ch[x][0]=ch[x][1]=0;
        flip[x]=0;
        size[x]=1;
    }
    void build(int &x,int l,int r,int f){
        if(l>r) return ;
        int mid=(l+r)>>1;
        Newnode(x,f);
        map[id[mid]]=x;
        build(ch[x][0],l,mid-1,x);
        build(ch[x][1],mid+1,r,x);
        pushup(x);
    }
    void init(int n){
        int i;
        pre[0]=ch[0][0]=ch[0][1]=0;
        size[0]=flip[0]=tot=0;
        for(i=1;i<=n;i++) {
            scanf("%d",&in[i].num);
            in[i].id=i;
        }
        sort(in+1,in+n+1,cmp);
        for(i=1;i<=n;i++) id[in[i].id]=i;
        map[id[1]] = 1;
        map[id[n]] = 2;
        Newnode(root,0);
        Newnode(ch[root][1],root);
        build(Keytree,2,n-1,ch[root][1]);
        pushup(ch[root][1]);
        pushup(root);
    }
    void solve(int n){
        for(int i=1;i<=n;i++){
            Splay(map[i],0);
            printf("%d",i+size[ch[root][0]]);
            if(i<n) printf(" ");
            flip[ch[root][0]]^=1;
            del_root();
        }
        puts("");
    }
    int map[maxn];
    int flip[maxn];
}spt;
int main(){
    int n;
    while(scanf("%d",&n),n)    {
        if(n==1) {scanf("%*d");printf("1\n");continue;}
        spt.init(n);
        spt.solve(n);
    }
    return 0;
}
