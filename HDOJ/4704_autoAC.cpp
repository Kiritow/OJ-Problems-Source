#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<math.h>
using namespace std;
typedef long long int64;
typedef pair<int64,int64> PII;
#define MP(a,b) make_pair((a),(b)) 
const int maxn = 100015;
const int inf = 0x7fffffff;
const double pi=acos(-1.0);
const double eps = 1e-8;
const int64 mod = 1000000000+7;
int64 Fast_Pow( int64 a,int64 n,int64 mod ){
    int64 res = 1;
    while( n>=1 ){
        if( n&1 ){
            res = res*a%mod;
        }
        a = a*a%mod;
        n >>= 1;
    }
    return res%mod;
}
int64 GetNum( char str[],int64 mod ){
    int64 res = 0;
    int len = strlen( str );
    for( int i=0;i<len;i++ ){
        res = (res*10+str[i]-'0')%mod;
    }
    return res;
}
int main(){
    char str[ maxn ];
    while( scanf("%s",str)!=EOF ){
        int64 n = GetNum( str,mod-1 );
        printf("%I64d\n",Fast_Pow( 2,(n-1+mod)%mod,mod ));
    }
    return 0;
}
