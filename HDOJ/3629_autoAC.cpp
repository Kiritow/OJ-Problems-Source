#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
const int N=1000;
struct Point{double x, y;}p[N];
double ans[2*N];
long long C(int a,int b){
    long long ans=1;
    for(int i=0;i<b;i++) ans*=(a-i);
    for(int i=2;i<=b;i++) ans/=i;
    return ans;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                double tmp=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
                if(tmp<=-eps) tmp+=2*pi;
                j<i?ans[j]=tmp:ans[j-1]=tmp;
            }
            sort(ans,ans+n-1);
            int k=1;
            long long re2=0;
            for(int j=0;j<n-1;j++)
                ans[j+n-1]=ans[j]+2*pi;
            for(int j=0;j<n-1;j++){
                while(fabs(ans[k]-ans[j])-pi<0) k++;
                if(k-j-1>=2) re2+=C(k-j-1,2);
            }
            res+=C(n-1,3)-re2;
        }
        printf("%I64d\n",C(n,4)-res);
    }
    return 0;
}
