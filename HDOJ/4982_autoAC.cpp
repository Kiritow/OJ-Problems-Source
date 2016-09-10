#include <iostream>
#include <cstring>
#include <cstdlib>
#include<cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 2000000000
using namespace std;
typedef long long ll;
const int MAX_E=10000;
const int MAX_N=1005;
const int MAX_K=3000;
const int MAXN=10010;
bool judge(int sum,int y,int k)
{
    int mid1=(k-1)*k/2;
    int mid2=sum-mid1;
    if(mid2<=k-1) return false;
    if(y>k-1&&y!=mid2) return true;
    if(y<=k-1){
        if(k-y<=mid2-(k+1)) return true;
        else return  false;
    }
    if(y==mid2){
        if(mid2-(k-1)>=3) return true;
        else return false;
    }
}
int main()
{
    int n,k,T,mm;
    bool flag;
    while(scanf("%d%d",&n,&k)!=EOF){
        int c1=(int)sqrt((double)k*(k-1)/2);
        int c2=(int)sqrt((double)n);
        flag=0;
        for(int i=c1;i<=c2;i++){
            if((k*(k-1)/2<=i*i)&&(i*i<=n-1)&&judge(i*i,n-i*i,k-1)){
                flag=1;
                break;
            }
        }
        if(flag==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
