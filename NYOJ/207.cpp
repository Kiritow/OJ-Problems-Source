#include <bits/stdc++.h>
using namespace std;

#define MAXN 50005

int father[MAXN];
///Relationship: 0 Same 1 Father--eat-->son 2 son--eat-->father
int relation[MAXN];


int find(int pos)
{
    if(father[pos]!=pos)
    {
        int x=father[pos];
        father[pos]=find(x);
        relation[pos]=(relation[pos]+relation[x])%3;
    }
    return father[pos];
}

int main()
{
    int N,K;
    while(scanf("%d %d",&N,&K)==2)
    {
        /// Init
        for(int i=0; i<=N; i++)
        {
            relation[i]=0;
            father[i]=i;
        }
        int a,b,c;
        int cnt=0;
        for(int i=0;i<K;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a==2&&b==c)
            {
                ++cnt;continue;
            }
            if(b>N||c>N)
            {
                ++cnt;continue;
            }
            int rootfather_b=find(b);
            int rootfather_c=find(c);
            if(rootfather_b==rootfather_c)
            {
                if(a==1&&relation[b]!=relation[c])
                {
                    ++cnt;continue;
                }
                if(a==2&&relation[b]!=(relation[c]+2)%3)
                {
                    ++cnt;continue;
                }
            }
            else
            {
                father[rootfather_c]=rootfather_b;
                relation[rootfather_c]=(relation[b] + (a-1) + (3-relation[c])) % 3;

            }
        }
        printf("%d\n",cnt);
    }
    return 0;

}
