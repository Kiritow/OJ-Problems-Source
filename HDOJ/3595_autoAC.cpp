#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        while(n--){
            int p,q,len=2,f[100];
            scanf("%d%d",&p,&q);
            if(p<q) swap(p,q);
            f[1]=p;f[2]=q;
            while(f[len]){
                f[len+1]=f[len-1]%f[len];
                len++;
            }
            int k=len-2,j=-1;
            for(int i=1;i<len-1;i++){
                if(f[i]/f[i+1]>1){
                    if(j>0&&i%2!=j%2)
                        k++;
                    j=i;
                }
            }
            ans=max(ans,k);
        }
        if(ans&1) puts("MM");
        else puts("GG");
    }
    return 0;
}
