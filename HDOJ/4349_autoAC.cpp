#include"cstdlib"
#include"cstdio"
#include"cstring"
#include"cmath"
#include"stack"
#include"algorithm"
#include"iostream"
#define ll __int64
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int cnt=0;
        while(n)
        {
            if(n%2==1) cnt++;
            n/=2;
        }
        printf("%d\n",1<<cnt);
    }
    return 0;
}
