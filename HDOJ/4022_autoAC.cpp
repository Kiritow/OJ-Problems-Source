#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<iterator>
using namespace std;
typedef map<int,multiset<int> > def;
void pop(def &a,def &b,int k)
{
    printf("%d\n",a[k].size());
    for(multiset<int>::iterator i=a[k].begin();i!=a[k].end();i++)
        b[*i].erase(k);
    a[k].clear();
}
int main()
{
    int n,m,x,y;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)return 0;
        def h;def l;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            h[x].insert(y);
            l[y].insert(x);
        }
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&x,&y);
           if(x==0)
                pop(h,l,y);
            else
                pop(l,h,y);
        }
        printf("\n");
    }
    return 0;
}
