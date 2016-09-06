#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double typev;
typedef pair<int, int> pii;
const int N = 100005;
const double eps = 1e-8;
const double DINF = 1e40;
const double pi = acos(-1.0);
template<typename T>
void getSNum(T& ans){
    char ch;
    int s;
    while(true){
        ch = getchar();
        if((ch >= '0' && ch <= '9') || ch == '-') break;
    }
    if(ch == '-'){
        s = -1;
        ans = 0;
    }else{
        s = 1;
        ans = ch -'0';
    }
    while(true){
        ch = getchar();
        if(!(ch >= '0' && ch <= '9')) break;
        ans = ans*10+ch-'0';
    }
    ans *= s;
}
int sign(double a){
    return a < -eps ? -1 : (a > eps);
}
struct point{
    typev x, y;
    int id;
    void read(){
        scanf("%lf%lf", &x, &y);
    }
    void print(){
        printf("(%lf, %lf)\n", x, y);
    }
    point(typev _x=0, typev _y=0):x(_x), y(_y) {}
}ps[N], que[N];
int n;
point k;
typev xmul(point st, point ed1, point ed2){
    return (ed1.x-st.x)*(ed2.y-st.y) - (ed1.y-st.y)*(ed2.x-st.x) ;
}
bool isLess(pii a, pii b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
double maxSlope(point *ps, int n, pii& ans){
    int l, r, i, k;
    double s, tmp;
    pii ti;
    l = r = 0;
    que[r++] = ps[0];
    s = -DINF;
    for(i = 1; i < n; i++){
        while(r-l >= 2){
            k = sign(xmul(que[l], que[l+1], ps[i]));
            if(k < 0 || (k == 0 && que[l].id < que[l+1].id)) break;
            l++;
        }
        tmp = (ps[i].y-que[l].y)/(ps[i].x-que[l].x);
        ti.first = que[l].id; ti.second = ps[i].id;
        if(sign(s-tmp) < 0 || (sign(s-tmp) == 0 && isLess(ti, ans))){
            s = tmp;
            ans = ti;
        }
        while(r-l >= 2){
            k = sign(xmul(que[r-2], que[r-1], ps[i]));
            if(k > 0 || (k == 0 && que[r-1].id < ps[i].id)) break;
            r--;
        }
        que[r++] = ps[i];
    }
    return s;
}
bool cmpp(point a, point b){
    return (a.x < b.x) || (sign(a.x-b.x) == 0 && a.y < b.y);
}
double maxSlopeAbs(point* ps, int n, pii& ans){
    //棣ゆ圭x肩哥
    sort(ps, ps+n, cmpp);
    double s = -DINF;
    int i, j, mi;
    pii ti;
    for(i = 0; i < n; i++){
        for(j = i; j < n && sign(ps[j].x-ps[i].x) == 0; j++) ;
        if(j-i > 1){
            for(mi=ps[i].id, i++; i < j; i++){
                ti.first = mi;
                ti.second = ps[i].id;
                if(s < 0 || (s > 0 && isLess(ti, ans))){
                    s = DINF;
                    ans = ti;
                }
                if(mi > ps[i].id){
                    mi = ps[i].id;
                }
            }
        }
        i = j-1;
    }
    if(s > 0){
        return s;
    }
    s = maxSlope(ps, n, ans);
    double tmp;
    int l, r;
    for(i = 0; i < n; i++){
        ps[i].x = 0 - ps[i].x;
    }
    l = 0; r = n-1;
    while(l < r){
        swap(ps[l++], ps[r--]);
    }
    tmp = maxSlope(ps, n, ti);
    if(sign(tmp-s) > 0 || (sign(tmp-s) == 0 && isLess(ti, ans))){
        s = tmp;
        ans = ti;
    }
    return s;
}
point rotate(point st, double Cos, double Sin){
    return point(st.x*Sin- st.y*Cos, st.x*Cos+st.y*Sin);
}
bool input(){
    if(scanf("%d", &n) == EOF) return false;
    k.read();
    int i, g;
    double Cos, Sin, len;
    len = sqrt(k.x*k.x+k.y*k.y);
    Cos = k.x / len;
    Sin = k.y / len;
    for(i = 0; i < n; i++){
        getSNum(g);
        ps[i].x = g;
        getSNum(g);
        ps[i].y = g;
        ps[i] = rotate(ps[i], Cos, Sin);
        ps[i].id = i+1;
    }
    return true;
}
void solve(){
    pii ans;
    if(k.x == 0 && k.y == 0){
        ans.first = 1;
        ans.second = 2;
    }else{
        maxSlopeAbs(ps, n, ans);
    }
    printf("%d %d\n", ans.first, ans.second);
}
int main(){
    while(input()) solve();
    return 0;
}
