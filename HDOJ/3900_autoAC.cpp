#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define ll long long
struct data
{
    int t,l,c;  
}B[3545];       
int n,r;   
#include<map>
#include<queue>
#include<set>
map<ll,bool > vis;
ll s;
inline bool check(ll s,int x) 
{
    int tx=(s&(7ll<<(x*3)))>>(x*3);
    for(int i=0;i<n;i++)
    {
        if(i==x) continue;
        int ti=(s&(7ll<<(i*3)))>>(i*3);
        if(B[x].t==B[i].t) {
            if(B[x].c!=B[i].c) continue;
            if(tx+B[x].l<=ti||ti+B[i].l<=tx) continue;
            return 0;
        } else {
            if(tx+B[x].l>B[i].c&&B[i].c>=tx&&
               ti<=B[x].c&&B[x].c<B[i].l+ti) {
                return 0;
            }
        }
    }
    return 1;
}
inline bool done(ll s)
{
    for(int i=0;i<n;i++) {
        if(B[i].t==1) continue;
        int tt= ((s&(7ll<<(3*r)))>>(r*3));
        if(B[i].c<tt+B[r].l) continue;
        int l=((s&(7ll<<(3*i)))>>(i*3)) , r=l+B[i].l;
        if(r<=2||l>2) continue;
        return 0;
    }
    return 1;
}
inline void cover(ll& s,int x,int p)
{
    s&=~(7ll<<(x*3));
    s|=(ll)p<<(x*3);
}
#define pii  pair<ll,int>
#define  mp  make_pair
int bfs(ll s)
{
    if(done(s)) return 1;
    queue< pii  > q;
    q.push(mp(s,0));
    vis.clear();
    vis[s]=1;
    while(!q.empty()) {
        pii tt=q.front(); q.pop();
        ll u=tt.first;
        int d=tt.second+1;
        for(int i=0;i<n;i++) {
            int p=(u&(7ll<<(i*3)))>>(i*3);
            for(int j=1;j<=p;j++) {
                ll v=u;
                cover(v,i,p-j);
                if(!check(v,i)) break;
                if(done(v)) return d+1;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(mp(v,d));
            }
            for(int j=1;p+j+B[i].l<=6;j++) {
                ll v=u;
                cover(v,i,p+j);
                if(!check(v,i)) break;
                if(done(v)) return d+1;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(mp(v,d));
            }
        }
    }
    return -1;
}
int main()
{
    while(cin>>n&&n)
    {
       ll s=0;
        for(int i=0;i<n;i++)
        {
            int t,lx,ly,rx,ry;
            cin>>t>>lx>>ly>>rx>>ry;
            if(lx==rx) {
                B[i].t=0;
                B[i].l=ry-ly+1;
                B[i].c=lx;
                s|=((ll)ly<<(3*i));
            }
            else {
                B[i].t=1;
                B[i].l=rx-lx+1;
                B[i].c=ly;
                s|=((ll)lx<<(3*i));
            }
        }
        cin>>r;
        cout<<bfs(s)<<endl;
    }
}
