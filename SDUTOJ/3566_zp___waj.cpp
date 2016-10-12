#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int n,loop,cnt=1;
    scanf("%d",&loop);
    while(loop--){
        scanf("%d",&n);
        if(n<6||n&1)puts("0");
        else {
            int ans=__builtin_popcount(n);
            printf("%lld\n",((ll)pow(3.0,ans)-3)/6);
        }
    }
    return 0;
}
