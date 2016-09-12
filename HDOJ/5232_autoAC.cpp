#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 200001
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
const int inf=0x3f3f3f3f;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void P(int x)
{
    Num=0;if(!x){putchar('0');puts("");return;}
    while(x>0)CH[++Num]=x%10,x/=10;
    while(Num)putchar(CH[Num--]+48);
    puts("");
}
int g[300][300];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j]=read();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j])
                {
                    ans++;
                    g[i][j]=0;
                    g[j][i]=0;
                }
            }
        }
        cout<<(ans+n)*2<<endl;
    }
}
