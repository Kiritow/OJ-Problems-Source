#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define forn(i,n) for(int i=0; i<(int)(n); i++)
using namespace std;
const int N = 4;
const double eps = 1e-6;
const double pi = acos(-1.0);
struct matrix {
    int n;
    double a[N][N];
    void clear() {forn(i,n)forn(j,n)a[i][j]=0;}
    matrix(){}
    matrix(int z):n(z){clear();}
    matrix operator * (const matrix& u){
        matrix ans(n);
        forn(i,n) forn(k,n) forn(j,n)
            ans.a[i][j] += a[i][k] * u.a[k][j];
        return ans;
    }
    matrix pow(int k){
        matrix r(n), t=*this;
        forn(i,n) r.a[i][i]=1.0;
        while (k){
            if (k&1) r = t*r;
            t = t*t;
            k >>= 1;
        } return r;
    }
};
char op[20];
matrix dfs(int tim){
    matrix res(4);
    forn(i,4)res.a[i][i]=1;
    double r[5];
    while (~scanf("%s", op)){
        if (op[0] == 'e') break;        
        matrix tmp(4);
        forn(i,4)tmp.a[i][i]=1;
        if (op[0] == 't'){                  
            forn(i,3) scanf("%lf", &r[i]);
            forn(i,3) tmp.a[i][3]=r[i];
        }
        else if (op[0] == 's'){              
            forn(i,3) scanf("%lf", &r[i]);
            forn(i,3) tmp.a[i][i]=r[i];
        }
        else if (op[0] == 'r' && op[1] == 'o'){     
            double t=0.0, c, s;
            forn(i,4) scanf("%lf", &r[i]);
            forn(i,3) t += r[i]*r[i];
            t = sqrt(t);
            forn(i,3) r[i] /= t;
            r[3] = r[3]/180*pi;
            c = cos(r[3]), s = sin(r[3]);
            forn(i,3){
                forn(j,3){
                    bool f = (i+1)%3==j;
                    if (i == j) tmp.a[i][j]=(1-c)*r[i]*r[j]+c;
                    else tmp.a[i][j]=(1-c)*r[i]*r[j]+s*(f?-r[3^i^j]:r[3^i^j]);
                }
            }
        }
        else {             
            int tim2;
            scanf("%d", &tim2);
            tmp = dfs(tim2);
        }
        res = tmp*res;
    }
    return res.pow(tim);
}
double p[5], q[5];
int main()
{
    int n;
    while (~scanf("%d", &n) && n){
        matrix tmp(4);
        forn(i,4)tmp.a[i][i]=1;
        tmp = dfs(1)*tmp;
        forn(i,n){
            forn(j,3) scanf("%lf",&p[j]);
            p[3] = 1.0;
            forn(j,3){
                q[j] = 0.0;
                forn(k,4) q[j]+=tmp.a[j][k]*p[k];
            }
            forn(j,3) printf("%.2f%c",q[j]+eps,j==2?'\n':' ');
        }
        puts("");
    }
    return 0;
}
