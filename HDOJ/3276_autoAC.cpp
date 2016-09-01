#include<iostream>
using namespace std;
#define N 50005
#define esp 1e-5
#define inf -10000000001
double a[N],sum[N];
double L[N],R[N];
int q[N];
int n,x,y;
int head,tail;
bool find(double ave){
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i]-ave;
    head=tail=0;
    L[x-1]=inf;
    for(int i=x;i<=n;i++){
        int p=i-x;
        while(head<tail&&sum[p]<sum[q[tail-1]])
            tail--;
        q[tail++]=p;
        while(head<tail&&i-y>q[head])
            head++;
        L[i]=max(L[i-1],sum[i]-sum[q[head]]);
    }
    sum[n+1]=0;
    for(int i=n;i>0;i--)
        sum[i]=sum[i+1]+a[i]-ave;
    head=tail=0;
    R[n-x+2]=inf;
    for(int i=n-x+1;i>0;i--){
        int p=i+x;
        while(head<tail&&sum[p]<sum[q[tail-1]])
            tail--;
        q[tail++]=p;
        while(head<tail&&i+y<q[head])
            head++;
        R[i]=max(R[i+1],sum[i]-sum[q[head]]);
    }
    for(int i=x+1;i<=n-x;i++)   
        if(L[i-1]+R[i+1]>=0)
            return true;
    return false;
}
int main(){
    int k=1;
    while(~scanf("%d%d%d",&n,&x,&y)){
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        double f=1.0,l=200000.0,ret;
        while(l-f>=esp){
            double mid=(f+l)/2;
            if(find(mid)){
                f=mid;
                ret=mid;
            }
            else
                l=mid;
        }
        printf("Case %d: %.3lf\n",k++,ret);
    }
}
