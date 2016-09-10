#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
const int inf=0xfffffff;
typedef long long ll;
using namespace std;
int main()
{
    int n;
    ll a, s;
    while(~scanf("%d", &n)){
        scanf("%I64d", &s);
        for(int i=1; i<n; i++){
            scanf("%I64d", &a);
            s ^= a;
        }
        if(!s) printf("Lose\n");
        else printf("Win\n");
    }
    return 0;
}
