#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef double typev;
const double eps = 1e-8;
const int N = 50005;
int sign(double d){
    return d < -eps ? -1 : (d > eps);
}
struct point{
    typev x, y;
    point operator-(point d){
        point dd;
        dd.x = this->x - d.x;
        dd.y = this->y - d.y;
        return dd;
    }
    point operator+(point d){
        point dd;
        dd.x = this->x + d.x;
        dd.y = this->y + d.y;
        return dd;
    }
}ps[N];
//int n, cn;
double dist(point d1, point d2){
    return sqrt(pow(d1.x - d2.x, 2.0) + pow(d1.y - d2.y, 2.0));
}
double dist2(point d1, point d2){
    return pow(d1.x - d2.x, 2.0) + pow(d1.y - d2.y, 2.0);
}
bool cmp(point d1, point d2){
    return d1.y < d2.y || (d1.y == d2.y && d1.x < d2.x);
}
typev xmul(point st1, point ed1, point st2, point ed2){
    return (ed1.x - st1.x) * (ed2.y - st2.y) - (ed1.y - st1.y) * (ed2.x - st2.x);
}
typev dmul(point st1, point ed1, point st2, point ed2){
    return (ed1.x - st1.x) * (ed2.x - st2.x) + (ed1.y - st1.y) * (ed2.y - st2.y);
}
struct poly{
    static const int N = 50005; 
    point ps[N+5]; 
    int pn;  
    poly() { pn = 0; }
    void push(point tp){
        ps[pn++] = tp;
    }
    int trim(int k){
        return (k+pn)%pn;
    }
    void clear(){ pn = 0; }
};
poly graham(point* ps, int n){
    sort(ps, ps + n, cmp);
    poly ans;
    if(n <= 2){
        for(int i = 0; i < n; i++){
            ans.push(ps[i]);
        }
        return ans;
    }
    ans.push(ps[0]);
    ans.push(ps[1]);
    point* tps = ans.ps;
    int top = -1;
    tps[++top] = ps[0];
    tps[++top] = ps[1];
    for(int i = 2; i < n; i++){
        while(top > 0 && xmul(tps[top - 1], tps[top], tps[top - 1], ps[i]) <= 0) top--;
        tps[++top] = ps[i];
    }
    int tmp = top;  
    for(int i = n - 2; i >= 0; i--){
        while(top > tmp && xmul(tps[top - 1], tps[top], tps[top - 1], ps[i]) <= 0) top--;
        tps[++top] = ps[i];
    }
    ans.pn = top;
    return ans;
}
point getRoot(point p, point st, point ed){
    point ans;
    double u=((ed.x-st.x)*(ed.x-st.x)+(ed.y-st.y)*(ed.y-st.y));
    u = ((ed.x-st.x)*(ed.x-p.x)+(ed.y-st.y)*(ed.y-p.y))/u;
    ans.x = u*st.x+(1-u)*ed.x;
    ans.y = u*st.y+(1-u)*ed.y;
    return ans;
}
point change(point st, point ed, point next, double l){
    point dd;
    dd.x = -(ed - st).y;
    dd.y = (ed - st).x;
    double len = sqrt(dd.x * dd.x + dd.y * dd.y);
    dd.x /= len, dd.y /= len;
    dd.x *= l, dd.y *= l;
    dd = dd + next;
    return dd;
}
double getMinAreaRect(point* ps, int n, point* ds){
    int cn, i;
    double ans;
    point* con;
    poly tpoly = graham(ps, n);
    con = tpoly.ps;
    cn = tpoly.pn;
    if(cn <= 2){
        ds[0] = con[0]; ds[1] = con[1];
        ds[2] = con[1]; ds[3] = con[0];
        ans=0;
    }else{
        int  l, r, u;
        double tmp, len;
        con[cn] = con[0];
        ans = 1e40;
        l = i = 0;
        while(dmul(con[i], con[i+1], con[i], con[l])
            >= dmul(con[i], con[i+1], con[i], con[(l-1+cn)%cn])){
                l = (l-1+cn)%cn;
        }
        for(r=u=i = 0; i < cn; i++){
            while(xmul(con[i], con[i+1], con[i], con[u])
                <= xmul(con[i], con[i+1], con[i], con[(u+1)%cn])){
                    u = (u+1)%cn;
            }
            while(dmul(con[i], con[i+1], con[i], con[r])
                <= dmul(con[i], con[i+1], con[i], con[(r+1)%cn])){
                    r = (r+1)%cn;
            }
            while(dmul(con[i], con[i+1], con[i], con[l])
                >= dmul(con[i], con[i+1], con[i], con[(l+1)%cn])){
                    l = (l+1)%cn;
            }
            tmp = dmul(con[i], con[i+1], con[i], con[r]) - dmul(con[i], con[i+1], con[i], con[l]);
            tmp *= xmul(con[i], con[i+1], con[i], con[u]);
            tmp /= dist2(con[i], con[i+1]);
            len = xmul(con[i], con[i+1], con[i], con[u])/dist(con[i], con[i+1]);
            if(sign(tmp - ans) < 0){
                ans = tmp;
                ds[0] = getRoot(con[l], con[i], con[i+1]);
                ds[1] = getRoot(con[r], con[i+1], con[i]);
                ds[2] = change(con[i], con[i+1], ds[1], len);
                ds[3] = change(con[i], con[i+1], ds[0], len);
            }
        }
    }
    return ans+eps;
}
int main ()
{
   int t ,n ,i ,NN ,cas = 1;
   point ds[10];
   scanf("%d" ,&t);
   while(t--)
   {
      scanf("%d" ,&NN);
      int n = 0;
      for(i = 1 ;i <= NN ;i ++)
      {
          for(int j = 1 ;j <= 4 ;j ++)
          {
              scanf("%lf %lf" ,&ps[n].x ,&ps[n].y);
              n++;
          }
      }
      double ans = getMinAreaRect(ps ,n ,ds);
      printf("Case #%d:\n" ,cas ++);
      printf("%.0lf\n" ,ans);
   }
   return 0;
}
