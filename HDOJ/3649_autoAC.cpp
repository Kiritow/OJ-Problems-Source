#include <iostream>
#include <cstdio>
using namespace std;
int red[10],black[10],first;
int solve(){
    if(black[1]-red[1]==1) return first;
    if(red[4]-1>10-black[4]) return 0;
    if(red[4]-1<10-black[4]) return 1;
    int sg=0;
    sg^=(black[2]-red[2]-1);
    sg^=(black[3]-red[3]-1);
    sg^=(black[1]-red[1])%2;
    if(sg) return first;
    else return first^1;
}
int main(){
    while(scanf("%d",&first)!=EOF){
        for(int i=1;i<=4;i++) scanf("%d",&red[i]);
        for(int i=1;i<=4;i++) scanf("%d",&black[i]);
        if ( !solve() ) printf("Red\n");
        else printf("Black\n");
    }
    return 0;
}
