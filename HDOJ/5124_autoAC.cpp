#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct line{
        int l,r;
};
bool operator < (const line &a,const line &b)
{
        if(a.r<b.r)return 1;
        if(a.r==b.r){
                if(a.l<b.l)return 1;
        }
        return 0;
}
line L[100005];
int pos[200005];
int d[400005];
int maxv[400005];
int yl,yr;
void maintain(int o,int l,int r)
{
        int lc=o*2;
        int rc=o*2+1;
        if(r>l){
                maxv[o]=max(maxv[lc],maxv[rc]);
        }else maxv[o]=0;
        maxv[o]+=d[o];
}
void update(int o,int l,int r)
{
        int lc=o*2;
        int rc=o*2+1;
        if(yl<=l&&yr>=r){
                d[o]++;
        } else {
                int mid=l+((r-l)>>1);
                if(yl<=mid)update(lc,l,mid);
                if(yr>mid)update(rc,mid+1,r);
        }
        maintain(o,l,r);
}
int query(int o,int l,int r,int add)
{
        if(yl<=l&&yr>=r){
                return maxv[o]+add;
        } else {
                int m=l+((r-l)>>1);
                int ret=-1;
                if(yl<=m)ret=max(ret,query(o*2 , l , m , add + d[o] ) );
                if(yr>m)ret=max(ret , query(o*2+1 , m+1 , r , add+d[o]));
                return ret;
        }
}
int bisearch(int x,int tot)
{
        int le=0;
        int ri=tot-1;
        while(le<ri){
                int mid=(le+ri)>>1;
                if(pos[mid]==x)return mid;
                if(pos[mid]>x)ri=mid-1;
                else {
                        le=mid+1;
                }
        }
        return le;
}
int main()
{
        int T;
        scanf("%d",&T);
        while(T--){
                int n;
                scanf("%d",&n);
                int tot=0;
                set<int> s;
                s.clear();
                for(int i=0;i<n;++i){
                        scanf("%d%d",&L[i].l,&L[i].r);
                        if(s.find(L[i].l)==s.end()){
                                s.insert(L[i].l);
                                pos[tot++]=L[i].l;
                        }
                        if(s.find(L[i].r)==s.end()){
                                s.insert(L[i].r);
                                pos[tot++]=L[i].r;
                        }
                }
                sort(pos,pos+tot);
                for(int i=0;i<=tot*4;++i){
                        d[i]=0;
                        maxv[i]=0;
                }
                int ans=0;
                for(int i=0;i<n;++i){
                       int le=bisearch(L[i].l,tot);
                       int ri=bisearch(L[i].r,tot);
                       le++;
                       ri++;
                       yl=le;
                       yr=ri;
                       update(1,1,tot);
                }
                yl=1;yr=tot;
                ans=query(1,1,tot,0);
                printf("%d\n",ans);
        }
        return 0;
}
