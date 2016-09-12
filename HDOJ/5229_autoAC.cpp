#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    for(;a>0&&b>0;a>b?a%=b:b%=a);
    return a+b;
}
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        while(T--){
            int n;
            scanf("%d",&n);
            map<string,int>m;
            ll ji=0,ou=0;
            m.clear();
            int i;
            for(i=1;i<=n;i++){
                string a;
                cin>>a;
                m[a]++;
                if(a.length()%2){
                    ji++;
                }
                else ou++;
            }
            ll cnt=0;
            cnt=ji*ou;
            for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
                if(it->second>1){
                    cnt+=((it->second)*((it->second)-1)/2);
                }
            }
            ll sum=n*(n-1)/2;
            if(cnt==0)printf("0/1\n");
            else{
                ll g=gcd(cnt,sum);
                printf("%lld/%lld\n",cnt/g,sum/g);
            }
        }
    }
    return 0;
}
