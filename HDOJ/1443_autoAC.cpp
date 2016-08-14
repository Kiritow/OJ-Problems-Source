#include <cstdlib>
#include <iostream>
#include<string>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include <math.h>
using namespace std;
int n, a, b;
int con[15];
int run(int a, int b)
{
    int cnt = 0;
    int sum = 2 * a;
    int index = b % (2 * a);
    if(index == 0) index = sum;
    while(index > a)
    {
        sum--;
        index = (index + b - 1) % sum;
        if(index == 0) index = sum;
        cnt ++;
    }
    return cnt;
}
int solve(int a)
{
    for(int i=a+1; ; i++)
    {
        if(run(a, i) == a) return i;
    }
}
void init()
{
    for(int i=1; i<=14; i++)
    {
        con[i] = solve(i);
    }
}
int main()
{
    init();
    while(cin>>n)
    {
        if(n == 0) break;
        else cout<<con[n]<<endl;
    }
    return 0;
}
