#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#define ll __int64
#define MAX 1000009
using namespace std;
ll has[1000009];
ll b[4][8],op[32];
ll endval,start;
struct lmx{
    ll arr[4][8];
    ll  val;
    ll step;
    ll blankx[4];
    ll blanky[4];
};
ll a[4][8]=
{
   {11,12,13,14,15,16,17},
   {21,22,23,24,25,26,27},
   {31,32,33,34,35,36,37},
   {41,42,43,44,45,46,47}
};
ll _cnt(ll c[][8])
{
    ll s=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            s+=c[i][j]*op[8*i+j];
        }
    }
    return s;
}
void exchange(ll c[][8])
{
    ll i,j;
    for(i=0;i<4;i++)
    {
        for(j=1;j<8;j++)
        {
            if(c[i][j]==11)      swap(c[0][0],c[i][j]);
            else if(c[i][j]==21) swap(c[1][0],c[i][j]);
            else if(c[i][j]==31) swap(c[2][0],c[i][j]);
            else if(c[i][j]==41) swap(c[3][0],c[i][j]);
        }
    }
}
bool ihash(ll val)
{
    ll p=val%MAX;
    while(has[p]!=-1&&has[p]!=val)
    {
        p=(p+20)%MAX;
    }
    if(has[p]==-1){has[p]=val;return true;}
    return false;
}
void input()
{
    int i,j;
    for(i=0;i<4;i++)
    {
      for(j=1;j<8;j++)
      {
        scanf("%I64d",&b[i][j]);
      }
      b[i][0]=0;
    }
}
lmx s,h,t;
queue<lmx> q;
ll bfs()
{
    ll i,j,cnt=0,k,f=0,v,pos1,pos2,xx,yy;
   if(start==endval) return 0;
    while(!q.empty()) q.pop();
    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            if(b[i][j]==0) {s.blankx[cnt]=i;s.blanky[cnt]=j;cnt++;}
        }
    }
    memcpy(s.arr,b,sizeof(b));
    s.step=0;
    s.val=_cnt(b);
    has[s.val%MAX]=s.val;
    q.push(s);
    while(!q.empty())
    {
        h=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            t=h;
            xx=h.blankx[i];
            yy=h.blanky[i];
            for(j=0;j<4;j++)
            {
                for(k=0;k<8;k++)
                {
                   if(h.arr[xx][yy-1]+1==h.arr[j][k])
                   {
                       pos1=j;pos2=k;
                        swap(t.arr[pos1][pos2],t.arr[xx][yy]);
                    v=_cnt(t.arr);
                    t.blankx[i]=pos1;
                    t.blanky[i]=pos2;
                    if(ihash(v))
                    {
                        t.step=h.step+1;
                        t.val=v;
                        if(v==endval) return t.step;
                        q.push(t);
                    }
                   }
                }
            }
        }
    }
    return -1;
}
int main()
{
    ll i,j,n;
    scanf("%I64d",&n);
    op[0]=2;
    for(i=1;i<32;i++) op[i]=op[i-1]<<1;
    while(n--)
    {
        input();
        exchange(b);
        endval=_cnt(a);
        start=_cnt(b);
        memset(has,-1,sizeof(has));
        printf("%I64d\n",bfs());
    }
    return 0;
}
