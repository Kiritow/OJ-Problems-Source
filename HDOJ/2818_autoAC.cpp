#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<memory.h>
#include<cstring>
using namespace std;
int father[30002],low[30002],high[30002];
int find(int x)
{
    if(x==father[x])
        return x;
    int dx=find(father[x]);
    low[x]+=low[father[x]];
    return father[x]=dx;
}
void clear()
{
    for(int i=0;i<30002;i++)
    {
        father[i]=i;
        high[i]=1;
    }
    memset(low,0,sizeof(low));
}
int main()
{
    char ch;
    int a,b,n;
    while(cin>>n)
    {
        getchar();
        clear();
        while(n--)
        {
            cin>>ch;
            if(ch=='M')
            {
                scanf("%d %d%*c",&a,&b);
                int x=find(a);
                int y=find(b);
                if(x==y)
                    continue;
                father[x]=y;
                low[x]=high[y];
                high[y]+=high[x];
            }
            if(ch=='C')
            {
                scanf("%d%*c",&a);
                find(a);
                cout<<low[a]<<endl;
            }
        }
    }
    return 0;
}
