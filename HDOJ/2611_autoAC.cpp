#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int a[1001];
int n,p,len,tmp;
struct node {
    int num;
    int pos;
};
node tree[1001];
bool cmp(const node& x,const node& y)
{
    if(x.num!=y.num)
    return x.num<y.num;
    else
    return x.pos<y.pos;
}
void print(int x)
{
    int i;
    for(i=0;i<x-1;i++)
       printf("%d ",a[i]);
       printf("%d\n",a[i]);
}
bool dfs(int deep,int pos,int pp)
{
    int pre,i;
    bool flag=false;
    if(deep == len)
    {
        tmp++;
        print(deep);
        if(tmp == p)
        return true;
        return false;
    }
    if(pos>n)
        return false;
    for(i=pos;i<n;i++)
    {
        if(tree[i].pos > pp )
        {
                if(!flag)
                {
                    pre=tree[i].num;
                    flag=true;
                }
                else if(pre == tree[i].num)
                    continue;
                pre=tree[i].num;
                a[deep]=tree[i].num;
                if(dfs(deep+1,i+1,tree[i].pos))
                    return true;
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d%d",&n,&p))
    {
        int tc;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tc);
            tree[i].num=tc;
            tree[i].pos=i;
        }
        sort(tree,tree+n,cmp);
        tmp=0;
        for(int i=1;i<n;i++)
        {
            len=i;
            if(dfs(0,0,-1))
                break;
        }
        printf("\n");
    }
    return 0;
}
