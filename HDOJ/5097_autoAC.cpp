#include<cstdio>
#include<cstring>
#include<cmath>
const double alpha = 0.85;
const double eps = 1e-10;
const int N = 3010;
int n;
double mat[N][N], q[2][N];
inline double sqr(double x){
    return x*x;
}
bool ok(){
    double s = 0.0;
    for(int i=0; i<n; i++)  s += sqr(q[0][i]-q[1][i]);
    return fabs(s)<eps;
}
char s[N];
int main(){
    while(~scanf("%d", &n)){
        double b = (1.0-alpha)/n;
        for(int i=0; i<n; i++){
            scanf("%s", s);
            int m = 0;
            for(int j=0; j<n; j++)  m += s[j]-'0';
            for(int j=0; j<n; j++){
                mat[j][i] = s[j]=='0'?0.0:(1.0/m);
                mat[j][i] = mat[j][i]*alpha + b;
            }
            q[1][i] = 0.0;
            q[0][i] = 1.0;
        }
        bool f = 0;
        while(!ok()){
            for(int i=0; i<n; i++){
                q[f^1][i] = 0.0;
                for(int j=0; j<n; j++){
                    q[f^1][i] += mat[i][j] * q[f][j];
                }
            }
            f^=1;
        }
        for(int i=0; i<n; i++){
            if(i)   putchar(' ');
            printf("%.2f", q[f][i]);
        }
        puts("");
    }
    return 0;
}
