#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<list>
#include<deque>
#include<map>
#include <stdio.h>
#include <queue>
#include <stack>
#define maxn 10000+5
#define ull unsigned long long
#define ll long long
#define reP(i,n) for(i=1;i<=n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define cle(a) memset(a,0,sizeof(a))
#define mod 90001
#define PI 3.141592657
#define INF 1<<30
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
bool cmp(int a,int b){
    return a>b;
};
int a[1004];
int b[2];
int main()
{
    int t,n,mark;
    cin>>t;
    while(t--)
    {
        mark=0;
        cle(a);
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        cle(b);
        int j=0;
        for(int i=n-1;i>=1;i--)
        {
                if(a[i+1]-a[i]==3)
                {
                    mark=1;cout<<a[i]+1<<" "<<a[i]+2<<endl;break;
                }
                if(a[i+1]-a[i]==2)
                {
                    b[j++]=a[i]+1;
                }
                if(a[i+1]-a[i]==1)continue;
        }
        if(j==2)
        {
            cout<<b[1]<<" "<<b[0]<<endl;
        }
        else if(j==0&&!mark)
        {
            if(a[1]>2)cout<<a[1]-2<<" "<<a[1]-1<<endl;
            else cout<<a[n]+1<<" "<<a[n]+2<<endl;
        }
        else if(j==1)
        {
            if(a[1]>1)cout<<a[1]-1<<" "<<b[0]<<endl;
            else cout<<b[0]<<" "<<a[n]+1<<endl;
        }
    }
    return 0;
}
