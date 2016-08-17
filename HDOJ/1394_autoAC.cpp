#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 5005
#define inf 999999999
int c[N];
int a[N];
int lowbit(int x){
    return x&(-x);
}
void update(int x){
    while(x<N){
        c[x]++;
        x+=lowbit(x);
    }
}
int get_sum(int x){
    int ans=0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
main()
{
    int n, i, j, k;
    while(scanf("%d",&n)==1){
        memset(c,0,sizeof(c));
        int num=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]++;
            num+=get_sum(N-1)-get_sum(a[i]);  
            update(a[i]);               
        }                              
        int minh=inf;
        for(i=1;i<=n;i++)
        {
            num=num-(a[i]-1)+(n-a[i]);       
            minh=min(minh,num);             
        }
        printf("%d\n",minh);
    }
}
