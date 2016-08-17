#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b;
long long A[10],B[10];
void dp(int s,long long *p,int t)
{
    if(s<=0) return;
    int x=s/10,y=s%10;
    for(int i=1;i<=y;i++) p[i]+=t;
    while(x)
    {
        p[x%10]+=(y+1)*t;
        x/=10;
    }
    for(int i=0;i<=9;i++) p[i]+=t*(s/10);
    t*=10;
    dp(s/10-1,p,t);
}
int main()
{
    while(scanf("%d%d",&a,&b)&&b!=0)
    {
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        if(a<b)
            swap(a,b);
        b--;
        if(a>b)
        {
            dp(a,A,1);
            dp(b,B,1);
        }
        for(int i=0;i<9;i++)
            printf("%I64d ",A[i]-B[i]);
        printf("%I64d\n",A[9]-B[9]);
    }
    return 0;
}
