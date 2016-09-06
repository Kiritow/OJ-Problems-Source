#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 6000005
#define N 11005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct segment{
    int x1,x2,y,val;
    segment(){}
    segment(int _x1,int _x2,int _y,int _v):x1(_x1),x2(_x2),y(_y),val(_v){}
    bool operator<(const segment s)const{
        return y<s.y;
    }
}seg[N*2];
struct Node{
    int left,right,len[8],cnt[5];
}L[N*2*4];
int x[N*2]={-1},cnt;
LL ans[8];
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    mem(L[step].len,0);
    mem(L[step].cnt,0);
    if(l==r) return;
    int m=(l+r)>>1;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
}
void Push_Up(int step){
    int state=(L[step].cnt[1]>0?1:0)|(L[step].cnt[2]>0?2:0)|(L[step].cnt[4]>0?4:0);
    if(state){
        mem(L[step].len,0);
        L[step].len[state]=x[L[step].right+1]-x[L[step].left];
        for(int i=1;i<8;i++){
            if(state!=(state|i)){
                int tmp=L[lson].len[i]+L[rson].len[i];
                L[step].len[state|i]+=tmp;
                L[step].len[state]-=tmp;
            }
        }
    }
    else if(L[step].left!=L[step].right)
        for(int i=1;i<8;i++) L[step].len[i]=L[lson].len[i]+L[rson].len[i];
    else mem(L[step].len,0);
}
void Update(int step,int l,int r,int val){
    if(L[step].left==l&&r==L[step].right)
        val>0?++L[step].cnt[val]:--L[step].cnt[-val];
    else{
        int m=(L[step].left+L[step].right)>>1;
        if(r<=m) Update(lson,l,r,val);
        else if(l>m) Update(rson,l,r,val);
        else{
            Update(lson,l,m,val);
            Update(rson,m+1,r,val);
        }
    }
    Push_Up(step);
}
int Bin(int m){
    int low=1,high=cnt,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(x[mid]==m) return mid;
        if(x[mid]<m) low=mid+1;
        else high=mid-1;
    }
}
int main(){
    int t,cas=0,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char str[6];
            int x1,x2,y1,y2;
            scanf("%s%d%d%d%d",str,&x1,&y1,&x2,&y2);
            seg[2*i]=segment(x1,x2,y1,str[0]=='R'?1:(str[0]=='G'?2:4));
            seg[2*i+1]=segment(x1,x2,y2,str[0]=='R'?-1:(str[0]=='G'?-2:-4));
            x[2*i+2]=x1;x[2*i+1]=x2;
        }
        sort(seg,seg+2*n);
        sort(x+1,x+1+2*n);
        cnt=0;
        for(int i=1;i<=2*n;i++)
            if(x[i]!=x[cnt])
                x[++cnt]=x[i];
        Bulid(1,1,cnt);
        mem(ans,0);
        for(int i=0;i<2*n;i++){
            int l=Bin(seg[i].x1),r=Bin(seg[i].x2)-1;
            Update(1,l,r,seg[i].val);
            if(seg[i].y!=seg[i+1].y)
                for(int j=1;j<8;j++)
                    ans[j]+=(LL)(seg[i+1].y-seg[i].y)*(LL)L[1].len[j];
        }
        printf("Case %d:\n",++cas);
        printf("%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n",ans[1],ans[2],ans[4],ans[3],ans[5],ans[6],ans[7]);
    }
    return 0;
}
