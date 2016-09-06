#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
const int maxn = 200 +5;
pair<double,double>con[maxn];
int main(){
    int n;
    while(cin >> n){
        for(int i = 1 ; i <= n ; i++) scanf("%lf%lf",&con[i].first,&con[i].second);
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                pair<double,double> t;
                t.first = (con[i].first + con[j].first) / 2.0;
                t.second = (con[i].second + con[j].second) / 2.0;
                int cnt = 0;
                for(int k = 1 ; k <= n ; k++){
                    double dis = pow(t.first - con[k].first,2) + pow(t.second - con[k].second,2);
                    if(dis <= 6.25 + eps) cnt++;
                }
                ans = max(ans , cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
