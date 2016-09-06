#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1510;
double a[maxn], d[maxn];
void getd()
{
    d[1]=0.5;
    for(int i=2; i<maxn; i++)
        d[i]=d[i-1]*(2*i-1)/(2*i);
}
void geta()
{
    a[0]=1.0;
    for(int i=1; i<maxn; i++)
        a[i]=a[i-1]+2*d[i];
}
int main()
{
    getd();
    geta();
    int t, ca=1, n;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%d", &n);
        printf("Case %d: ", ca++);
        if(n&1)
            printf("%.6lf\n", a[n/2]);
        else
            printf("%.6lf\n", (a[(n-1)/2]+a[(n+1)/2])*0.5);
    }
    return 0;
}
