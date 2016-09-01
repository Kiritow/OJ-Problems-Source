#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<deque>
#include<cmath>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define REP(i,s,t) for(int i=(s);i<=(t);i++)
#define REP2(i,t,s) for(int i=(t);i>=s;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
const int N=20;
const int Maxans=10240+10;
int a[N];
int bit[N];
vector<int>G[Maxans];
int state[1<<17];
bool judge(int x)
{
  int cnt=0;
  REP(i,1,16)
  {
    if(x&(1<<(i-1)))
    {
      bit[++cnt]=a[i];
    }
  }
  return cnt==4;
}
int fuck()
{
  REP(i,0,Maxans)
  {
    G[i].clear();
  }
  memset(state,0,sizeof(state));
  sort(a+1,a+1+16);
  REP(i,0,(1<<16)-1)
  {
    if(judge(i))
    {
      do
      {
        int tmp=bit[1]*1+bit[2]*2+bit[3]*3+bit[4]*4;
        for(int j=0;j<G[tmp].size();j++)
        {
          if((i&G[tmp][j])==0)
          {
            state[i|G[tmp][j]]++;
          }
        }
        G[tmp].push_back(i);
      }while(next_permutation(bit+1,bit+1+4));
    }
  }
  int ans=0;
  REP(i,0,(1<<16)-1)
  {
    ans+=state[i]*state[((1<<16)-1)^i];
  }
  return ans/2;
}
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("test.in","r",stdin);
  #endif
  int ca=1;
  while(~scanf("%d",&a[1]))
  {
    if(!a[1])
    {
      break;
    }
    REP(i,2,16)
    {
      scanf("%d",&a[i]);
    }
    int ans=fuck();
    printf("Case %d: %d\n",ca++,ans);
  }
  return 0;
}
