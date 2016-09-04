#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t,r;
    long long n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld%lld",&r,&k,&m);    
        printf("%d %lld\n",r,1+(k-m)*m);
    }
    return 0;
}
