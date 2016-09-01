#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
const int N = 1000005;
const int INF = 1 << 30;
const int M = 1005;
bool prime[N];
int p[N];
int pri[M],num[M];
int arr[M];
int k,cnt,ct;
void isprime()
{
    k = 0;
    memset(prime,true,sizeof(prime));
    for(int i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++] = i;
            for(int j=i+i;j<N;j+=i)
                prime[j] = false;
        }
    }
}
void Divide(int n)
{
    cnt = 0;
    int t = (int)sqrt(1.0*n);
    for(int i=0;p[i]<=t;i++)
    {
        if(n%p[i]==0)
        {
            int a = 0;
            pri[cnt] = p[i];
            while(n%p[i]==0)
            {
                n /= p[i];
                a++;
            }
            num[cnt] = a;
            cnt++;
        }
    }
    if(n > 1)
    {
        pri[cnt] = n;
        num[cnt] = 1;
        cnt++;
    }
}
void dfs(int dept,int product = 1)
{
    if(dept == cnt)
    {
        arr[ct++] = product;
        return;
    }
    for(int i=0;i<=num[dept];i++)
    {
        dfs(dept+1,product);
        product *= pri[dept];
    }
}
void Work(int n)
{
    ct = 0;
    Divide(n);
    dfs(0,1);
    sort(arr,arr+ct);
    int ctt = 0;
    int ansx = INF;
    int ansy = INF;
    int tmpx = 0;
    int tmpy = 0;
    for(int i=0;i<ct;i++)
    {
        int t = n / arr[i] * 12 - 3 * arr[i] * arr[i];
        if(t >= 0)
        {
            int tmp = (int)sqrt(t * 1.0);
            if(tmp * tmp == t)
            {
                if((3*arr[i] - tmp)%6==0)
                {
                    ctt++;
                    tmpx = (3*arr[i] - tmp) / 6;
                    if(tmpx < ansx)
                    {
                        ansx = tmpx;
                        ansy = arr[i] - tmpx;
                    }
                }
                if((3*arr[i] + tmp)%6==0)
                {
                    ctt++;
                    tmpx = (3*arr[i] + tmp) / 6;
                    if(tmpx < ansx)
                    {
                        ansx = tmpx;
                        ansy = arr[i] - tmpx;
                    }
                }
            }
        }
    }
    if(ctt == 0) puts("Impossible");
    else printf("%d %d\n",ansx,ansy);
}
int main()
{
    int n;
    isprime();
    while(~scanf("%d",&n))
    {
        if(n == 0) break;
        Work(n);
    }
    return 0;
}
