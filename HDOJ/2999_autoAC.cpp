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
int n,a[100],m,k,cnt,sg[1005];
int get_sg(int n){
    if(sg[n]!=-1)
        return sg[n];
    int vis[10000];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<cnt&&a[i]<=n;i++){
        for(int j=0;j<=(n-a[i]);j++){
            if(sg[j]==-1)
                sg[j]=get_sg(j);
            if(sg[n-j-a[i]]==-1)
                sg[n-j-a[i]]=get_sg(n-j-a[i]);
            vis[sg[j]^sg[n-j-a[i]]]=1;
        }
    }
    for(int i=0;;i++)
        if(vis[i]==0)
            return i;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        cnt=1;
        for(int i=1;i<n;i++)
            if(a[i]!=a[cnt-1])
                a[cnt++]=a[i];
        int q;
        scanf("%d",&q);
        memset(sg,-1,sizeof(sg));
        while(q--){
            scanf("%d",&k);
            if(sg[k]==-1)
                sg[k]=get_sg(k);
            if(sg[k])
                puts("1");
            else
                puts("2");
        }
    }
    return 0;
}
