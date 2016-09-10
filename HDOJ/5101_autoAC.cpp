#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, k, v[1010][110], m[1100], arr[1010*110];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int cnt=0;
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &m[i]);
            for(int j=0; j<m[i]; j++)
            {
                scanf("%d", &v[i][j]);
                arr[cnt++]=v[i][j];
            }
            sort(v[i], v[i]+m[i]);
        }
        sort(arr, arr+cnt);
        LL ans=0;
        for(int i=0; i<cnt; i++)
            ans+=arr+cnt-upper_bound(arr+i+1, arr+cnt, k-arr[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m[i]; j++)
                ans-=v[i]+m[i]-upper_bound(v[i]+j+1, v[i]+m[i], k-v[i][j]);
        printf("%I64d\n", ans);
    }
    return 0;
}
