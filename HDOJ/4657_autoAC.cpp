#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cstring>
#include<vector>
#define ll __int64
#define pi acos(-1.0)
#define MAX 100005
#define mod 1000003
using namespace std;
int a[MAX],b[MAX],c[MAX],index[MAX];
int main(){
    int t,n,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        for(i=0;i<n;i++) a[i]=c[i]=index[i]=i;
        for(i=0;i<n;i++){
            int cur=i;
            while((a[cur]+b[cur])%n!=c[cur]){
                int l = index[(c[cur]-b[cur]+n)%n];
                swap(a[l],a[cur]);
                swap(index[a[l]],index[a[cur]]);
                if(l>i) break;
                cur=l;
                swap(c[i+1],c[cur]);
            }
        }
        for(i=0;i<n;i++){
            printf("%d",a[i]);
            if(i!=n-1) printf(" ");
            else printf("\n");
        }
        for(i=0;i<n;i++){
            printf("%d",c[i]);
            if(i!=n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
