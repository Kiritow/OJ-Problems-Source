#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
const int N=30000+10;
typedef long long LL;
struct Point{
    LL x,y;
    Point (LL a=0,LL b=0):x(a),y(b){}
    Point operator - (const Point &p)const{
        return Point(x - p.x, y - p.y);
    }
};
LL sum[N],Ti[N],ti;
int n,M,r,anger[N];
typedef Point Vector;
LL Cross(const Vector &u,const Vector &v){
    return u.x*v.y - u.y*v.x;
}
struct dequeue{
    Point q[N];
    int head,tail;
    void init(){
        head = 1; tail = 0;
    }
    void push(const Point &u){
        while (head < tail && Cross(q[tail] - q[tail-1],u - q[tail-1]) <= 0) 
            tail--;
        q[++tail] = u;
    }
    void pop(int k,int i,int w){
        while (head <= tail && anger[i] - anger[q[head].x] > w) head++;
        while (head < tail && -k*q[head].x + q[head].y >= -k*q[head+1].x + q[head+1].y) head++;
    }
}H;
struct vegetable{
    int vi,ai;
    LL di;
    vegetable(int v=0,int a=0,LL d=0):vi(v),ai(a),di(d){}
    bool operator < (const vegetable &p)const{
        return vi>p.vi;
    }
    void input(){
        scanf("%d%d%I64d",&vi,&ai,&di);
    }
    void output(){
        cout<< vi <<" "<< ai <<" "<< di << endl;
    }
}vg[N];
void init(){
    sort(vg+1,vg+n+1);
    anger[0] = sum[0] = Ti[0] = 0;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+vg[i].di;
        Ti[i]=Ti[i-1]+i*vg[i].di;
        anger[i] = anger[i-1] + vg[i].ai;
    }
}
LL dp[11][N];
int check(int m){
    for (int i=0;i<=n;i++){
        if (anger[i] <= m) dp[0][i]=Ti[i];
        else dp[0][i] = Ti[i]+ti ;
    }
    for (int j=1;j<=M;j++){
        H.init();
        H.push(Point(0,(j-1)*r));
        for (int i=1;i<=n;i++){
            H.pop(sum[i],i,m);
            if (H.head<=H.tail)
                dp[j][i] = -sum[i]*H.q[H.head].x + H.q[H.head].y + Ti[i] + r;
            else dp[j][i] = ti + 100;    
             if (dp[j-1][i] < ti) H.push(Point(i,sum[i]*i + dp[j-1][i] - Ti[i]));
        }
    }    
    LL ret = dp[0][n];
    for (int i=1; i<=M;i++){
        if(dp[i][n] < ret) ret = dp[i][n];
    }
    if (ret > ti) return 0;
    return 1;
}
void solve(int l,int r){
    init();
    int ret=-1;
    while (r>=l){
        int m=(l+r)>>1;
        if (check(m)){
            ret=m; r=m-1;
        }else l=m+1;
    }
    if (ret == -1) printf("I have no idea\n");
    else printf("%d\n",ret);
}
int main(){
    int T; scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%I64d",&n,&M,&r,&ti);
        int allai = 0;
        for (int i=1;i<=n;i++){
            vg[i].input();
            allai += vg[i].ai;
        }
        solve(1,allai);
    }
    return 0;
}
