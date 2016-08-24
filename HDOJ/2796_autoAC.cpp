#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100],n;
int main(){
while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n+1);
    int k=1;
    int fro=a[1];
    int site=1;
    int left=0;
    for(int i=2;i<=n;i++){
        if(a[i]>fro&&i-site+left>=k+1&&a[i]!=a[i-1]){
            fro=a[i];
            left=i-site-k-1+left;
            site=i;
            k++;
        }else continue;
    }
        printf("%d\n",k);
}
return 0;
}
