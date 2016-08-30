#include<cstdio>  
const int maxn=444444;  
int prime[]={ 2, 3, 5, 7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};  
int  dpos[]={28,25,23,21,20,19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};  
int a[]={1,2,4,8,16,32,64};  
int b[]={1,3,9,27,81};  
int c[]={1,5,25};  
int d[]={1,7,49};  
#define lson l,mid,lrt  
#define rson mid+1,r,rrt  
#define mid ((l+r)>>1)  
#define lrt rt<<1  
#define rrt rt<<1|1  
int MAX[maxn],MIN[maxn];  
inline int turn(int x){  
    int cnt,y=0;  
    for(int i=0;i<25&&x>1;i++){  
    for(cnt=0;x%prime[i]==0;x/=prime[i]) cnt++;  
    y|=cnt<<dpos[i];  
    }  
    return y;  
}  
inline int back(int x,int p)  
{  
    long long y=1;  
    int k=x>>dpos[0];y=y*a[k]%p;x^=k<<dpos[0];  
    k=x>>dpos[1];y=y*b[k]%p;x^=k<<dpos[1];  
    k=x>>dpos[2];y=y*c[k]%p;x^=k<<dpos[2];  
    k=x>>dpos[3];y=y*d[k]%p;x^=k<<dpos[3];  
    for(int i=4;i<25;i++)  
    if(x&(1<<dpos[i])) y=y*prime[i]%p;  
    return y;  
}  
#define _min(x,y) ((x)<(y)?(x):(y))  
#define _max(x,y) ((x)>(y)?(x):(y))  
inline int min(int x,int y){  
    return _min(x&0x70000000,y&0x70000000)|_min(x&0x0e000000,y&0x0e000000)|_min(x&0x01800000,y&0x01800000)|_min(x&0x00600000,y&0x00600000)|((x&0x001fffff)&(y&0x001fffff));  
}  
inline int max(int x,int y){  
    return _max(x&0x70000000,y&0x70000000)|_max(x&0x0e000000,y&0x0e000000)|_max(x&0x01800000,y&0x01800000)|_max(x&0x00600000,y&0x00600000)|((x&0x001fffff)|(y&0x001fffff));  
}  
inline void pushup(int rt){  
    MAX[rt]=max(MAX[lrt],MAX[rrt]);  
    MIN[rt]=min(MIN[lrt],MIN[rrt]);  
}  
void build(int l,int r,int rt){  
    if(l==r){  
    int x;scanf("%d",&x);  
    MIN[rt]=MAX[rt]=turn(x);  
    return;  
    }  
    build(lson);build(rson);  
    pushup(rt);  
}  
void update(int k,int x,int l,int r,int rt){  
    if(l==r){  
    MAX[rt]=MIN[rt]=turn(x);  
    return;  
    }  
    if(k<=mid) update(k,x,lson);  
    else update(k,x,rson);  
    pushup(rt);  
}  
int query_max(int s,int t,int l,int r,int rt){  
    if(s<=l&&t>=r) return MAX[rt];  
    int ret=0;  
    if(s<=mid) ret=max(ret,query_max(s,t,lson));  
    if(t>mid)  ret=max(ret,query_max(s,t,rson));  
    return ret;  
}  
int query_min(int s,int t,int l,int r,int rt){  
    if(s<=l&&t>=r) return MIN[rt];  
    int ret=0x7fffffff;  
    if(s<=mid) ret=min(ret,query_min(s,t,lson));  
    if(t>mid)  ret=min(ret,query_min(s,t,rson));  
    return ret;  
}  
int main()  
{  
    int n,q;  
    while(scanf("%d%d",&n,&q)!=EOF){  
    build(1,n,1);  
    char s[2];  
    while(q--){  
        scanf("%s",s);  
        if(s[0]=='C'){  
        int k,v;  
        scanf("%d%d",&k,&v);  
        update(k,v,1,n,1);  
        }  
        else if(s[0]=='L'){  
        int k1,k2,p;  
        scanf("%d%d%d",&k1,&k2,&p);  
        int x=query_max(k1,k2,1,n,1);  
        printf("%u\n",back(x,p));  
        }  
        else{  
        int k1,k2,p;  
        scanf("%d%d%d",&k1,&k2,&p);  
        int x=query_min(k1,k2,1,n,1);  
        printf("%u\n",back(x,p));  
        }  
    }  
    }  
    return 0;  
}
