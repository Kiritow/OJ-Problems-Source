#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int maxn = 1003;
struct Point
{
    int x,y;
    double rad;
    bool operator<(const Point &rhs) const {
        return rad < rhs.rad;
    }
}P[maxn];
int col[maxn];
Point tmp[maxn];
bool cmp(const Point& a,const Point& b) //anticlockwise sort
{
    return a.x*b.y >= b.x*a.y;
}
int solve(int n)
{
    if(n<=3) return n;
    int ans = -1;
    for(int pivot = 0; pivot < n; pivot++){
        int k = 0;
        for(int i = 0; i < n; i++) if(i!=pivot){
            tmp[k].x = P[i].x - P[pivot].x;
            tmp[k].y = P[i].y - P[pivot].y;
            if(col[i]) { tmp[k].x = - tmp[k].x; tmp[k].y = -tmp[k].y; }
            tmp[k].rad = atan2(tmp[k].y, tmp[k].x);
            k++;
        }
        sort(tmp,tmp+k);
        int L = 0, R = 0, sum = 1;
        while(L<k){
            if(L == R) { R = (R+1)%k; sum++; }
            while(R != L && cmp(tmp[L],tmp[R])) {
                R = (R+1)%k; sum++;
            }
            ans = max(ans,sum);
            sum--;  L++;
        }
    }
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i = 0; i < n; i++)
            scanf("%d%d%d",&P[i].x,&P[i].y,col+i);
            printf("%d\n",solve(n));
    }
    return 0;
}
