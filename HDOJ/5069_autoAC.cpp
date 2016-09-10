#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long long
#define mod 1000000007
#define maxn 200010
#define INF 0x3f3f3f3f
using namespace std;
struct node
{
    int u,id;
    bool operator<(const node&s)const
    {
        return u < s.u ;
    }
};
struct SAM
{
    SAM *pre,*son[4] ;
    int len ,vi;
    void init()
    {
        pre=NULL ;
        memset(son,NULL,sizeof(son)) ;
        vi=0;
    }
}que[maxn*2],*root,*tail,*b[maxn];
int tot,ans[maxn] ,cnt[maxn],s[maxn];
int id(char a )
{
    if(a=='A') return 0 ;
    else if(a=='C') return 1 ;
    else if(a=='G') return 2 ;
    return 3 ;
}
vector<node>qe[maxn] ;
void add(int c ,int l)
{
    que[tot].init();
    SAM *p = tail,*np=&que[tot++] ;
    np->len=l;tail=np ;
    while(p&&p->son[c]==NULL)p->son[c]=np,p=p->pre ;
    if(p==NULL) np->pre = root ;
    else
    {
        SAM *q = p->son[c] ;
        if(p->len+1==q->len)np->pre = q ;
        else
        {
            que[tot].init();
            SAM *nq = &que[tot++] ;
            *nq=*q ;
            nq->len = p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
}
char str[maxn] ;
int main()
{
    int i , j ,k ,len,n , m;
    int u,v ;
    node a ;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(i=1;i<=n;i++)
          qe[i].clear();
        len=1;
        for( i = 1 ; i <= n ;i++)
        {
            scanf("%s",str+len) ;
            k = strlen(str+len) ;
            s[i]=len;
            cnt[i]=k;
            len += k+1 ;
        }
        for( i = 1 ; i <= m ;i++)
        {
            scanf("%d%d",&u,&v) ;
            a.id = i ;
            a.u = v ;
            qe[u].push_back(a);
        }
        for( i = 1 ; i <= n ;i++)
        {
            if(qe[i].size()==0) continue ;
            sort(qe[i].begin(),qe[i].end());
            tot=0;
            que[0].init();
            root=tail=&que[tot++];
            k=1;
            for( j = s[i] ; j < s[i]+cnt[i];j++){
                add(id(str[j]),k++);
            }
            SAM *p= tail;
            while(p != NULL )
            {
                p->vi = true;
                p=p->pre;
            }
            for( j = 0 ; j < qe[i].size();j++){
                a=qe[i][j] ;
                ans[a.id]=0;
                if(j&&a.u==qe[i][j-1].u)
                {
                    ans[a.id]=ans[qe[i][j-1].id];
                    continue ;
                }
                p = root ;
                int tmp=0;
                for( k = s[a.u] ; k < s[a.u]+cnt[a.u];k++)
                {
                    int v = id(str[k]) ;
                    if(p->son[v]==NULL) break ;
                    p=p->son[v] ;
                    tmp++;
                    if(p->vi)
                        ans[a.id]=max(ans[a.id],tmp);
                }
            }
        }
        for( i = 1 ; i <= m ;i++)
            printf("%d\n",ans[i]);
    }
    return 0 ;
}
