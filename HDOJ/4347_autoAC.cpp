#include<queue>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
const int N=55555,K=5;  
const int inf=0x3f3f3f3f;  
#define sqr(x) (x)*(x)  
int k,n,idx;     
struct point  
{  
    int x[K];  
    bool operator < (const point &u) const  
    {  
        return x[idx]<u.x[idx];  
    }  
}po[N];  
typedef pair<double,point>tp;  
priority_queue<tp>nq;  
struct kdTree  
{  
    point pt[N<<2];  
    int son[N<<2];  
    void build(int l,int r,int rt=1,int dep=0)  
    {  
        if(l>r) return;  
        son[rt]=r-l;  
        son[rt*2]=son[rt*2+1]=-1;  
        idx=dep%k;  
        int mid=(l+r)/2;  
        nth_element(po+l,po+mid,po+r+1);  
        pt[rt]=po[mid];  
        build(l,mid-1,rt*2,dep+1);  
        build(mid+1,r,rt*2+1,dep+1);  
    }  
    void query(point p,int m,int rt=1,int dep=0)  
    {  
        if(son[rt]==-1) return;  
        tp nd(0,pt[rt]);  
        for(int i=0;i<k;i++) nd.first+=sqr(nd.second.x[i]-p.x[i]);  
        int dim=dep%k,x=rt*2,y=rt*2+1,fg=0;  
        if(p.x[dim]>=pt[rt].x[dim]) swap(x,y);  
        if(~son[x]) query(p,m,x,dep+1);  
        if(nq.size()<m) nq.push(nd),fg=1;  
        else  
        {  
            if(nd.first<nq.top().first) nq.pop(),nq.push(nd);  
            if(sqr(p.x[dim]-pt[rt].x[dim])<nq.top().first) fg=1;  
        }  
        if(~son[y]&&fg) query(p,m,y,dep+1);  
    }  
}kd;  
void print(point &p)  
{  
    for(int j=0;j<k;j++) printf("%d%c",p.x[j],j==k-1?'\n':' ');  
}  
int main()  
{  
    while(scanf("%d%d",&n,&k)!=EOF)  
    {  
        for(int i=0;i<n;i++) for(int j=0;j<k;j++) scanf("%d",&po[i].x[j]);  
        kd.build(0,n-1);  
        int t,m;  
        for(scanf("%d",&t);t--;)  
        {  
            point ask;  
            for(int j=0;j<k;j++) scanf("%d",&ask.x[j]);  
            scanf("%d",&m); kd.query(ask,m);  
            printf("the closest %d points are:\n", m);  
            point pt[20];  
            for(int j=0;!nq.empty();j++) pt[j]=nq.top().second,nq.pop();  
            for(int j=m-1;j>=0;j--) print(pt[j]);  
        }  
    }  
    return 0;  
}
