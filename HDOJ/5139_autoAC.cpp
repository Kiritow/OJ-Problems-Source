#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=100002;
const int mod=1000000007;
int ans[maxn];
vector<pair<int,int> >vc;
int n;
int cnt=0;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        vc.push_back(make_pair(n,cnt++));
    }
    sort(vc.begin(),vc.end());
    int MAX=vc[cnt-1].first;
    long long tp=1,result=1;
    int t=0;
    for(int i=1;i<=MAX;i++)
    {
        tp=tp*i;
        if(tp>=mod)
            tp%=mod;
        result=result*tp;
        if(result>=mod)
            result%=mod;
        while(t<cnt&&vc[t].first==i)
        {
            ans[vc[t].second]=result;
            t++;
        }
    }
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<endl;
    return 0;
}
