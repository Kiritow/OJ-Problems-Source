#include <cstdio>
typedef long long llg;
llg a,b,n,m;
void solve(){
    llg ans1(1),ans2(0),t1(a),t2(1);
    llg tmp;
    while(n){
        if(n&1){
            tmp = ans1;
            ans1 = (ans1*t1+ans2*t2*b)%m;
            ans2 = (tmp*t2+ans2*t1)%m;
        }
        tmp = t1;
        t1 = (t1*t1+t2*t2*b)%m;
        t2 = 2*tmp*t2%m;
        n >>= 1;
    }
    printf("%lld\n",ans1*2%m);
}
int main(){
    while(~scanf("%lld%lld%lld%lld",&a,&b,&n,&m))
        solve();
    return 0;
}
