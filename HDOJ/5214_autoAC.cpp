#include<iostream>  
#include<cstdio>  
#include<cstring> 
#include <cmath> 
#include<stack>
#include<vector>
#include<map> 
#include<set>
#include<queue> 
#include<algorithm>  
using namespace std;
typedef long long LL;
const int INF = (1<<30)-1;
const int mod=4294967296;
const int maxn=10000005;
unsigned int  l[maxn],r[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        unsigned int n,a,b,c,d;
        cin>>n>>l[1]>>r[1]>>a>>b>>c>>d;
        for(int i=2;i<=n;i++) l[i]=l[i-1]*a+b;
        for(int i=2;i<=n;i++) r[i]=r[i-1]*c+d;
        for(int i=1;i<=n;i++)
        if(l[i]>r[i]) swap(l[i],r[i]);
        int minn=r[1],maxx=l[1];
        for(int i=1;i<=n;i++){
            if(l[i]>maxx) maxx=l[i];
            if(r[i]<minn) minn=r[i];
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(l[i]>minn&&r[i]<maxx){
                flag=1;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");                
    }
    return 0;
}
