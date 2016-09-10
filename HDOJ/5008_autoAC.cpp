#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define root 1,n,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define M 120010
#define INF 10000007
using namespace std;
typedef long long LL;
LL ran[M],sa[M],X[M],Y[M],high[M],init[M];
LL buc[M];
struct SegmentTree{
    LL Min[M << 2];
    void pushup(LL rt){
        Min[rt] = min(Min[rt<<1],Min[rt<<1|1]);
    }
    void build(LL l,LL r,LL rt){
        if(l == r){
            Min[rt] = sa[l];
            return;
        }
        LL mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    LL query(LL L,LL R,LL l,LL r,LL rt){
        if(L <= l && r <= R){
            return Min[rt];
        }
        LL mid = (l + r) >> 1;
        LL ans = INF;
        if(L <= mid) ans = min(query(L,R,lson),ans);
        if(mid + 1 <= R) ans = min(query(L,R,rson),ans);
        return ans;
    }
};
SegmentTree sgt;
void calhigh(LL n) {
    LL i , j , k = 0;
    for(i = 1 ; i <= n ; i++) ran[sa[i]] = i;
    for(i = 0 ; i < n ; high[ran[i++]] = k)
        for(k?k--:0 , j = sa[ran[i]-1] ; init[i+k] == init[j+k] ; k++);
}
bool cmp(LL *r,LL a,LL b,LL l) {
    return (r[a] == r[b] && r[a+l] == r[b+l]);
}
void suffix(LL n,LL m = 128) {
    LL i , l , p , *x = X , *y = Y;
    for(i = 0 ; i < m ; i ++) buc[i] = 0;
    for(i = 0 ; i < n ; i ++) buc[ x[i] = init[i]  ] ++;
    for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
    for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[i] ]] = i;
    for(l = 1,p = 1 ; p < n ; m = p , l *= 2) {
        p = 0;
        for(i = n-l ; i < n ; i ++) y[p++] = i;
        for(i = 0 ; i < n ; i ++) if(sa[i] >= l) y[p++] = sa[i] - l;
        for(i = 0 ; i < m ; i ++) buc[i] = 0;
        for(i = 0 ; i < n ; i ++) buc[ x[y[i]] ] ++;
        for(i = 1 ; i < m ; i ++) buc[i] += buc[i-1];
        for(i = n - 1; i >= 0 ; i --) sa[ --buc[ x[y[i]] ] ] = y[i];
        for(swap(x,y) , x[sa[0]] = 0 , i = 1 , p = 1 ; i < n ; i ++)
            x[ sa[i] ] = cmp(y,sa[i-1],sa[i],l) ? p-1 : p++;
    }
    calhigh(n-1);
}
LL Log[M];
LL best[20][M];
void initRMQ(LL n) {
    for(LL i = 1; i <= n ; i ++) best[0][i] = high[i];
    for(LL i = 1; i <= Log[n] ; i ++) {
        LL limit = n - (1<<i) + 1;
        for(LL j = 1; j <= limit ; j ++) {
            best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
        }
    }
}
LL lcp(LL a,LL b) {
    if(a>b)return 0;
    LL t = Log[b - a + 1];
    return min(best[t][a] , best[t][b - (1<<t) + 1]);
}
char str[M];
LL dlen[M];
void getlen(LL n,LL len){
    for(LL i=1;i<=n;i++){
        dlen[i]=len-sa[i]-high[i];
    }
    for(LL i=1;i<=n;i++){
        dlen[i]+=dlen[i-1];
    }
}
void findK(LL n,LL k,LL &start,LL &len){
    if(k>dlen[n]||k<=0){
        start=len=0;
        return ;
    }
    LL l=1,r=n;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(dlen[mid]>=k) r=mid-1;
        else l=mid+1;
    }
    start=l;
    len=k-dlen[start-1]+high[start];
}
LL findLcp(LL start,LL len,LL n){
    LL l=start + 1,r=n;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(lcp(start+1,mid)>=len)l=mid+1;
        else r=mid-1;
    }
    return sgt.query(start,r,root);
}
int main() {
    LL l,r,q;
    LL v,u;
    LL start,llen;
    Log[0] = -1;
    for(LL i = 1; i < M ; i ++) {
        Log[i] = (i&(i-1)) ? Log[i-1] : Log[i-1] + 1 ;
    }
    while(scanf("%s",str)!=EOF){
        l = r  = 0;
        LL n=strlen(str);
        for(LL i=0;i<n;i++)init[i]=str[i];
        init[n]=0;
        suffix(n+1);
        initRMQ(n);
        getlen(n,n);
        sgt.build(root);
        scanf("%I64d",&q);
        for(LL i=1;i<=q;i++){
            scanf("%I64d",&v);
            u=(l^r^v)+1;
            findK(n,u,start,llen);
            if(llen==0&&start==0){
                l=0,r=0;
                printf("0 0\n");
                continue;
            }
            LL ans=findLcp(start,llen,n);
            l=ans;r=ans+llen-1;
            l++;r++;
            printf("%I64d %I64d\n",l,r);
        }
    }
}
