#include <stdio.h>
#define G1 100005
int mu[G1];
void getMu(){       
    for(int i=1;i<G1;i++)
        mu[i]=1;
    for(int i=2;i<G1;i++){
        if(mu[i]==0)continue;
        mu[i]=-mu[i];
        for(int j=i*2;j<G1;j+=i)
            mu[j]+=mu[i];
    }
}
int main(){
    getMu();
    int t1,t2,k,kase=1,temp,_;
    long long  ans1,ans2;
    scanf("%d",&_);
    while(_--){
        scanf("%*d%d%*d%d%d",&t1,&t2,&k);
        if(k==0){
            printf("Case %d: 0\n",kase++);
            continue;
        }
        t1=t1/k;
        t2=t2/k;
        if(t1>t2){
            temp=t1;
            t1=t2;
            t2=temp;
        }
        ans1=ans2=0;
        for(int i=1;i<=t1;i++)
            ans1+=(long long)mu[i]*(t1/i)*(t2/i);
        for(int i=1;i<=t1;i++)
            ans2+=(long long)mu[i]*(t1/i)*(t1/i);
        printf("Case %d: %I64d\n",kase++,ans1-ans2/2);
    }
    return 0;
}
