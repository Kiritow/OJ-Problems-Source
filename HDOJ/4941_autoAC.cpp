#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
map<int,map<int,int> >mm;
map<int,int>row;
map<int,int>col;
int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        row.clear();
        col.clear();
        mm.clear();
        int n,m,i,j,k,rr=0,cc=0,a,b,c,x,y;
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(!row[a])
            {
                row[a]=++rr;
                x=rr;
            }
            else x=row[a];
            if(!col[b])
            {
                col[b]=++cc;
                y=cc;
            }
            else y=col[b];
            mm[x][y]=c;
        }
        int q;
        printf("Case #%d:\n",++tt);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                int t=row[b];
                row[b]=row[c];
                row[c]=t;
            }
            else if(a==2)
            {
                int t=col[b];
                col[b]=col[c];
                col[c]=t;
            }
            else
            {
                printf("%d\n",mm[row[b]][col[c]]);
            }
        }
    }
    return 0;
}
