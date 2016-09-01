#include <iostream>
#include <cstdio>
using namespace std;
int zhengc[101],yanchi[101];
int times[101],timee[101];
int ts,te;
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int a,b,c,d,i;
        for(i=1;i<=n;i++){
            scanf("%d%d",&zhengc[i],&yanchi[i]);
            yanchi[i]+=zhengc[i];
            scanf("%d:%d %d:%d",&a,&b,&c,&d);
            times[i]=a*60+b;
            timee[i]=c*60+d;
        }
        scanf("%d:%d %d:%d",&a,&b,&c,&d);
        ts=a*60+b;
        te=c*60+d;
        bool mark=true;
        int tt;
        for(i=1;i<=n;i++){
            tt=ts+zhengc[i];
            if(tt>=1440){
                mark=false;
                break;
            }
            if(tt<=times[i] || ts>=timee[i]){
                ts+=zhengc[i];
                if(ts>=te || ts>=1440){
                    mark=false;
                    break;
                }
            }else{
                ts+=yanchi[i];
                if(ts>=te || ts>=1440){
                    mark=false;
                    break;
                }
            }
        }
        if(mark){
            if(ts<te){
                printf("Lucky YY!\n");
            }else{
                printf("Poor YY!\n");
            }
        }else{
            printf("Poor YY!\n");
        }
    }
    return 0;
}
