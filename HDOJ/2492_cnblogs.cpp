#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
 
using namespace std;
//Constant Declaration
/*--------------------------*/
//#define LL long long 
#define LL __int64
const int M=100001;
const int INF=1<<30;
const double EPS = 1e-11;
const double PI = acos(-1.0);
/*--------------------------*/
// some essential funtion
/*----------------------------------*/
void Swap(int &a,int &b){   int t=a;a=b;b=t; }
int Max(int a,int b){   return a>b?a:b;  }
int Min(int a,int b){   return a<b?a:b;  }
int Gcd(int a,int b){   while(b){b ^= a ^=b ^= a %= b;}  return a; }
/*----------------------------------*/
//for (i = 0; i < n; i++)
/*----------------------------------*/

LL c[M];
int a[M];
int left_lower[M], right_lower[M];//分别是，在第i个数左右边，比第i个数小的个数
int n = 100000;


int LowBit(int x)
{
    return x&(-x);
}

int Sum(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += c[k];
        k -= LowBit(k);
    }
    return sum;
}

void Update(int k, int sc)
{
    while (k <= 100000)
    {
        c[k] += sc;
        k += LowBit(k);
    }
}


 
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 int t, case1 = 0;
 scanf("%d", &t);
 int m;
 int i, j;
 int num;
 //scanf("%d%d", &n, &m);
 while (t--)
 {
    scanf("%d", &num);
    memset(c, 0, sizeof(c));
    memset(left_lower, 0, sizeof(left_lower));
    memset(right_lower, 0, sizeof(right_lower));
    for (i = 1; i <= num; i++)
    {
        scanf("%d", &a[i]);
        left_lower[i] += Sum(a[i] - 1);///Sum(a[i] - 1)：插入该数前，区间1到a[i]-1的总个数
        Update(a[i], 1);
    }
    
    memset(c, 0, sizeof(c));
    for (i = num; i > 0; i--)//顺序插入
    {
        right_lower[i] += Sum(a[i] - 1);
        Update(a[i], 1);
    }

    LL ans = 0;
    
    for (i = 1; i <= num; i++)//逆序插入
    {
        ans += left_lower[i]*(num - i - right_lower[i]);//由于只能求比其小的个数，可以用i右边的总个数见减比他小的来求比他大的个数。
        ans += (i - 1 - left_lower[i])*right_lower[i];//
    }

    printf("%I64d\n", ans);
 }
 

 return 0;
}
