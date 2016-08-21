#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 110000
#define mem(a,b) memset(a,b,sizeof(a))
#define root10 ch[ch[root][1]][0]
#define root1 ch[root][1]
#define root11 ch[ch[root][1]][1]
#define lson ch[x][0]
#define rson ch[x][1]
int ch[maxn][2];
int pre[maxn];
int root,tot;
int size[maxn];
int val[maxn];
//----------------------
int l[maxn];
int r[maxn];
vector<int>vec[maxn];
vector<int>ans;
vector<int>tree;
void push_down(int x)
{
}
void push_up(int x)
{
}
void rot(int x,int kind)
{
    int y=pre[x];
    push_down(y);
    push_down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    push_up(y);
    push_up(x);
}
void splay(int x,int goal)
{
    push_down(x);
    while(pre[x]!=goal)
    {
        if(pre[pre[x]]==goal)
        {
            push_down(pre[x]);
            push_down(x);
            rot(x,ch[pre[x]][0]==x);
        }
        else
        {
            int y=pre[x];
            push_down(pre[y]);
            push_down(y);
            push_down(x);
            int kind=ch[pre[y]][0]==y;
            if(ch[y][kind]==x)
            {
                rot(x,!kind);
                rot(x,kind);
            }
            else
            {
                rot(y,kind);
                rot(x,kind);
            }
        }
    }
    push_up(x);
    if(goal==0)root=x;
}
void init()
{
    root=tot=0;
    memset(ch,0,sizeof(ch));
    memset(pre,0,sizeof(pre));
}
void newnode(int &x,int k,int father)
{
    x=++tot;
    pre[x]=father;
    size[x]=1;
    ch[x][0]=ch[x][1]=0;
    val[x]=k;
    if(k<0)r[-k]=x;
    else l[k]=x;
}
void buildtree(int &x,int l,int r,int father)
{
    if(l>r)return;
    int mid=(l+r)/2;
    newnode(x,ans[mid],father);
    buildtree(ch[x][0],l,mid-1,x);
    buildtree(ch[x][1],mid+1,r,x);
    push_up(x);
}
int get_max(int r)
{
    push_down(r);
    while(ch[r][1])
    {
        r=ch[r][1];
        push_down(r);
    }
    return r;
}
int get_min(int r)
{
    push_down(r);
    while(ch[r][0])
    {
        r=ch[r][0];
        push_down(r);
    }
    return r;
}
int query(int x)
{
    int ll=l[x];
    splay(ll,0);
    int y=get_min(ll);
    return val[y];
}
void dos(int a,int b)
{
    int x,y,z;
    x=l[a];y=r[a];z=y;
    splay(x,0);
    splay(y,0);
    int ll,rr,conn;
    ll=ch[x][0];
    rr=ch[y][1];
    conn=get_max(ll);
    pre[ll]=pre[rr]=0;
    ch[x][0]=ch[y][1]=0;
    if(conn!=0)ch[conn][1]=rr;
    pre[rr]=conn;
    if(b==0)return;
    if(query(b)==a)
    {
        ch[conn][1]=0;pre[rr]=0;
        ch[x][0]=ll;ch[y][1]=rr;
        pre[ll]=x;
        pre[rr]=y;
        pre[0]=0;
        return;
    }
    if(rr!=0)splay(rr,0);
    x=l[b];
    splay(x,0);
    y=get_min(ch[x][1]);
    splay(y,x);
    ch[y][0]=z;pre[z]=y;
}
void dfs(int x)
{
    ans.push_back(x);
    for(int i=0; i<vec[x].size(); i++)
    {
        dfs(vec[x][i]);
    }
    ans.push_back(-x);
}
int main()
{
    int n,x;
    int cas=0;
    while(~scanf("%d",&n))
    {
        if(cas)puts("");
        cas++;
        init();
        for(int i=0; i<=n; i++)vec[i].clear();
        ans.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            vec[x].push_back(i);
        }
        dfs(0);
        int len=0;
        int st=1;
        for(int i=1; i<ans.size()-1; i++)
        {
            if(ans[i]>0)len++;
            else len--;
            if(len==0)
            {
                buildtree(root,st,i,0);
                st=i+1;
            }
        }
        int m,x,y;
        char str[1110];
        scanf("%d",&m);
        while(m--)
        {
            cas++;
            scanf("%s",str);
            if(str[0]=='M')
            {
                scanf("%d%d",&x,&y);
                dos(x,y);
            }
            if(str[0]=='Q')
            {
                scanf("%d",&x);
                printf("%d\n",query(x));
            }
        }
    }
    return 0;
}
