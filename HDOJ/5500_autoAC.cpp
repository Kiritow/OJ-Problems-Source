#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<bitset>
using namespace std;
#define N 300005
#define NMAX 2000000000 
typedef long long ll;
int a[22];
bool cmp(const int& x, const int& y){
    return x>y;
}
int main(){
    int T, n, m;
    while ( scanf("%d", &T) != EOF){
        while ( T > 0 ){
            T--;
            scanf("%d", &n);
            int index = -1;
            for ( int i = 0 ;i < n; i++ ){
                scanf("%d", &a[i]);
            }
            int ans = 0, t = n - 1, cur = n;
            while ( t >= 0 ){
                if ( a[t] == cur ) cur--;
                t--;
            }
            cout << cur << endl;
        }
    } 
    return 0;
}
