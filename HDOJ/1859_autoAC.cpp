#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int a[100],b[100],n;
    while(n--){
        int j=1,i=0;
        while(scanf("%d%d",&a[i],&b[i])!=EOF,a[i]||b[i]){
            i++;
            j=j+1;}
        sort(a,a+j-1);
        sort(b,b+j-1);
        if(j!=1) printf("%d %d %d %d\n",a[0],b[0],a[j-2],b[j-2]);
        else
            break;
    }
    return 0;
}
