#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll pow(ll a,ll b,ll mod){
    ll as=1;
    while(b){
        if(b&1)as=as*a%mod;
        b>>=1; a=a*a%mod;
    }
    return as;
}
vector<ll>as,f;
ll gcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    else{
        ll r=gcd(b,a%b,y,x);
        y-=a/b*x;
        return r;
    }
}
void moxianxing(ll a,ll b,ll n){
    ll x,y;
    ll d=gcd(a,n,x,y);
    as.clear();
    if(b%d==0){
        x%=n;x+=n;x%=n;
        as.push_back(x*(b/d)%(n/d));
        for(ll i=1;i<d;i++)
            as.push_back((as[0]+i*n/d)%n);
    }
}
bool gtest(ll g,ll p){
    for(int i=0;i<f.size();i++)
        if(pow(g,(p-1)/f[i],p)==1)
            return 0;
     return 1;
}
ll gen(ll p){
    ll tmp=p-1;
    f.clear();
    for(ll i=2;i<=tmp/i;i++)
        if(tmp%i==0){
            f.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp!=1)f.push_back(tmp);
    ll g=0;
    while(++g)if(gtest(g,p))return g;
}
map<ll,int>rec;
ll lisanshu(ll x,ll n,ll m){
    ll s=(ll)(sqrt((double)m)+0.5);
    ll cur=1;rec.clear();
    for(int i=0;i<s;i++){
        rec[cur]=i;
        cur=cur*x%m;
    }
    ll mul=cur;cur=1;
    for(int i=0;i<s;i++){
        ll more=n*pow(cur,m-2,m)%m;
        if(rec.count(more))return i*s+rec[more];
        cur=cur*mul%m;
    }
    return -1;
}
int dd[33],hh[30],mi[80];
int mm[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve(ll x){
    int y,mo,d,h,min,s,i;
    for(y=2000;1;y++){
        s=365*24*60*60;
        if(y%4==0&&y%100||y%400==0)s+=24*60*60;
        if(y%10==5||y%10==8)s++;
        if(x-s<0)break;
        x-=s;
    }
    if(y%4==0&&y%100||y%400==0)
        for(i=2;i<13;i++)
            mm[i]+=24*60*60;
    if(y%10==5||y%10==8){
        mm[12]++;dd[31]++;hh[24]++;mi[60]++;
    }
    for(i=1;i<13;i++)if(x-mm[i]<0)break;x-=mm[i-1];mo=i;
    for(i=1;i<33;i++)if(x-dd[i]<0)break;x-=dd[i-1];d=i;
    for(i=1;i<25;i++)if(x-hh[i]<0)break;x-=hh[i-1];h=i-1;
    for(i=1;i<61;i++)if(x-mi[i]<0)break;x-=mi[i-1];min=i-1;
    if(y%4==0&&y%100||y%400==0)
        for(i=2;i<13;i++)
            mm[i]-=24*60*60;
    if(y%10==5||y%10==8){
        mm[12]--;dd[31]--;hh[24]--;mi[60]--;
    }
    printf("%d.%02d.%02d %02d:%02d:%02lld\n",y,mo,d,h,min,x);
}
int main(){
    ll a,p,q,g,u,v;
    int cs,csi;
    for(int i=1;i<15;i++)mm[i]=mm[i]*24*60*60+mm[i-1];
    for(int i=1;i<33;i++)dd[i]=i*24*60*60;
    for(int i=1;i<30;i++)hh[i]=i*60*60;
    for(int i=1;i<80;i++)mi[i]=i*60;
    scanf("%d",&cs);
    for(csi=1;csi<=cs;csi++){
        scanf("%lld%lld%lld",&p,&q,&a);
        printf("Case #%d:\n",csi);
        if(a==0){puts("2000.01.01 00:00:00");continue;}
        as.clear();
        g=gen(p);
        v=lisanshu(g,a,p);
        if(v==-1){puts("Transmission error");continue;}
        moxianxing(q,v,p-1);
        if((int)as.size()==0){puts("Transmission error");continue;}
        for(int i=0;i<as.size();i++)as[i]=pow(g,as[i],p);
        sort(as.begin(),as.end());
        for(int i=0;i<as.size();i++)
            solve(as[i]);
    }
    return 0;
}
