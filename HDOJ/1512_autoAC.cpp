#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100003;
int n,m;
int f[maxn];
typedef struct node
{
    int sword;
    int dis;
    node* left;
    node* right;
}*Pnode;
Pnode tree[maxn];
int distance(Pnode t)
{
    return t?t->dis:0;
}
void fixdis(Pnode t)
{
    if(distance(t->left)<distance(t->right))
        swap(t->left,t->right);
    t->dis=distance(t->right)+1;
}
Pnode merge(Pnode a,Pnode b)
{
    if(!a)
        return b;
    if(!b)
        return a;
    if(b->sword>a->sword)
        swap(a,b);
    a->right=merge(a->right,b);
    fixdis(a);
    return a;
}
Pnode delMax(Pnode t)
{
    if(t)
        return merge(t->left,t->right);
    return NULL;
}
void init(Pnode &t,int sword)
{
    t=new node;
    t->dis=1;
    t->left=t->right=NULL;
    t->sword=sword;
}
int find(int x)
{
    int y,root,t;
    y=x;
    while(f[y]>0)
        y=f[y];
    root=y;
    y=x;
    while(f[y]>0)
    {
        t=f[y];
        f[y]=root;
        y=t;
    }
    return root;
}
int unio(int x,int y)
{
    if(f[x]<f[y])
    {
        f[x]+=f[y];
        return f[y]=x;
    }
    else
    {
        f[y]+=f[x];
        return f[x]=y;
    }
}
void solve(int u,int v)
{
    int fu=find(u);
    int fv=find(v);
    if(fu==fv)
    {
        cout<<-1<<endl;
        return;
    }
    Pnode p1,p2,p3,p4;
    init(p1,tree[fu]->sword/2);
    p2=delMax(tree[fu]);
    p2=merge(p1,p2);
    init(p3,tree[fv]->sword/2);
    p4=delMax(tree[fv]);
    p4=merge(p3,p4);
    fv=unio(fu,fv);
    tree[fv]=merge(p2,p4);
    cout<<tree[fv]->sword<<endl;
}
int main()
{
    int i,d,u,v;
    while(cin>>n)
    {
        for(i=1;i<=n;++i)
        {
            cin>>d;
            init(tree[i],d);
        }
        memset(f,-1,sizeof(f));
        cin>>m;
        for(i=0;i<m;++i)
        {
            cin>>u>>v;
            solve(u,v);
        }
        for(i=1;i<=n;++i)
            delete tree[i];
    }
    return 0;
}
