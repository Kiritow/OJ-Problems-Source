#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
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
#define maxn 1000006
#define mod 1000000007
#define eps 1e-9
#define e exp(1.0)
#define PI acos(-1)
const double EP  = 1E-10 ;
int Num;
const ll inf=999999999;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> Q;
map<int,int> H;
struct node
{
    int x,y;
};
node p[maxn];
int b[maxn];
vector<int> Q1[maxn];
int main()
{
    int t=read();
    for(int cas=1;cas<=t;cas++)
    {
        int n=read();
        H.clear();
        for(int i=1;i<=n;i++)
        {
            p[i].x=read(),p[i].y=read();
            Q.push_back(p[i].x);
            Q.push_back(p[i].y);
        }
        sort(Q.begin(),Q.end());
        Q.erase(unique(Q.begin(),Q.end()),Q.end());
        int len = Q.size();
        for(int i=0;i<len;i++)
            H[Q[i]]=i;
        for(int i=0;i<len;i++)
            Q1[i].clear(),b[i]=0;
        Q.clear();
        for(int i=1;i<=n;i++)
        {
            Q1[H[p[i].x]].push_back(H[p[i].y]);
        }
        for(int i=0;i<len;i++)
        {
            sort(Q1[i].begin(),Q1[i].end());
            Q1[i].erase(unique(Q1[i].begin(),Q1[i].end()),Q1[i].end());
        }
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<Q1[i].size();j++)
                b[Q1[i][j]]++;
        }
        int ans1 = 0,ans2 = 0,ans3 = 0;
        for(int i=0;i<len;i++)
        {
            if(Q1[i].size()==0)continue;
            if(Q1[i].size()==1)
            {
                if(b[Q1[i][0]]==1)
                    ans3++;
            }
            else
            {
                int flag = 1;
                for(int j=0;j<Q1[i].size();j++)
                {
                    if(b[Q1[i][j]]!=1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    ans1++;
            }
        }
        for(int i=0;i<len;i++)
            Q1[i].clear(),b[i]=0;
        for(int i=1;i<=n;i++)
        {
            Q1[H[p[i].y]].push_back(H[p[i].x]);
        }
        for(int i=0;i<len;i++)
        {
            sort(Q1[i].begin(),Q1[i].end());
            Q1[i].erase(unique(Q1[i].begin(),Q1[i].end()),Q1[i].end());
        }
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<Q1[i].size();j++)
                b[Q1[i][j]]++;
        }
        for(int i=0;i<len;i++)
        {
            if(Q1[i].size()==0)continue;
            if(Q1[i].size()==1)
            {
                if(b[Q1[i][0]]==1)
                    ans3++;
            }
            else
            {
                int flag = 1;
                for(int j=0;j<Q1[i].size();j++)
                {
                    if(b[Q1[i][j]]!=1)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    ans2++;
            }
        }
        printf("Case #%d: %d %d %d\n",cas,ans1,ans2,ans3/2);
    }
}
