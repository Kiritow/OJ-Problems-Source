#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define Maxn 250009
int root,last;
int tots;
int l;
int sv[Maxn*2];
struct query{int a;long long ans;}qu[Maxn];
struct sam_node{
    int fa,son[26];
    int len;
    void init(int _len){len=_len;fa=-1;memset(son,-1,sizeof(son));}
}t[Maxn*2];
void sam_init(){
    tots=0;
    root=last=0;
    t[tots].init(0);
}
void extend(int w){
    int p=last;
    int np=++tots;t[tots].init(t[p].len+1);
    sv[l]=np;
    int q,nq;
    while(p!=-1&&t[p].son[w]==-1){t[p].son[w]=np;p=t[p].fa;}
    if (p==-1) t[np].fa=root;
    else{
        q=t[p].son[w];
        if (t[p].len+1==t[q].len){t[np].fa=q;}
        else{
            nq=++tots;t[nq].init(0);
            t[nq]=t[q];
            t[nq].len=t[p].len+1;
            t[q].fa=nq;t[np].fa=nq;
            while(p!=-1&&t[p].son[w]==q){t[p].son[w]=nq;p=t[p].fa;}
        }
    }
    last=np;
}
int w[Maxn],r[Maxn*2];
void topsort(){
    int i;
    for(i=0;i<=l;++i)   w[i]=0;
    for(i=1;i<=tots;++i)w[t[i].len]++;
    for(i=1;i<=l;++i)   w[i]+=w[i-1];
    for(i=tots;i>=1;--i)r[w[t[i].len]--]=i;
    r[0]=0;
}
int dp[Maxn*2];
int sub[Maxn*2];
char s[Maxn];
int set[Maxn*2];
int findset(int x){
    int y;
    while(x!=set[x]){
        y=set[x];
        set[x]=set[y];
        x=y;
    }
    return x;
}
int main(){
    int n,m,k,f,y,p,i,a;
    long long ans;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        scanf("%s",s);
        int tl=strlen(s);
        l=0;
        sam_init();
        for(i=0;i<tl;++i){
            ++l;
            extend(s[i]-'a');
        }
        char ts[20];
        for(i=1;i<=m;++i){
            scanf("%d",&a);
            if (a==1){
                scanf("%s",ts);
                s[l++]=ts[0];
                qu[i].a=a;
                extend(ts[0]-'a');
            }
            else if (a==2) qu[i].a=a;
        }
        for(i=0;i<=tots;++i){dp[i]=0;}
        topsort();
        p=root;
        for(i=0;i<l;++i){
            p=t[p].son[s[i]-'a'];
            dp[p]++;
        }
        for(i=tots;i>=1;--i){
            p=r[i];
            if (t[p].fa!=-1) dp[t[p].fa]+=dp[p];
        }
        ans=0;
        for(i=1;i<=tots;++i)
            if (dp[i]>=k) ans+=t[i].len-t[t[i].fa].len;
        for(i=0;i<=tots;++i){set[i]=i;sub[i]=0;}
        for(i=m;i>=1;--i){
            if (qu[i].a==2) qu[i].ans=ans;
            else{
                p=sv[l];
                l--;
                y=findset(p);
                while(y!=0&&dp[y]<k){          
                    f=t[y].fa;
                    set[y]=f=findset(f);
                    y=f;
                }
                y=findset(p);
                if (y==root) {continue;}
                sub[y]++;
                while(y!=0&&(dp[y]-sub[y]<k)){   
                    ans=ans-t[y].len+t[t[y].fa].len;
                    f=t[y].fa;
                    f=findset(f);
                    sub[f]+=sub[y];
                    set[y]=f;
                    y=f;
                }
            }
        }
        for(i=1;i<=m;++i)if (qu[i].a==2){
            printf("%I64d\n",qu[i].ans);
        }
    }
    return 0;
}
