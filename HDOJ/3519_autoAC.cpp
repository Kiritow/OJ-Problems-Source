#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define LG long long
using namespace std;
const int maxn=10005,MAX=1<<30,MIN=-(1<<30);
struct node
{
    int gp[5][5];
}A,B;
int n,m;
node mul(node a,node b)
{
    node c;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            c.gp[i][j]=0;
            for(int k=0;k<4;k++)
            {
                c.gp[i][j]+=a.gp[i][k]*b.gp[k][j];
                c.gp[i][j]%=m;
            }
        }
        return c;
}
node sort_exp(int k)
{
    node ans=B,a=A;
    while(k)
    {
        if(k&1)ans=mul(ans,a);
        k>>=1;
        a=mul(a,a);
    }
    return ans;
}
int main()
{
    for(int i=0;i<2;i++)
        B.gp[i][i]=1;
    memset(A.gp,0,sizeof(A.gp));
    A.gp[0][0]=A.gp[0][1]=A.gp[1][0]=A.gp[1][2]=A.gp[2][3]=1;
    A.gp[3][3]=2;
    m=10007;
    while(~scanf("%d",&n))
    {
        node ans=sort_exp(n);
        printf("%d\n",2*ans.gp[0][3]%m);
    }
    return 0;
}
