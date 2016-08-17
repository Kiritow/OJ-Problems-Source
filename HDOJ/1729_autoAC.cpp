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
int get_sg(int s,int c){
    int q=sqrt((double)s);
    while(q+q*q>=s)
        q--;
    if(c>q) return s-c;
    else return get_sg(q,c);
}
int main(){
    int n,cas=0;
    while(scanf("%d",&n)!=EOF&&n){
        int s,c;
        printf("Case %d:\n",++cas);
        int ans=0;
        while(n--){
            scanf("%d%d",&s,&c);
            ans^=get_sg(s,c);
        }
        if(ans)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
