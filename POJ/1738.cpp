#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 50001
int stone[MAXN];
int n;
int t;
int ans;///合并分数

void proc(int index)///合并主逻辑
{
    int tmp=stone[index-1]+stone[index];///计算合并这两堆石子得到的分数
    ans+=tmp;
    for(int i=index;i<t-1;i++)///石子左移空出一个位置,同时也会把合并起点左移一个
    {
        stone[i]=stone[i+1];
    }
    --t;///恢复合并起点
    int ci;
    for(ci=index-1;ci>0;--ci)///由合并前的位置左侧开始寻找一个更大的数字
    {
        if(stone[ci-1]>=tmp)
        {
            break;///找到第一个更大的数字
        }
        else
        {
            ///这说明这个数字不是更大的，右移这个数字
            stone[ci]=stone[ci-1];
        }
    }
    stone[ci]=tmp;///左边是更大的数字，因此放在这个数字的右边。
    ///这个数字里面的内容已经被右移了一格所以并没有丢失数据

    ///因为一直要在左侧寻找更大的数据因而转向左侧石子的合并
    while(ci>=2 && stone[ci-2]<=stone[ci])
    {
        ///这是符合条件的状态(即stone[k-1]<=stone[k+1])
        ///保存合并起点和操作点的距离
        int dis=t-ci;
        proc(ci-1);
        ///设置新的操作点(?)
        ci=t-dis;
    }
}


int main()
{
    while(scanf("%d",&n)==1&&n!=0)
    {
        memset(stone,0,sizeof(int)*MAXN);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&stone[i]);
        }
        if(n==1)
        {
            printf("0\n");continue;
        }
        if(n==2)
        {
            printf("%d\n",stone[0]+stone[1]);continue;
        }

        t=1;
        ans=0;

        for(int i=1;i<n;i++)
        {
            stone[t]=stone[i];
            t++;///合并起点右移
            while(t>=3&&stone[t-3]<=stone[t-1])
            {
                proc(t-1-1);
            }
        }
        ///如果石子的堆数仍然大于1(即石子堆的合并起点大于1),那么继续操作直到合并起点降为1
        while(t>1) proc(t-1);

        printf("%d\n",ans);
    }
    return 0;
}
