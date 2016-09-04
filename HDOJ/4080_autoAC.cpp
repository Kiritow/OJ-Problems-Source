#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN=40000+5;
const int SIGMA_SIZE=26;
const int INF=~0U>>1;
struct State{
    State* go[SIGMA_SIZE],*suf;
    int val,cnt,right;
    State():suf(0) {val=cnt=0;memset(go,0,sizeof go);}
}*root,*last;
State mem[MAXN<<1],*cur;
int ans1,ans2;
int m;
inline void init()
{
    ans1=-1;
    cur=mem;
    mem[0]=State();
    last=root=cur++;
}
inline void extend(int w)
{
    State* p=last,*np=cur++;
    *np=State();
    np->right=np->val=p->val+1;
    while(p && !p->go[w]) p->go[w]=np,p=p->suf;
    if(!p) np->suf=root;
    else
    {
        State* q=p->go[w];
        if(q->val==p->val+1) np->suf=q;
        else
        {
            State* nq=cur++;
            *nq=State();
            memcpy(nq->go,q->go,sizeof q->go);
            nq->right=nq->val=p->val+1;
            nq->suf=q->suf;
            q->suf=np->suf=nq;
            while(p && p->go[w]==q) p->go[w]=nq,p=p->suf;
        }
    }
    last=np;
}
inline int idx(char c)
{
    return c-'a';
}
char s[MAXN];
int n;
State* pt[MAXN<<1];
void work()
{
    static int ws[MAXN<<1];
    State* t;
    for(int i=0;i<=n;++i) ws[i]=0;
    for(t=mem+1;t!=cur;++t) ++ws[t->val];
    for(int i=1;i<=n;++i) ws[i]+=ws[i-1];
    for(t=cur-1;t!=mem;--t) pt[--ws[t->val]]=t;
    t=root;
    for(int i=0;i<n;++i) t=t->go[idx(s[i])],t->cnt++;
    for(int i=cur-mem-2;i>=0;--i)
    {
        State* u=pt[i];
        if(u->cnt>=m)
        {
            if(u->val>ans1) ans1=u->val,ans2=u->right-u->val;
            else if(u->val==ans1) ans2=std::max(ans2,u->right-u->val);
        }
        if(u->suf)
            u->suf->cnt+=u->cnt,u->suf->right=std::max(u->suf->right,u->right);
    }
}
int main()
{
    while(scanf("%d",&m)!=EOF && m)
    {
        init();
        scanf("%s",s);
        n=strlen(s);
        if(m==1)
        {
            printf("%d 0\n",n);
            continue;
        }
        for(int i=0;i<n;++i)
            extend(idx(s[i]));
        work();
        if(ans1==-1) puts("none");
        else printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
