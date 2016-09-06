#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,num[1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            ans+=1*num[i]*(n-1-num[i]);
        }
        ans/=2;
        printf("%.3f\n",1.0-ans*1.0/((n*(n-1)*(n-2))/6));
    }
    return 0;
}
