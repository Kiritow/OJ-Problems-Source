#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 30005
int a[N];
int n,k,m;
int len,tot;
int l1,l2,r1,r2;
int ans[N],c[N*2];
struct node{
    int l,r,id,p;
    void set(int i,int ll,int rr,int pp){
        id=i;l=ll;r=rr;p=pp;
    }
}f[N*4];
bool cmp(node a,node b){
    if(a.l/len!=b.l/len) return a.l/len<b.l/len;
    return a.r<b.r;
}
void solve(){
    int nl=1;
    int nr=0;
    int res=0;
    for(int i=0;i<tot;i++)
    {
        while(nl>f[i].l){
            nl--;
            if(k>a[nl]) res+=c[k-a[nl]];
            c[a[nl]]++;
        }
        while(nr<f[i].r){
            nr++;
            if(k>a[nr]) res+=c[k-a[nr]];
            c[a[nr]]++;
        }
        while(nl<f[i].l){
            if(k>a[nl]) res-=c[k-a[nl]];
            c[a[nl]]--;
            nl++;
        }
        while(nr>f[i].r){
            if(k>a[nr]) res-=c[k-a[nr]];
            c[a[nr]]--;
            nr--;
        }
        ans[f[i].id]+=res*f[i].p;
    }
}
int main()
{
    while(~scanf("%d",&n)){
        scanf("%d",&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(c,0,sizeof(c));
        scanf("%d",&m);
        tot=0;
        for(int i=1;i<=m;i++)
        {
            ans[i]=0;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            f[tot++].set(i,l1,r2,1);
            f[tot++].set(i,l1,l2-1,-1);
            f[tot++].set(i,r1+1,r2,-1);
            if(r1+1<=l2-1) f[tot++].set(i,r1+1,l2-1,1);
        }
        len=sqrt(n);
        sort(f,f+tot,cmp);
        solve();
        for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    }
    return 0;
}
