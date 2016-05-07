#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
    int N;
    while(cin>>N){
        vector <int> arr[201];
        for (int i=1;i<=N;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            arr[a].pb(b);
        }
        int mn=2e9, ans=0;
        for (int i=1;i<=N+N;i++){
            if (mn < i) ans++, mn = 2e9;
            for(int j=0;j<arr[i].size();j++)
            {
                int e=arr[i][j];
                mn=min(mn,e);
            }
        }
        if (mn < 2e9) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
