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
#define maxn 2000001
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
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
int g[50][50];
map<int,int> H1;
map<int,int> H2;
vector<int> x;
vector<int> y;
vector<int> kiss[50];
struct node
{
    int x1,x2,y1,y2;
}a[100];
int main()
{
    int t=read();
    for(int cas=1;cas<=t;cas++)
    {
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        H1.clear();
        H2.clear();
        x.clear();
        y.clear();
        for(int i=0;i<50;i++)
            kiss[i].clear();
        int n=read();
        for(int i=0;i<n;i++)
        {
            a[i].x1=read(),a[i].y1=read(),a[i].x2=read(),a[i].y2=read();
            if(a[i].x1>a[i].x2)
                swap(a[i].x1,a[i].x2);
            if(a[i].y1>a[i].y2)
                swap(a[i].y1,a[i].y2);
            x.push_back(a[i].x1);
            x.push_back(a[i].x2);
            y.push_back(a[i].y1);
            y.push_back(a[i].y2);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        y.erase(unique(y.begin(),y.end()),y.end());
        for(int i=0;i<x.size();i++)
            H1[x[i]]=i;
        for(int i=0;i<y.size();i++)
            H2[y[i]]=i;
        for(int i=0;i<n;i++)
        {
            a[i].x1=H1[a[i].x1];
            a[i].x2=H1[a[i].x2];
            a[i].y1=H2[a[i].y1];
            a[i].y2=H2[a[i].y2];
        }
        for(int i=0;i<n;i++)
            if(a[i].x1==a[i].x2)
                for(int j=a[i].y1;j<=a[i].y2;j++)
                    g[a[i].x1][j]=i+1;
        for(int i=0;i<n;i++)
            if(a[i].y1==a[i].y2)
                for(int j=a[i].x1;j<=a[i].x2;j++)
                    if(g[j][a[i].y1]!=0)
                        kiss[g[j][a[i].y1]].push_back(i+1);
        ll ans=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int flag=0;
                for(int k=0;k<kiss[i].size();k++)
                {
                    for(int m=0;m<kiss[j].size();m++)
                    {
                        if(kiss[i][k]==kiss[j][m])
                        {
                            flag++;
                            break;
                        }
                    }
                }
                ans+=flag*(flag-1)/2;
            }
        }
        printf("Case #%d:\n",cas);
        cout<<ans<<endl;
    }
}
