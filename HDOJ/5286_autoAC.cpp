#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
const int maxn=51005;
const int mod=1000000007;
struct pi{
    int sum;
    int lson;
    int rson;
}pp[maxn*17];
int root[maxn],tot;
void build(int cnt,int l,int r){
    pp[cnt].sum=0;
    if(l==r) return;
    pp[cnt].lson=tot+1;
    tot++;
    build(tot,l,(l+r)/2);
    pp[cnt].rson=tot+1;
    tot++;
    build(tot,(l+r)/2+1,r);
}
void merg(int qq,int cnt,int n,int p,int k){
    int le,ri,mid;
    le=1;
    ri=n;
    while(le<=ri){
        mid=(le+ri)/2;
        pp[cnt]=pp[qq];
        pp[cnt].sum+=k;
        if (le==ri) break;
        if(p<=mid){
            pp[cnt].lson=tot+1;
            tot++;
            ri=mid;
            cnt=tot;
            qq=pp[qq].lson;
        }
        else{
            pp[cnt].rson=tot+1;
            tot++;
            le=mid+1;
            cnt=tot;
            qq=pp[qq].rson;
        }
    }
}
int query(int cnt,int le,int ri,int l,int r){
    int s=0;
    int mid;
    if(le>=l&&ri<=r){
        return pp[cnt].sum;
    }
    mid=(le+ri)/2;
    if(l<=mid) s+=query(pp[cnt].lson,le,mid,l,r);
    if(r>mid) s+=query(pp[cnt].rson,mid+1,ri,l,r);
    return s;
}
int a[maxn],b[maxn],c[maxn];
int l[maxn],vis[maxn],r[505],le[505];
int g[315][315];
vector<int>gg[maxn],g1;
int d[maxn][300];
int main()
{
    int i,j,n,m,t;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
            gg[i].clear();
        }
        sort(b+1,b+1+n);
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++){ a[i]=lower_bound(b+1,b+1+n,a[i])-b;
            vis[a[i]]++;
        }
        for(i=1;i<=n;i++){
            long long q=1;
            gg[i].push_back(0);
            for(j=1;j<=vis[i];j++){
                q=q*b[i];
                q%=mod;
                gg[i].push_back(q);
            }
        }
        int p=sqrt(n),f=0;
        for(i=1;i<=n;i++){
            f++;
            int q=min(i+p-1,n);
            r[f]=q;
            le[f]=i;
            for(j=1;j<=n;j++){
                d[j][f]=d[j][f-1];
            }
            for(j=i;j<=q;j++){
                l[j]=f;
                d[a[j]][f]++;
            }
            i=q;
        }
        memset(g,0,sizeof(g));
        for(i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            for(j=i;j<=n;j++){
                vis[a[j]]++;
                if(j==i||l[j]!=l[j-1]){
                    g[l[i]][l[j]]=(g[l[i]][l[j]-1]+gg[a[j]][vis[a[j]]])%mod-gg[a[j]][vis[a[j]]-1];
                    g[l[i]][l[j]]%=mod;
                }
                else{
                    g[l[i]][l[j]]+=(gg[a[j]][vis[a[j]]]-gg[a[j]][vis[a[j]]-1])%mod;
                    g[l[i]][l[j]]%=mod;
                }
            }
            i+=p-1;
        }
        memset(vis,0,sizeof(vis));
        int la=0;
        for(i=0;i<m;i++){
            int x,y,ll,rr;
            scanf("%d%d",&x,&y);
            ll=x;
            rr=y;
            x=min((ll^la)%n+1,(rr^la)%n+1);
            y=max((ll^la)%n+1,(rr^la)%n+1);
            g1.clear();
            if(l[y]-l[x]<=1){
                for(j=x;j<=y;j++){
                    if(vis[a[j]]==0) g1.push_back(a[j]);
                    vis[a[j]]++;
                }
                int s=0;
                int p=g1.size();
                for(j=0;j<p;j++){
                    s+=gg[g1[j]][vis[g1[j]]];
                    vis[g1[j]]=0;
                    s%=mod;
                }
                s=(s+mod)%mod;
                printf("%d\n",s);
                la=s;
            }
            else{
                int s=0;
                s=g[l[x]+1][l[y]-1];
                for(j=x;j<=r[l[x]];j++){
                    if(!vis[a[j]]) g1.push_back(a[j]);
                    vis[a[j]]++;
                }
                for(j=le[l[y]];j<=y;j++){
                    if(!vis[a[j]]) g1.push_back(a[j]);
                    vis[a[j]]++;
                }
                int p=g1.size();
                for(j=0;j<p;j++){
                    int v=g1[j];
                    int q=d[v][l[y]-1]-d[v][l[x]];
                    s+=(gg[v][q+vis[v]]-gg[v][q])%mod;
                    s%=mod;
                    vis[v]=0;
                }
                s=(s%mod+mod)%mod;
                printf("%d\n",s);
                la=s;
            }
        }
    }
}
