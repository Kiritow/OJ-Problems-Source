#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Node{
    double t,x,y;
    void input(){
        scanf("%lf%lf%lf",&t,&x,&y);
    }
    double calc(Node b){
        return hypot(x-b.x,y-b.y)/(b.t-t);
    }
}node[1010];
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++)node[i].input();
        double ans = -1.0;
        for(int i = 0;i < n-1;i++)
            ans = max(ans,node[i].calc(node[i+1]));
        printf("%.10lf\n",ans);
    }
    return 0;
}
