#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
struct fac
{
    LL fz,fm;
    fac(){}
    fac (LL a,LL b):fz(a),fm(b) {}
    fac fix()
    {
        LL d=__gcd(fz,fm);
        return fac(fz/d,fm/d);
    }
    fac operator + (const fac & b) const { return fac(fz*b.fm+fm*b.fz,fm*b.fm).fix(); }
    fac operator * (const fac & b) const { return fac(fz*b.fz,fm*b.fm).fix(); }
    fac operator / (const fac & b) const { return fac(fz*b.fm,fm*b.fz).fix(); }
    fac operator - (const fac & b) const { return fac(fz*b.fm-fm*b.fz,fm*b.fm).fix() ;}
};
struct node
{
    fac xs;
    int d[5],x[5];
    node () { 
        xs=fac(1,1);
        for(int i=0;i<5;i++) { d[i]=x[i]=0;}
    }
    node operator * (const node & b) const {
        node ans;
        ans.xs=xs*b.xs;
        for(int i=0;i<5;i++) {
            ans.d[i]=d[i]+b.d[i];
            ans.x[i]=x[i]+b.x[i];
        }
        return ans;
    }
    bool operator < (const node & b) const
    {
        for(int i=0;i<5;i++) {
            if(d[i]!=b.d[i]) return d[i]<b.d[i];
        }
        return 0;
    }
    bool operator == (const node & b)
    {
        for(int i=0;i<5;i++) if(d[i]!=b.d[i]) return false;
        return true;
    }
    void output()
    {
        cout << xs.fz << "/" << xs.fm << " ";
        for(int i=0;i<5;i++){
            cout << d[i] << " ";
        }
        for(int i=0;i<5;i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
};
vector <node> dep[10],ans;
vector <node> v_mult(vector <node> & a,vector <node> & b)
{
    vector<node> ans;
    int s1=a.size(),s2=b.size();
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            ans.push_back(a[i]*b[j]);
        }
    }
    return ans;
}
vector <node> v_exp(vector <node> & a,int b)
{
    vector <node> c=a;
    while(--b){
        c=v_mult(c,a);
    }
    return c;
}
void init()
{
    node a;
    dep[5].push_back(a);
    for(int i=4;i>=0;i--){
        int s=dep[i+1].size();
        vector <node > tmp;
        node b;
        b.d[i]=1;
        tmp.push_back(b);
        for(int j=0;j<i;j++){
            node b;
            b.xs=fac(-1,1);
            b.x[j]=1;
            tmp.push_back(b);
        }
        for(int j=0;j<s;j++){
            vector<node> q=v_exp(tmp,dep[i+1][j].x[i]+1);
            int s1=q.size();
            for(int k=0;k<s1;k++){
                node tt=dep[i+1][j]*q[k];
                tt.xs=tt.xs*fac(1,dep[i+1][j].x[i]+1);
                dep[i].push_back(tt);
            }
        }
    }
    sort(dep[0].begin(),dep[0].end());
    int ss=dep[0].size();
    node pre=dep[0][0];
    for(int i=1;i<ss;i++){
        if(dep[0][i]==pre){
            pre.xs=pre.xs+dep[0][i].xs;
        }
        else {
            if(pre.xs.fz) ans.push_back(pre);
            pre=dep[0][i];
        }
    }
    if(pre.xs.fz) ans.push_back(pre);
}
struct work
{
    int s1,s2,d;
    bool operator < (const work & b) const{
        return d<b.d;
    }
}tt[10];
int n;
int a[5],d[5];
fac cal()
{
    fac res=fac(0,1);
    for(size_ i=0;i<ans.size();i++){
        fac tmp=ans[i].xs;
        for(int j=0;j<5;j++){
            for(int k=0;k<ans[i].d[j];k++){
                tmp.fz=tmp.fz*d[j];
            }
        }
        tmp=tmp.fix();
        res=res+tmp;
    }
    return res;
}        
void dfs(fac & ans,int s,int t)
{
    if(s==5){
        for(int i=0;i<5;i++) d[i]=tt[i].d;
        for(int i=0;i<5;i++){
            if(a[i]){
                for(int j=i;j<5;j++) d[j]-=tt[i].s2;
            }
        }
        for(int i=3;i>=0;i--) {
            d[i]=min(d[i],d[i+1]);
            if(d[i]<0) return;
        }
        fac p=cal();
        if(t) ans=ans+p;
        else ans=ans-p;
        return;
    }
    a[s]=1;
    dfs(ans,s+1,1-t);
    a[s]=0;
    dfs(ans,s+1,t);
}
fac solve()
{
    while(n<5){
        tt[n].s2=1;
        tt[n++].d=2000;
    }
    fac ans=fac(0,1);
    dfs(ans,0,1);    
    for(int i=0;i<5;i++) ans.fm=ans.fm*tt[i].s2;
    return ans.fix();
}
int main()
{
    init();
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++) scanf("%d%d%d",&tt[i].s1,&tt[i].s2,&tt[i].d);
        sort(tt,tt+n);
        int flag=1;
        for(int i=0;i<n;i++){
            if(tt[i].s1==tt[i].s2){
                for(int j=i+1;j<n;j++) tt[j].d-=tt[i].s1;
                if(i==0) {
                    if(tt[i].s1>tt[i].d) { flag=0;break;}
                }
                else {
                    tt[i-1].d=min(tt[i-1].d,tt[i].d-tt[i].s1);
                }
                for(int j=i;j<n-1;j++){
                    tt[j]=tt[j+1];
                }
                i-- , n--;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) tt[j].d-=tt[i].s1;
            tt[i].s2-=tt[i].s1;
            if(tt[i].d<0) { flag=0;break;}
        }
        if(!flag) puts("Poor boy!");
        else if(n==0) puts("Congratulations!");
        else {
            fac ans=solve();
            if(ans.fm<0) { ans.fz=-ans.fz , ans.fm=-ans.fm;}
            if(ans.fz<=0) puts("Poor boy!");
            else if(ans.fz>=ans.fm) puts("Congratulations!");
            else printf("%I64d/%I64d\n",ans.fz,ans.fm);
        }          
    } 
}
