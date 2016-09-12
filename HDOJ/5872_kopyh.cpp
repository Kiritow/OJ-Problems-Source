//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1123456
using namespace std;
long long n,m,sum,res,flag;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    long long i,j,cas,T,t,x,y,z,h,l,k;
    while(scanf("%I64d%I64d%I64d",&h,&l,&k)!=EOF)
    {
        x=k/h;//最大人数时一排几个部门
        y=k/(x+1);//多放一个部门时每个部门最多的人数
        res=y+1;//加一个人保证不能多放一个部门
        printf("%I64d\n",l/(k-k%res)+bool(l%(k-k%res)));//ok
    }
    return 0;
}
