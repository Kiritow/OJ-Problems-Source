#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i < (n);i++)
#define REPD(i,n) for(int i=(n-1);i >= 0;i--)
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)
int n,m;
int C[2011][2011];
char str[2011][2011];
void fun(){
    C[0][0] = 0;
    FOR(i,1,n){
        C[i][0] = 0;
        FOR(j,1,m){
            C[i][j] = C[i][j-1]+(str[i][j]=='*'?1:0);
        }
    }
    FOR(i,2,n){
        FOR(j,1,m){
            C[i][j] += C[i-1][j];
        }
    }
}
int Area(int x1,int y1,int x2,int y2){
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    return C[x2][y2]-C[x2][y1-1]-C[x1-1][y2]+C[x1-1][y1-1];
}
 int main()
{
     while(~scanf("%d%d",&n,&m),n,m){
        int x,y;
        scanf("%d%d",&x,&y);
        FOR(i,1,n)scanf("%s",str[i]+1);
        fun();
        int ans = 0;
        FOR(i,1,n){
            FOR(j,1,m){
                if(str[i][j] != '*')continue;
                int xx1 = i+x-1;
                int yy1 = j+y-1;
                if(!(xx1<1||yy1<1||xx1>n||yy1>m)){
                    if(Area(i,j,xx1,yy1) == x*y)ans++;
                }
                int xx2 = i+y-1;
                int yy2 = j+x-1;
                if(xx2 == xx1 && yy2==yy1)continue;
                if(xx2<1||yy2<1||xx2>n||yy2>m)continue;
                if(Area(i,j,xx2,yy2) == x*y)ans++;
            }
        }
        printf("%d\n",ans);
     }
     return 0;
 }
