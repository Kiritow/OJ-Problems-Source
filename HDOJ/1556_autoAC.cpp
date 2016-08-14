#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int inf=10000000;
int f[100005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        memset(f,0,sizeof(f));
        for(int i=0,a,b;i<n;++i){
            scanf("%d%d",&a,&b);
            f[a]++;
            f[b+1]--;
        }
        cout<<f[1];
        for(int i=2;i<=n;++i){
            f[i]+=f[i-1];
            cout<<' '<<f[i];
        }
        cout<<endl;
    }
    return 0;
}
