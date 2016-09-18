#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
#include<iomanip>
#include<cmath>
#include<bitset>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef long double ld;
#define INF (1ll<<60)-1
#define Max 1e9
using namespace std;
ll a[200100],T;
int n;
queue<int> qu1,qu2;
bool pd(int k){
    while(!qu1.empty()) qu1.pop();
    while(!qu2.empty()) qu2.pop();
    for(int i=1;i<=n;i++) qu1.push(a[i]);
    int num=0;
    ll sum=0,ans=0;
    if((n-1)%(k-1)!=0){
        num=(n-1)%(k-1)+1;
        for(int i=1;i<=num;i++) {
            sum+=qu1.front();
            qu1.pop();
        }
        qu2.push(sum);
        ans+=sum;
    }
    while(!qu1.empty()){
        sum=0;
        for(int i=1;i<=k;i++){
            if(!qu1.empty() && !qu2.empty() ){
                if(qu1.front()<=qu2.front()){
                    sum+=qu1.front();
                    qu1.pop();
                } else {
                    sum+=qu2.front();
                    qu2.pop();
                }
            } else if(qu1.empty()){
                sum+=qu2.front();
                qu2.pop();
            } else if(qu2.empty()){
                sum+=qu1.front();
                qu1.pop();
            }
        }
        ans+=sum;
        qu2.push(sum);
    }
    if(ans>T) return false;
    sum=0;num=0;
    while(!qu2.empty()){
        sum+=qu2.front();
        qu2.pop();
        num++;
        if(num==k){
            qu2.push(sum);
            ans+=sum;
            sum=0;
            num=0;
            if(qu2.size()==1) break;
        }
    }
    if(ans>T) return false;
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%I64d",&n,&T);
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        int l=2,r=n,mid,ans=1;
        while(l<=r){
            mid=(l+r)/2;
            if(pd(mid)) {
                r=mid-1;
                ans=mid;
            } else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
