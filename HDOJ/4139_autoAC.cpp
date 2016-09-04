#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 1000005
#define LL long long
int max(int a,int b){return a>b?a:b;}
LL cnt[N];
void gao(int n,int p){
    int i;
    int a=1;
    for(i=2;i*i<=n;i+=a,a=2){
        if(n%i==0){
            while(n%i==0){
                cnt[i] += p;
                n/=i;
            }
        }
    }
    if(n>1)cnt[n] += p;
}
int main(){
    int t;
    scanf("%d",&t);
    int ca=1;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        int i,j;
        int a,b;
        memset(cnt,0,sizeof(cnt));
        int maxm = 0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            maxm = max(a,maxm);
            gao(a,1);
        }
        for(j=0;j<m;j++){
            scanf("%d",&b);
            maxm = max(b,maxm);
            gao(b,-1);
        }
        int x = 1,y = 1;
        for(i=2;i<=maxm;i++){
            if(cnt[i] > 0){
                while(cnt[i]--){
                    x *= i;
                }
            } else if(cnt[i]<0){
                while(cnt[i]++){
                    y *= i;
                }
            }
        }
        printf("Case #%d: %d / %d\n",ca++,x,y);
    }
    return 0;
}
