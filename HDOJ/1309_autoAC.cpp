#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double mon,downpay,loan,dep;
double rate[110];
int main(){
   // freopen("in","r",stdin);
    while(cin >> mon >> downpay>>loan>>dep&&mon>0){
        memset(rate,0.0,sizeof rate);
        while(dep--){
            int s;
            double ra;
            cin >> s >> ra;
            for(int i = s; i <= 100; i++) rate[i] = ra;
        }
        int ans = 0;
        double aver = loan/mon;
        double nowloan = loan;
        double nowsum = (loan+downpay)*(1-rate[0]);
        while(nowsum < nowloan){
            ans++;
            nowloan -= aver;
            nowsum = nowsum*(1-rate[ans]);
        }
        cout<<ans<<" ";
        if(ans != 1) cout<<"months"<<endl;
        else cout<<"month"<<endl;
    }
    return 0;
}
