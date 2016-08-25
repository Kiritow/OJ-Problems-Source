#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits.h>
#include <time.h>
#include <string.h>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define Max INT_MAX
#define Min INT_MIN
#define eps 1e-8
#define N 1001
priority_queue<int , vector<int> ,greater<int> > p[701];
int s[51];
int n,m;
bool vis[51];
int live,die;
void gao(){
    int i,j,k;
    live=0,die=0;
    int t=1;
    while(live+die<m){
        i=0;
        while(i<n && !p[t].empty()){
            int x=p[t].top();
            p[t].pop();
            if(x>=s[i]){
                die++;
                i++;
            }
            else
            if(x-1>=s[0]){
                x--;
                p[t+1].push(x);
            }
            else
            live++;
        }
        while(!p[t].empty()){
            int x=p[t].top();
            p[t].pop();
            if(x-1>=s[0]){
            x--;
            p[t+1].push(x);
            }
            else
            live++;
        }
        t++;
    }
    printf("%d\n",die);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        int i,j;
        for(i=0;i<n;i++)scanf("%d",&s[i]);
        sort(s,s+n);
        for(i=0;i<=700;i++)
        while(!p[i].empty())
        p[i].pop();
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            p[a].push(b);
        }
        gao();
    }
    return 0;
}
