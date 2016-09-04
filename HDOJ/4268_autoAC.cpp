#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
multiset<int> myset;
multiset<int>::iterator it;
const int maxn=200000;
struct node
{
    int x,y;
    bool operator<(const node& b)const
    {
        return x<b.x;
    }
}a[maxn],b[maxn];
int main()
{
    int sec,n;
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        myset.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=1;i<=n;i++)
        scanf("%d%d",&b[i].x,&b[i].y);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int j=1;int ans=0;
        for(int i=1;i<=n;i++)
        {
            while(j<=n&&b[j].x<=a[i].x)
            {
                myset.insert(b[j].y);
                j++;
            }
            it=myset.upper_bound(a[i].y);
            if(myset.size()>0&&it!=myset.begin())it--;
            if(myset.size()>0&&(*it)<=a[i].y)
            {
                ans++;
                myset.erase(it);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
