#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const double eps=1e-8;
int pr[1231];
struct A{vector<int> a;double s;}e,te;
struct P{int p[100],n;double s;}p,da;
long long mx;
int pt1(A &e,int n){
    double k=1;
    for(int i=0;i<n;i++){
        k*=pow(pr[i]+0.0,e.a[i]+0.0);
        if(k>p.s*1.00000001)return 0;
    }
    return 1;
}
void cf(P &p,int k){
    p.p[p.n]=0;
    for(int i=0;i<p.n;i++)
        p.p[i]*=k;
    for(int i=0;i<p.n;i++)
        p.p[i+1]+=p.p[i]/10,p.p[i]%=10;
    while(p.p[p.n]){
        p.p[p.n+1]=p.p[p.n]/10;
        p.p[p.n]%=10;
        p.n++;
    }
}
P qiu(A &a,int n){
    P p;
    p.n=1;
    p.p[0]=1;
    for(int i=0;i<n;i++)
        for(int q=0;q<a.a[i];q++)
            cf(p,pr[i]);
    return p;
}
int pt(P a,P b){
    if(a.n!=b.n){
        return a.n<b.n;
    }
    for(int i=a.n;i--;){
        if(a.p[i]!=b.p[i])
            return a.p[i]<b.p[i];
    }
    return 1;
}
int s[123],x[123];
int n;
long long js(A &e,int n){
    long long da=1;
    for(int i=0;i<n;i++)
        da*=e.a[i]+1;
    return da;
}
void dfs(int rt,A& e,long long k){
    if(rt>n)return ;
    if(k>=mx){
        if(!pt1(e,rt))return ;
        if(k>mx||(k==mx&& pt(qiu(e,rt),da))){
            if(!pt(qiu(e,rt),p))return ;
            mx=k;
            da=qiu(e,rt);
        }
    }
    int ss=s[rt];
    if(rt)ss=min(ss,e.a[rt-1]);
    for(int i=ss;i>=x[rt];i--){
        e.a[rt]=i;
        dfs(rt+1,e,k*(e.a[rt]+1));
    }
}
int gs(int k){ return 2*(log(pr[n]+0.0)/log(k+0.0))-1;}
int gx(int k){ return (log(pr[n]+0.0)/log(k+0.0));}
void qiu(){
    for(n=1;;n++){
        e.a.clear();
        for(int i=0;i<n;i++)
            s[i]=gs(pr[i]),x[i]=gx(pr[i]);
        if(x[0]<3)x[0]=1;
        for(int i=0;i<n;i++)
            e.a.push_back(1);
        if(!pt1(e,n))break;
    }
    if(n<15)
        for(int i=0;i<n;i++)
            x[i]=1;
    e.a.clear();
    for(int i=0;i<n;i++)e.a.push_back(0);
    dfs(0,e,1);
}
int main(){
    int ind=0;
    for(int i=2;i<1e3;i++){
        if(pr[i]==0){
            pr[ind++]=i;
            for(int q=i*i;q<1e3;q+=i)
                pr[q]=1;
        }
    }
    string s;
    while(cin>>s){
        if(s=="1"){
            puts("1 1");
            continue;
        }
        mx=-1;
        reverse(s.begin(),s.end());
        p.n=s.size();
        p.s=0;
        for(int i=0;i<s.size();i++){
            p.p[i]=s[i]-'0';
            p.s+=p.p[i]*pow(10.0,i);
        }
        qiu();
        p=da;
        for(int i=p.n;i--;)
            cout<<p.p[i];
        cout<<' '<<mx;cout<<endl;
    }
}
