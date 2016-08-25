#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 50009;
int a[N];
int main(){
    int n, i, j, k;
    while(~scanf("%d", &n) && n)
    {
        for(i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a+n);
        printf("%d-A", a[0]);
        for(i = n-1; i >= 1; --i){
            if(i&1)
                printf(" %d-B", a[i]);
            else
                printf(" %d-A",a[i]);
        }
        puts("");
    }
    return 0;
}
