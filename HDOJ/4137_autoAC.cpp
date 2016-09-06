#include<stdio.h> 
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
    int id;
    int v;
}p[33];
bool cmp(node a,node b){
    return a.v<b.v;
}
int main(){
    int t;
    scanf("%d",&t);
    int ca=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int i;
        int ans = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&p[i].v);
            p[i].id = i;
        }
        sort(p+1,p+1+n,cmp);
        for(i=1;i<=n;i++){
            ans += abs(p[i].id-i);
        }
        printf("Case #%d: %d\n",ca++,ans/2);
    }
    return 0;
}
