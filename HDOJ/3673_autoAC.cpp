#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans;
unsigned int m;
int l[2000000];
int t[2000000];
int a[200000];
struct cmp
{
    bool operator()(int x,int y)const
    {
    if(l[x]<l[y])return true;
    else if(l[x]==l[y]&&t[x]>t[y]) return true;
    return false;
    }
};
set<int,cmp> myset;
set<int,cmp>::reverse_iterator it;
int main()
{
    int sec=0;
    while(scanf("%u%d",&m,&n),m||n)
    {
        sec++;ans=0;
        myset.clear();
        memset(l,0,sizeof(l));
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            if(myset.count(a[i])==0)
            {
                if(myset.size()<m)
                {
                    l[a[i]]=1;t[a[i]]=i;myset.insert(a[i]);
                }
                else
                {
                    ans++;
                    it=myset.rbegin();
                    myset.erase(*it);
                    l[a[i]]=1;t[a[i]]=i;myset.insert(a[i]);
                }
            }
            else
            {
                myset.erase(a[i]);
                l[a[i]]++;
                myset.insert(a[i]);
            }
        }
        printf("Case %d: %d\n",sec,ans);
    }
    return 0;
}
