#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
typedef __int64 int64;
const int maxn = 2000005;
const int inf = 0x7fffffff;
const double pi=acos(-1.0);
const double eps = 1e-8;
struct node{
    int pi,di;
}a[ maxn ];
int cmp( node a,node b ){
    if( a.di!=b.di ) return a.di>b.di;
    else return a.pi<b.pi;
}
int main(){
    int n,m;
    while( scanf("%d%d",&n,&m)==2 ){
        int cnt = 0;
        for( int i=0;i<n;i++ ){
            scanf("%d",&a[ i ].di);
            a[ i ].pi = -1;
        }
        cnt = n;
        for( int i=0;i<m;i++ ){
            scanf("%d",&a[ cnt ].di);
            cnt++;
        }
        cnt = n;
        for( int i=0;i<m;i++ ){
            scanf("%d",&a[ cnt ].pi);
            cnt++;
        }
        sort( a,a+cnt,cmp );
        __int64 ans = 0;
        bool flag = true;
        int kill = 0;
        priority_queue< int,vector<int>,greater<int> > q;
        for( int i=0;i<cnt&&kill<n;i++ ){
            if( a[ i ].pi<0 ){
                if( q.empty() ){
                    flag = false;
                    break;
                }
                ans += q.top();
                q.pop();
                kill++;
            }
            else{
                q.push( a[ i ].pi );
            }
        }
        if( flag == false ) printf("No\n");
        else printf("%I64d\n",ans);
    }
    return 0;
}
