#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int N,C;
long long a[1000010];
long long f[1000010];
struct point
{
    int id;
    long long  x,y;
    point(int a,long long b,long long c)
    {
        id = a;x = b;y = c;
    }
    point(){};
};
long long  solve()
{
    static point s[1000010];
    int head = 1,tail = 0;
    long long temp;
    for (int i = 1;i <= N;i++)
    {
        point p(i-1,a[i],f[i-1]+ a[i]*a[i]);
        while(tail-1 >= head && (s[tail].x - s[tail-1].x)*(p.y - s[tail].y) - (s[tail].y - s[tail-1].y) *(p.x - s[tail].x) <0)
            tail --;
        s[++tail] = p;
        while (head <= tail && (temp = s[head].y - 2*a[i]*s[head].x+a[i]*a[i] + C,temp < f[i]||f[i] == -1))
        {
            f[i] = temp;
            head++;
        }
        head--;
    }
    return f[N];
}
int main()
{
    while(scanf("%d%d",&N,&C),N+C)
    {
        a[0] = 0;
        for(int i = 1;i <= N;i++)
            scanf("%d",&a[i]);
        memset(f,-1,sizeof(f));
        f[0] = 0;
        printf("%I64d\n",solve());
    }
    return 0;
}
