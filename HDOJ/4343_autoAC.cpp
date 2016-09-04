#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=100050;
int n,m,opt[20][N*2],x[N*2],cnt;
struct node
{
    int l,r;
    void read(){ scanf("%d%d",&l,&r); x[cnt++]=l; x[cnt++]=r; }
    void print(){ printf("%d %d\n",l,r); }
    bool operator <(const node tmp) const{ return l<tmp.l||(l==tmp.l&&r<tmp.r); }
}no[N];
inline int getid(int val,bool f)
{
    if(!f) return lower_bound(x,x+cnt,val)-x;
    return upper_bound(x,x+cnt,val)-x-1;
}
int calc(int l,int r)
{
    if(l>r) return 0;
    if(l==cnt||r==-1) return 0;
    int ret=0;
    for(int i=19;i>=0;i--){
        if(opt[i][l]<=r) {
            ret+=(1<<i);
            l=opt[i][l];
        }
    }
    return ret;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=-1)
    {
        cnt=0;
        for(int i=0;i<n;i++){
            no[i].read();
        }
        sort(no,no+n);
        sort(x,x+cnt);
        cnt=unique(x,x+cnt)-x;
        for(int i=0;i<n;i++){
            no[i].l=getid(no[i].l,0);
            no[i].r=getid(no[i].r,1);
        }
        x[cnt]=cnt;
        int mn=cnt,r=n;
        for(int i=cnt-1;i>=0;i--)
        {
            while(r>0&&no[r-1].l>=i){
                r--;
                mn=min(mn,no[r].r);
            }
            opt[0][i]=mn;
        }
        for(int i=0;i<20;i++) opt[i][cnt]=cnt;
        for(int i=1;i<20;i++){
            for(int j=0;j<cnt;j++){
                opt[i][j]=opt[i-1][opt[i-1][j]];
            }
        }
        while(m--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l=getid(l,0); r=getid(r,1);
            printf("%d\n",calc(l,r));
        }
    }
    return 0;
}
