#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int N,T;
double sum,k;
int c;
int main(void)
{
    int cas = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        sum = 0.0;
        for(int i = 0; i < N; ++i){
            scanf("%lf",&k);
            sum += k;
        }
        for(int i = 0; i < N; ++i)
            scanf("%d", &c);
        printf("Case #%d: %.6f\n",cas++,(N + 1.0) / sum);
    }
    return 0;
}
