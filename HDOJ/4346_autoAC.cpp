#include<cstdio>
#include<cstring>
using namespace std;
#define mod 1000000007
int t;
long long mod_pow(int a,int n,int p)
{
    long long ret=1;
    long long A=a;
    while(n){
        if (n & 1)
            ret=(ret*A)%p;
        A=(A*A)%p;
        n>>=1;
    }
    return ret;
}
int main(){
    scanf("%d",&t);
    while( t -- ){
        char str[808];
        scanf("%s",str);
        int len = strlen(str);
        int unknown = 0, r_num = 0;
        for(int i = 0; i < len; i ++){
            if(str[i] == '?') unknown ++;
            else if(str[i] == 'R') r_num ++;
        }
        long long unbea = (r_num == 0);
        for(int i = 0; i < len; i ++){
            if(str[i] == 'R' || str[i] == '?'){
                int x = (str[i] == 'R');
                unbea = (unbea + (x == r_num) ) % mod;
                for(int dis = 1; dis + i < len; dis += 2){
                    int y = x;
                    for(int sta = i + dis; sta < len; sta += dis){
                        y += (str[sta] == 'R');
                        if(str[sta] == 'G') break;
                        unbea = (unbea + (y == r_num) )% mod;
                    }
                }
            }
        }
        printf("%I64d\n",mod_pow(2,unknown,mod) - unbea);
    }
    return 0;
}
