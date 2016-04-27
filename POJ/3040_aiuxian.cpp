#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=30;
struct node
{
    int x,y;//存储钱的大小和数量
    bool operator<(const node c)const
    {
        return x>c.x;
    }
}num[maxn];
int need[maxn],n,c,kj;
//need[]函数是是存储需要哪些钱币的组合
int main()
{
    while(scanf("%d%d",&n,&c)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&num[i].x,&num[i].y);
        sort(num,num+n);//排序是第一步
        kj=0;
        while(1)
        {
            int sum=c;
            memset(need,0,sizeof(need));
            for(int i=0;i<n;i++)//这个for循环是用于找出钱币的组合方法
            {
                if(sum>0)
                {
                    int t=sum/num[i].x;
                    if(t==0)
                        continue;
                    t=min(t,num[i].y);
                    need[i]=t;
                    sum-=t*num[i].x;
                }
            }

            if(sum>0)//如果在上面的组合中没有使sum变为0,则从小到大选择最小的面值组合，这样使面值超过的最小化
            {
                for(int i=n-1;i>=0;i--)
                if(num[i].y&&num[i].x>=sum)
                {
                    sum=0;
                    need[i]++;
                    break;
                }
            }
            if(sum>0)//如果组合不能达到c，怎么说明搜索结束
                break;
            int cc=2e9;
            for(int i=n-1;i>=0;i--)//找出这个组合成的面值中最小的数量，同时减去它们。
            {
                if(need[i])
                {
                    cc=min(cc,num[i].y/need[i]);
                }
            }
            kj+=cc;
            for(int i=0;i<n;i++)
                if(need[i])
            {
                num[i].y-=cc*need[i];
            }
        }
        printf("%d\n",kj);
    }
    return 0;
}
