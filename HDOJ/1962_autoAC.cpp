#include<iostream>
#include<map>
using namespace std;
#define N 60
#define MM N*N
struct node{
    int next,v;
    node(){};
    node(int a,int b){
        next=a;v=b;
    }
}E[MM];
char card1[N][5];
char card2[N][5];
map<char,int> M;
int head[N],NE,pre[N];
bool h[N];
void init(){
    NE=0;
    for(int i=0;i<=9;i++)
        M[i+'0']=i;
    M['T']=10;M['J']=11;M['Q']=12;
    M['K']=13;M['A']=14;
    M['C']=15;M['D']=16;
    M['S']=17;M['H']=18;
    memset(head,-1,sizeof(head));
    memset(pre,-1,sizeof(pre));
}
void insert(int u,int v){
    E[NE]=node(head[u],v);
    head[u]=NE++;
}
bool dfs(int u){
    for(int i=head[u];i!=-1;i=E[i].next){
        int v=E[i].v;
        if(!h[v]){
            h[v]=1;
            if(pre[v]==-1||dfs(pre[v])){
                pre[v]=u;
                return true;
            }
        }
    }
    return false;
}
bool bigger(char *p,char *q){
    if(M[p[0]]==M[q[0]])
        return M[p[1]]>M[q[1]];
    return M[p[0]]>M[q[0]];
}
int main(void){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%s",card1[i]);
        for(int i=1;i<=n;i++){
            scanf("%s",card2[i]);
            for(int j=1;j<=n;j++)
                if(bigger(card2[i],card1[j]))
                    insert(i,j+n);
        }
        int cn=0;
        for(int i=1;i<=n;i++){
            memset(h,0,sizeof(h));
            if(dfs(i))
                cn++;
        }
        printf("%d\n",cn);
    }
}
