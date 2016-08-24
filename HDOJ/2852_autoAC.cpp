#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
#define Lowbit(x) ((x)&(-x))
int C[N];
bool vis[N];
void add(int x,int num)
{
    while(x < N)
    {
        C[x] += num;
        x += Lowbit(x);
    }
}
int Sum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += C[x];
        x -= Lowbit(x);
    }
    return ans;
}
int binarysearch(int l,int k){
    int mid, left, right, tmp;
    left = l + 1;
    right = N - 1;
    if(Sum(right) - Sum(l) < k)return -1;
    while(left <= right){
        mid = (left + right) >> 1;
        tmp = Sum(mid) - Sum(l);
        if(tmp == k){
            if(vis[mid]){
                return mid;
            }
            right = mid - 1;
        }
        else if(tmp > k){
            if(Sum(mid - 1) - Sum(l) < k)return mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int p, n, m, T, e, a, k, l, r, mid;
    while(~scanf("%d",&T))
    {
        memset(C,0,sizeof(C));
        memset(vis,0,sizeof(vis));
        while(T--)
        {
            scanf("%d",&p);
            switch(p)
            {
            case 0:
                scanf("%d",&e);
                add(e,1);
                vis[e] = 1;
                break;
            case 1:
                scanf("%d",&e);
                m = Sum(e) - Sum(e-1);
                if(!m)printf("No Elment!\n");
                else add(e,-1);
                if(m == 1)vis[e] = 0;
                break;
            case 2:
                scanf("%d%d",&a,&k);
                m = binarysearch(a,k);
                if(m == -1)
                printf("Not Find!\n");
                else
                printf("%d\n",m);
                break;
            }
        }
    }
    return 0;
}
