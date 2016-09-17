#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e6 + 5;

char a[N];
double sum[N];

void yu()
{
    for(int i = 1 ; i < N ; i++){
        sum[i] = sum[i - 1] + (double)1/i/i;
    }
}
int main()
{
    yu();
    while(~scanf("%s",a)){
        int l = strlen(a);
        if(l >= 7) printf("%.5lf\n",sum[1000000]);
        else{
            int n = 0;
            for(int i = 0 ; i < l ; i++){
                n = n * 10 + a[i] - '0';
            }
            printf("%.5lf\n",sum[n]);
        }
    }
    return 0;
}
