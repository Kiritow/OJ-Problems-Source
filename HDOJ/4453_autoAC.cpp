#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define LL(x)    (ch[x][0])
#define RR(x)    (ch[x][1])
#define Kt       (ch[ ch[Rt][1] ][0])
#define MID(a,b) (a+((b-a)>>1))
const int N=1e6+5;
int n,m,k1,k2;
int a[N/2];
struct SplayTree
{
    int Rt,top;
    int pre[N],sz[N],ch[N][2];
    int key[N],add[N],pos;
    bool flip[N];
    inline void Link(int x,int y,int f)
    {
        pre[x]=y; if(y) ch[y][f]=x;
    }
    inline void Rotate(int x,int f)
    {
        int y=pre[x],z=pre[y];
        PushDown(y); PushDown(x);
        Link(x,z,RR(z)==y);
        Link(ch[x][f],y,!f);
        Link(y,x,f);
        PushUp(y);
    }
    inline void Splay(int x,int goal)
    {
        while(pre[x]!=goal)
        {
            int y=pre[x],z=pre[y];
            int cx=(LL(y)==x),cy=(LL(z)==y);
            if(z==goal) Rotate(x,cx);
            else
            {
                if(cx==cy) Rotate(y,cy);
                else Rotate(x,cx);
                Rotate(x,cy);
            }
        }
        PushUp(x);
        if(goal==0) Rt=x;
    }
    inline void Select(int K,int goal)
    {
        int x=Rt;
        PushDown(x);
        while(1)
        {
            if(sz[LL(x)]>=K) x=LL(x);
            else if(sz[LL(x)]+1==K) break;
            else K-=sz[LL(x)]+1,x=RR(x);
            PushDown(x);
        }
        Splay(x,goal);
    }
    inline void fun_add(int x,int valu)
    {
        add[x]+=valu;
        key[x]+=valu;
    }
    inline void fun_flip(int x)
    {
        flip[x]^=1;
        swap(LL(x),RR(x));
    }
    inline void PushDown(int x)
    {
        if(add[x])
        {
            fun_add(LL(x),add[x]);
            fun_add(RR(x),add[x]);
            add[x]=0;
        }
        if(flip[x])
        {
            fun_flip(LL(x));
            fun_flip(RR(x));
            flip[x]=0;
        }
    }
    inline void PushUp(int x)
    {
        sz[x]=1+sz[LL(x)]+sz[RR(x)];
    }
    inline void Add(int x)
    {
        Select(1,0); Select(k2+2,Rt);
        fun_add(Kt,x);
    }
    inline void Reverse()
    {
        Select(1,0); Select(k1+2,Rt);
        fun_flip(Kt);
    }
    inline void Insert(int x,int pos)
    {
        Select(pos,0); Select(pos+1,Rt);
        addNode(x,Kt,RR(Rt));
        PushUp(RR(Rt)); PushUp(Rt);
    }
    inline int Delete(bool top)
    {
        int valu;
        if(top)
        {
            Select(1,0);    Select(3,Rt);
            valu=key[Kt];
            Kt=0;
            PushUp(RR(Rt)); PushUp(Rt);
        }
        else
        {
            int len=sz[Rt];
            Select(len-2,0);Select(len,Rt);
            valu=key[Kt];
            Kt=0;
            PushUp(RR(Rt)); PushUp(Rt);
        }
        return valu;
    }
    inline void Move(int x)
    {
        if(x==1)
        {
            int valu=Delete(0);
            Insert(valu,1);
        }
        else
        {
            int valu=Delete(1);
            Insert(valu,sz[Rt]-1);
        }
    }
    inline void Query()
    {
        Select(2,0);
        printf("%d\n",key[Rt]);
    }
    void addNode(int valu,int &x,int f)
    {
        x=++top;
        pre[x]=f; sz[x]=1; LL(x)=RR(x)=0;
        key[x]=valu; add[x]=flip[x]=0;
    }
    void build(int lft,int rht,int &x,int f)
    {
        if(lft>rht) return;
        int mid=MID(lft,rht);
        addNode(a[mid],x,f);
        build(lft,mid-1,LL(x),x);
        build(mid+1,rht,RR(x),x);
        PushUp(x);
    }
    void init()
    {
        Rt=top=0;
        pre[0]=sz[0]=LL(0)=RR(0)=0;
        addNode(0,Rt,0);    addNode(0,RR(Rt),Rt);
        build(0,n-1,Kt,RR(Rt));
        PushUp(RR(Rt));     PushUp(Rt);
    }
}spt;
int main()
{
    int t_cnt=0;
    while(scanf("%d%d%d%d",&n,&m,&k1,&k2)!=EOF)
    {
        if(n==0&&m==0&&k1==0&&k2==0) break;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        spt.init();
        printf("Case #%d:\n",++t_cnt);
        char op[100]; int x;
        while(m--)
        {
            scanf("%s",op);
            if(op[0]=='a')
            {
                scanf("%d",&x); spt.Add(x);
            }
            else if(op[0]=='r') spt.Reverse();
            else if(op[0]=='i')
            {
                scanf("%d",&x); spt.Insert(x,2);
            }
            else if(op[0]=='d') spt.Delete(1);
            else if(op[0]=='m')
            {
                scanf("%d",&x); spt.Move(x);
            }
            else spt.Query();
        }
    }
    return 0;
}
