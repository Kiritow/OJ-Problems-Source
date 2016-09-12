#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int _,ans;
int state(int i,int l,int r)
{
    if((1 << i) <= l)return 1;
    else if((1 << i) > r)return 0;
    else return -1;
}
void deal(int & l,int & r,int v,int i)
{
    l = max(l - v,0);
    r = min(max(r - v,0),(1 << i) - 1);
}
void dfs(int l1,int r1,int l2,int r2,int i,int cur)
{
    if(l2 <= l1 && r1 <= r2 || i == -1)return;
    if(cur + ((LL)1 << (i + 1)) - 1 < ans)return;
    int st1 = state(i,l1,r1),st2 = state(i,l2,r2);
    if(st1 >= 0 && st2 >= 0)
    {
        cur |= ((st1 ^ st2) << i);
        ans = max(cur,ans);
        deal(l1,r1,st1 << i,i) , deal(l2,r2,st2 << i,i);
        dfs(l1,r1,l2,r2,i - 1,cur);
    }
    else if(st1 == -1 && st2 == -1)
    {
        dfs(l1,min(r1,(1 << i) - 1),l2,min(r2,(1 << i) - 1),i - 1,cur);
        deal(l1,r1,1 << i,i) , deal(l2,r2,1 << i,i);
        dfs(l1,r1,l2,r2,i - 1,cur);
    }
    else if(st1 >= 0 && st2 == -1)
    {
        deal(l1,r1,st1 << i,i) , deal(l2,r2,st1 << i,i);
        dfs(l1,r1,l2,r2,i - 1,cur);
    }
    else// if(st1 == -1 && st2 >= 0)
    {
        cur |= (1 << i);
        ans = max(cur,ans);
        deal(l1,r1,!st2 << i,i) , deal(l2,r2,st2 << i,i);
        dfs(l1,r1,l2,r2,i - 1,cur);
    }
}
int main()
{
    scanf("%d",&_);
    for(int kcas = 1;kcas <= _;kcas++)
    {
        int l1,l2,r1,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        ans = 0;
        dfs(l1,r1,l2,r2,30,0);
        printf("Case #%d: %d\n",kcas,ans);
    }
}
