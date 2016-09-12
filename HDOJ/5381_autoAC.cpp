#include <stdio.h>
#include <algorithm>
#include <math.h>
const int N = (int)(1e4)+5;
int t,n,m,a[N],ppos[N];
long long ans[N];
int v1[N][35], v2[N][35], v3[N][35], v4[N][35];
int size1[N], size2[N];
struct Q{
    int l,r,id;
    bool operator < (const Q &a ) const{
        if(ppos[l] == ppos[a.l]) return r<a.r;
        return ppos[l] < ppos[a.l];
    }
}q[N];
int gcd(int a, int b){
    return !b?a:gcd(b, a%b);
}
int pool[50], pos[50], cnt;
void unique(int &cnt){
    int id = 0, p = pos[0];
    for(int i=0; i<cnt; i++){
        if(pool[i] != pool[id]){
            pos[id] = p; id++;
            p = pos[i]; pool[id] = pool[i];
        }
    }
    pos[id] = p;
    cnt = id+1;
}
void init(){
    cnt = 0;
    for(int i=n; i>=1; i--){
        for(int j=0; j<cnt; j++) pool[j] = gcd(pool[j], a[i]);
        pool[cnt] = a[i]; pos[cnt++]=i;
        unique(cnt);
        for(int j=cnt-1; j>=0; j--){
            v1[i][cnt-1-j] = pool[j];
            v2[i][cnt-1-j] = pos[j];
        }
        size1[i] = cnt;
    }
    cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<cnt; j++) pool[j] = gcd(pool[j], a[i]);
        pool[cnt] = a[i]; pos[cnt++] = i;
        unique(cnt);
        for(int j=cnt-1; j>=0; j--){
            v3[i][cnt-1-j] = pool[j];
            v4[i][cnt-1-j] = pos[j];
        }
        size2[i] = cnt;
    }
}
int l,r;
long long sum;
void add_l(int v){
    int s = l, t = r;
    long long tmp = 0;
    int last = s;
    for(int i=0; i<size1[l]; i++){
        if(v2[l][i] < s) continue;
        else if(v2[l][i] > t){
            tmp += (t - last + 1) *1LL *v1[l][i];
        }
        else{
            tmp +=  (v2[l][i] - last + 1) *1LL* v1[l][i];
            last = v2[l][i] + 1;
        }
        if(v2[l][i] >= t) break;
    }
    sum += v*tmp;
}
void add_r(int v){
    int s = l, t = r;
    long long tmp = 0;
    int last = t;
    for(int i=0; i<size2[r]; i++){
        if(v4[r][i] > t) continue;
        else if(v4[r][i] < s){
            tmp += (last - s + 1) * 1LL * v3[r][i];
        }else{
            tmp += (last - v4[r][i] + 1) *1LL * v3[r][i];
            last = v4[r][i]-1;
        }
        if(v4[t][i] <= s) break;
    }
    sum += v*tmp;
}
int main(){
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++){
        scanf("%d", &n);
        int S = (int)(sqrt(n*1.0) + 0,5);
        for(int i=1; i<=n; i++){
            ppos[i] = (i-1)/100;
        }
        for(int i=1; i<=n; i++) scanf("%d", &a[i]);;
        init(); scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }
        std::sort(q, q+m);
        sum = 0, l = 1, r = 0;
        for(int i=0; i<m; i++){
            if(r<q[i].r){
                for(r=r+1; r<=q[i].r; r++){
                    add_r(1);
                }
                r--;
            }
            if(r>q[i].r){
                for(;r>q[i].r; r--){
                    add_r(-1);
                }
            }
            if(l>q[i].l){
                for(l=l-1; l>=q[i].l; l--){
                    add_l(1);
                }
                l++;
            }
            if(l<q[i].l){
                for(; l<q[i].l; l++){
                    add_l(-1);
                }
            }
            ans[q[i].id] = sum;
        }
        for(int i=0; i<m; i++){
            printf("%I64d\n", ans[i]);
        }
    }
    return 0;
}
