#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson k<<1, L, mid
#define rson k<<1|1, mid+1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
ll a[1000000];
int count1;
int main(){
    mem0(a);
    int m;
    for(int i=1;(ll)3*i*(i-1)+1<=1000010000;i++){
        a[i]=3*i*(i-1)+1;
        m=i;
    }
    int t;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(*lower_bound(a+1,a+m+1,n)==n){
            printf("1\n");
            continue;
        }
        int p=1;
        int flag=0;
        if((n-2)%6==0){                            
            while(2*a[p]<=n){
                if(*lower_bound(a+1,a+m+1,n-a[p])==n-a[p]){
                    printf("2\n");
                    flag=1;
                    break;
                }
                p++;
            }
        }
        if(flag==1)
            continue;
        for(int i=3;;i++){
            if((n-i)%6==0){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
