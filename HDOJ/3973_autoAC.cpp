#include<cstdio>  
#include<cstring>  
#include<map>  
#define maxn 100010  
#define p 33  
using namespace std;  
typedef unsigned long long ll;  
struct Tree{  
    int l,r;  
    ll hashes;  
}tree[300000];  
char str[2000100];  
ll hh[maxn];  
void init(){  
    int i;  
    hh[0]=1;  
    for(i=1;i<=maxn;i++)  
        hh[i]=hh[i-1]*p;  
}  
ll calhash(){  
    int i,len=strlen(str);  
    ll sum=0;  
    for(i=0;i<len;i++)  
        sum=sum*p+str[i]-'a'+1;  
    return sum;  
}  
void build(int s,int t,int id){  
    tree[id].l=s;tree[id].r=t;  
    if(s==t){  
        tree[id].hashes=str[s]-'a'+1;  
        return;  
    }  
    int mid=(s+t)>>1;  
    build(s,mid,id<<1);  
    build(mid+1,t,id<<1|1);  
    tree[id].hashes=tree[id<<1].hashes*hh[t-mid]+tree[id<<1|1].hashes;  
}  
void update(int l,int id){  
    if(tree[id].l==tree[id].r){  
        tree[id].hashes=str[l]-'a'+1;  
        return ;  
    }  
    int mid=(tree[id].l+tree[id].r)>>1;  
    if(l<=mid) update(l,id<<1);  
    else update(l,id<<1|1);  
    tree[id].hashes=tree[id<<1].hashes*hh[tree[id].r-mid]+tree[id<<1|1].hashes;  
}  
ll query(int s,int t,int id){  
    if(tree[id].l==s && tree[id].r==t)  
        return tree[id].hashes;  
    int mid=(tree[id].l+tree[id].r)>>1;  
    if(t<=mid) return query(s,t,id<<1);  
    else if(s>mid) return query(s,t,id<<1|1);  
    return query(s,mid,id<<1)*hh[t-mid]+query(mid+1,t,id<<1|1);  
}  
int main(){  
    int t,T,pos,l,r,i,q,n;  
    char s1[10],s2[10];  
    map<ll,int>mp;  
    init();  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        printf("Case #%d:\n",t);  
        scanf("%d",&n);  
        mp.clear();  
        for(i=1;i<=n;i++){  
            scanf("%s",str);  
            mp.insert(make_pair(calhash(),1));  
        }  
        scanf("%s",str);  
        int len=strlen(str);  
        build(0,len-1,1);  
        scanf("%d",&q);  
        for(i=1;i<=q;i++){  
            scanf("%s",s1);  
            if(s1[0]=='C'){  
                scanf("%d%s",&pos,s2);  
                str[pos]=s2[0];  
                update(pos,1);  
            }  
            else{  
                scanf("%d %d",&l,&r);  
                if(mp.find(query(l,r,1))!=mp.end()) printf("Yes\n");  
                else printf("No\n");  
            }  
        }  
    }  
}
