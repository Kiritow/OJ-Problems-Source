#include<cstdio>
#include<cmath>
using namespace std;
#define N 50005
int f[N], rank[N], n, m;
void init(){
    for(int i=0; i<=n; ++i)
        f[i]=i, rank[i]=0;
}
int find(int x){
    if(x==f[x]) return f[x];
    int t=f[x];
    f[x] = find(f[x]);
    rank[x] += rank[t];
    return f[x];
}
bool Union(int x,int y, int m){
    int a=find(x), b=find(y);
    if(a==b){
        if(rank[x]+m!=rank[y])
            return false;
        return true;
    }
    f[b] = a;
    rank[b] = rank[x]+m-rank[y];
    return true;
}
int main(){
    int a,b,x;
    while(~scanf("%d%d",&n,&m)){
        init();
        int cnt=0;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&a,&b,&x);
            if(!Union(a, b, x)){
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
