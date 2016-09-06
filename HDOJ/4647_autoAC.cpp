#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m;
double a[N];
int cmp(double x,double y){
    return x>y;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        int u,v,w;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            a[u]+=1.0*w/2;
            a[v]+=1.0*w/2;
        }
        double t1=0,t2=0;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
            if(i&1)
                t1+=a[i];
            else
                t2+=a[i];
        printf("%.0lf\n",t1-t2);
    }
    return 0;
}
