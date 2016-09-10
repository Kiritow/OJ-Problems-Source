#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000005
int is_prime[MAX];
int num[MAX];
int len;
void Init() {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i<sqrt(MAX*1.0); i++) {
        if(is_prime[i]) {
            for(int j=i*i; j<MAX; j+=i) {
                is_prime[j] = 0;
            }
        }
    }
    len = 0;
    for(int i=2; i<MAX; i++) {
        if(is_prime[i])
            num[len++] = i;
    }
}
int main() {
    int t;
    Init();
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d", &n);
        if(!n) puts("2 2");
        else if(n<0) {
            n = -1*n;
            int flag = 0;
            for(int i=0; i<len; i++) {
                if(is_prime[num[i]+n]) {
                    flag = 1;
                    printf("%d %d\n", num[i], num[i]+n);
                    break;
                }
            }
            if(!flag) printf("FAIL\n");
        }
        else {
            int flag = 0;
            for(int i=0; i<len; i++) {
                if(is_prime[num[i]+n]) {
                    flag = 1;
                    printf("%d %d\n", num[i]+n, num[i]);
                    break;
                }
            }
            if(!flag) printf("FAIL\n");
        }
    }
    return 0;
}
