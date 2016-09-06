#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int t, n, m;
int f[1005];
bool emerge[1000];
int get_sg(int len)
{
    if(len<m) return f[len]=0;
    if(f[len]!=-1) return f[len];
    bool vs[1001]={0};
    for(int i=0; len-i-m>=0; i++)
        vs[get_sg(i)^get_sg(len-i-m)]=1;
    for(int i=0; i<1001; i++)
        if(!vs[i]) return f[len]=i;
}
int main()
{
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++)
    {
        scanf("%d%d", &n, &m);
        memset(f, -1, sizeof(f));
        printf("Case #%d: ", ca);
        if(n<m || get_sg(n-m)) printf("abcdxyzk\n");
        else printf("aekdycoin\n");
    }
    return 0;
}
