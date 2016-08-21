#include <iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#define leps 1e-6
using namespace std;
const int maxn=1000+7;
const int maxc=1e9+7;
int n,b,t,id;
struct component
{
    int price;
    int quality;
};
vector<component>v[maxn];
void clear()
{
    for(int i=0;i<maxn;i++)
    v[i].clear();
}
void read_data(int &minn,int &maxx)
{
    id=1;            
    map<string,int> m;
    char s[maxn],name[maxn];
    int p,q;
    component com;
    for(int i=1;i<=n;i++)
    {
       scanf("%s %s %d %d",s,name,&p,&q);
       minn=min(minn,q);
       maxx=max(maxx,q);
       if(m[s])
       {
           com.price=p;
           com.quality=q;
           v[m[s]].push_back(com);
       }
       else
       {
           m[s]=id++;
           com.price=p;
           com.quality=q;
           v[m[s]].push_back(com);
       }
    }
}
int min_value(int i,int x) 
{
    int len=v[i].size();
    int temp=maxc;
    for(int j=0;j<len;j++)
    {
        if(v[i][j].quality>=x)
        {
            temp=min(temp,v[i][j].price);
        }
    }
    if(temp==maxc)return -1;
    return  temp;
}
bool ok(int x)
{
    long long ans=0;
    for(int i=1;i<id;i++)
    {
        if(min_value(i,x)==-1)
        return false;
        ans+=min_value(i,x);
    }
    if(ans<=b)return true;
    else return false;
}
int bisearch(int a,int b)
{
    int l,r,mid;
    l=a;r=b;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(ok(mid))l=mid+1;
        else r=mid-1;
    }
    return mid;
}
int main()
{
    int minn,maxx;
    scanf("%d",&t);
    while(t--)
    {
        clear();
        scanf("%d %d",&n,&b);
        minn=maxc;maxx=0;
        read_data(minn,maxx);
        int temp=bisearch(minn,maxx);
        int ans=0;
        for(int i=1;i<id;i++)
        {
            int len=v[i].size();
            for(int j=0;j<len;j++)
            {
                if(v[i][j].quality<=temp)
                ans=max(ans,v[i][j].quality);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
