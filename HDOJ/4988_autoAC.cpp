#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define INF (~0U>>1)
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
#define maxn 100010
typedef __int64 ll;
struct node{
    int v;
    int sz;
    int s;
    node *p;
    node *ch[2];
    node(){
        sz=v=0;
        s=-1;
        p=ch[0]=ch[1]=this;
    }
    bool cmp(int s)
    {
        return this->s<s;
    }
    int cd(node *o)
    {
        return ch[1]==o?1:0;
    }
    void addc(node *o,int d)
    {
        ch[d]=o;
        o->p=this;
    }
}Tnull,*null=&Tnull;
node *newnode(int v)
{
    node *u=(node*)malloc(sizeof(node));
    u->sz=1;
    u->s=rand();
    u->v=v;
    u->ch[0]=u->ch[1]=null;
    return u;
}
void pushup(node *o)
{
    o->sz=o->ch[0]->sz+o->ch[1]->sz+1;
}
void rot(node *o,int d)
{
    node *k=o->ch[d];
    o->addc(k->ch[d^1],d);
    o->p->addc(k,o->p->cd(o));
    k->addc(o,d^1);
    pushup(o);
    pushup(k);
}
void Insert(node *o,node *pre,int v,int dd)
{
    if(o==null){
        pre->addc(newnode(v),dd);
        return;
    }
    int d;
    if(v>=o->v){
        d=1;
        Insert(o->ch[1],o,v,1);
    }
    else {
        d=0;
        Insert(o->ch[0],o,v,0);
    }
    if(o->cmp(o->ch[d]->s))rot(o,d);
    else pushup(o);
}
void Delete(node *o,int v)
{
    if(o==null)return;
    if(v==o->v){
        while(o->ch[0]!=null&&o->ch[1]!=null)
        {
            int d=o->ch[0]->cmp(o->ch[1]->s);
            rot(o,d);
            --o->p->sz;
        }
        node *k;
        o->ch[0]==null? k=o->ch[1]:k=o->ch[0];
        o->p->addc(k,o->p->cd(o));
        free(o);
        return;
    }
    v>o->v ? Delete(o->ch[1],v) : Delete(o->ch[0],v);
    pushup(o);
}
int Find(node *o,int v,int vis)
{
    if(o==null)return 0;
    int ax=0;
    if(v>o->v){
        if(!vis)ax+=o->ch[0]->sz+1;
        ax+=Find(o->ch[1],v,vis);
    }
    else {
        if(vis)ax+=o->ch[1]->sz+1;
        ax+=Find(o->ch[0],v,vis);
    }
    return ax;
}
void Free(node *o)
{
    if(o==null)return;
    Free(o->ch[0]);
    Free(o->ch[1]);
    free(o);
}
node *tree[maxn];
int a[maxn];
int b[maxn];
int p[maxn];
int pa[maxn];
int pb[maxn];
int n;
int bit(int x)
{
    return x&(-x);
}
void buildST()
{
    for(int i=0;i<n;++i){
    tree[i]=(node*)malloc(sizeof(node));
    tree[i]->ch[0]=tree[i]->ch[1]=null;
    }
}
void updateST1(int p,int v)
{
    while(p<n)
    {
    Insert(tree[p]->ch[1],tree[p],v,1);
    p+=bit(p+1);
    }
}
void updateST2(int p,int v)
{
    while(p<n)
    {
    Delete(tree[p]->ch[1],v);
    p+=bit(p+1);
    }
}
int queryST(int p,int v1,int v2)
{
    int ax=0;
    while(p>=0)
    {
        ax+=Find(tree[p]->ch[1],v1,0) + Find(tree[p]->ch[1],v2,1);
        p-=bit(p+1);
    }
    return ax;
}
void FreeST()
{
    for(int i=0;i<n;++i)Free(tree[i]);
}
char s[10];
int sum[maxn];
void addbit(int x)
{
    while(x<n)
    {
        sum[x]++;
        x+=bit(x+1);
    }
}
int getbit(int x)
{
    int ans=0;
    while(x>=0)
    {
        ans+=sum[x];
        x-=bit(x+1);
    }
    return ans;
}
int main()
{
    int i,Q;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;++i){
                scanf("%d",&a[i]);
                pa[a[i]]=i;
        }
        for(i=0;i<n;++i){
                scanf("%d",&b[i]);
                pb[b[i]]=i;
        }
        for(i=0;i<n;++i)p[i]=pa[b[i]];
        memset(sum,0,sizeof(sum));
        ll ans=0;
        for(i=0;i<n;++i)
        {
            ans+=getbit(n-1)-getbit(p[i]);
            addbit(p[i]);
        }
        buildST();
        for(i=0;i<n;i++)updateST1(i,p[i]);
        scanf("%d",&Q);
        for(i=0;i<Q;++i)
        {
            scanf("%s",s);
            if(s[0]=='Q')printf("%I64d\n",ans);
            else {
                int vis,x,y,temp;
                scanf("%d%d%d",&vis,&x,&y);
                if(x==y)continue;
                if(vis){
                    swap(b[x],b[y]);
                    pb[b[x]]=x;
                    pb[b[y]]=y;
                }
                else {
                    swap(a[x],a[y]);
                    pa[a[x]]=x;
                    pa[a[y]]=y;
                    x=pb[a[x]];
                    y=pb[a[y]];
                }
                updateST2(x,p[x]);
                updateST2(y,p[y]);
                if(x>y)swap(x,y);
                if(p[x]>p[y]){
                    y-x==1 ? temp=0 : temp=queryST(y,p[y],p[x])-queryST(x,p[y],p[x]);
                    ans+=((temp-y+x+1)<<1)-1;
                }
                else {
                    y-x==1 ? temp=0 : temp=queryST(y,p[x],p[y])-queryST(x,p[x],p[y]);
                    ans+=1+((y-x-1-temp)<<1);
                }
                updateST1(x,p[y]);
                updateST1(y,p[x]);
                swap(p[x],p[y]);
            }
        }
        FreeST();
    }
    return 0;
}
