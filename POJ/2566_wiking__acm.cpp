#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 5;
const int INF = 2000000000;
typedef  pair<int, int> P;
typedef long long LL;

P p[maxn];

int Abs(int x){return x<0?-x:x;}
int n;

void query(int tar){
    int s = 0,e = 1,Min = INF;
    int ansl,ansr,ansx;
    while(s <= n && e <= n){
        int tem = p[e].first-p[s].first;
        if(Abs(tem-tar) < Min){
            Min = Abs(tem-tar);
            ansx = tem;
            ansl = p[s].second;
            ansr = p[e].second;
        }
        if(tem > tar) s++;
        else if(tem < tar) e++;
        else break;
        if(s == e) e++;
    }
    if(ansl > ansr) swap(ansl,ansr);
    printf("%d %d %d\n",ansx,ansl+1,ansr);
}

int main(){
    int m;
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0) break;
        p[0] = P(0,0);
        int sum = 0;
        for(int i = 1;i <= n;i++){
            int tem;
            scanf("%d",&tem);
            sum += tem;
            p[i] = P(sum,i);
        }
        sort(p,p+n+1);
        while(m--){
            int x;
            scanf("%d",&x);
            query(x);
        }
    }
    return 0;
}
