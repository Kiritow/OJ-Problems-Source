#include <iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
const int INF=0x3f3f3f3f;
using namespace std;

struct node
{
    int val,mou;//面值和数目
} mon[25];
int n,c;
int need[25];//一种方案所需各面值的数目
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int main()
{
    int i,ans,ti,rest,lim,mday;

    while(~scanf("%d%d",&n,&c))
    {
        ans=0;
        lim=-1;
        for(i=0;i<n;i++)
            scanf("%d%d",&mon[i].val,&mon[i].mou);
        sort(mon,mon+n,cmp);
        for(i=n-1;i>=0;i--)
            if(mon[i].val>=c)//如果面值大于c直接加数目就行了
               ans+=mon[i].mou;
            else
            {
                lim=i;
                break;
            }
        while(1)
        {
            memset(need,0,sizeof need);
            rest=c;
            for(i=lim;i>=0;i--)//尽可能用大面值凑够
            {
                if(!mon[i].mou||!rest)
                    continue;
                ti=rest/mon[i].val;
                ti=min(ti,mon[i].mou);
                need[i]=ti;
                rest-=ti*mon[i].val;
            }
            if(rest)//没凑够的话。只能往回找最小的面值凑够。保证损失的钱最少
            {
                for(i=0;i<=lim;i++)
                {
                    if(mon[i].val>=rest&&(mon[i].mou-need[i]))
                    {
                        need[i]++;
                        rest=0;
                        break;
                    }
                }
                if(rest)
                    break;
            }
            mday=INF;
            for(i=0;i<=lim;i++)
                if(need[i])
                mday=min(mday,mon[i].mou/need[i]);//得出该种方案能支付的最大周数
            ans+=mday;
            for(i=0;i<=lim;i++)
                mon[i].mou-=mday*need[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
11 
6 1
4 1
*/
