#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
using namespace std;
int t,n,a[100010],odd_num,m,indx,Minpos,Min;
__int64 ans;
void init(){
    odd_num = 0;    ans = 1;
    Min = mod;  indx = 1;
}
long long pow_mod(int a,int n,int p)
{
    long long ret=1;
    long long A=a;
    while(n)
    {
        if (n & 1)
            ret=(ret*A)%p;
        A=(A*A)%p;
        n>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca ++){
        scanf("%d%d",&n,&m); init();
        for(int i = 1; i <= n;i ++){
            scanf("%d",a + i);
            if(a[i] < 0) odd_num++;
        }
        sort(a + 1, a + 1 + n);
        if(odd_num & 1){
            int j = 1;
            while(a[j] < 0) j ++;   indx = -- j;
            if(a[j] + m > 0) m += a[j], a[j] = 0;
            else a[j] += m,m = 0;
        }
        if(m > 0){
            for(int j = indx; j <= n && m > 0; j ++)
                if(a[j] == 0) a[j] ++, m --;
            for(int j = indx; j <= n && m > 0; j ++)
                if(a[j] == 1) a[j] ++, m --;
            for(int j = indx; j <= n && m > 0; j ++)
                if(a[j] == 2) a[j] ++, m --;
            for(int j = 1; j <= n; j ++)
                ans = (ans * a[j]) % mod;
            if(m <= 0){
                printf("Case %d: %I64d\n",ca,ans);
            }else{
                if(m == 1){
                    for(int j = 1; j <= n; j ++)
                        if(Min > a[j]) Min = a[j], Minpos = j;
                    ans /= a[Minpos];
                    ans = (ans * (a[Minpos] + 1)) % mod;
                    printf("Case %d: %I64d\n",ca,ans);
                }else if(m % 3 == 0){
                    ans = (ans * pow_mod(3,m/3,mod)) % mod;
                    printf("Case %d: %I64d\n",ca,ans);
                }else if((m - 1) % 3 == 0){
                    ans = (ans * pow_mod(3,(m - 1)/3 - 1,mod)) % mod;
                    ans = (ans * 4) % mod;
                    printf("Case %d: %I64d\n",ca,ans);
                }else if((m - 2) % 3 == 0){
                    ans = (ans * pow_mod(3,(m - 2)/3,mod)) % mod;
                    ans = (ans * 2) % mod;
                    printf("Case %d: %I64d\n",ca,ans);
                }
            }
        }
        else{
            for(int j = 1; j <= n; j ++)
                ans = (ans * a[j]) % mod;
            printf("Case %d: %I64d\n",ca,ans);
        }
    }
    return 0;
}
