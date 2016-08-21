#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    int qian;
    int v;
};
bool cmp(node a,node b)
{
    return a.qian>b.qian;
}
int main()
{
    int rong,zhonglei;
    int i;
    node f[2000];
    while(scanf("%d",&rong)&&rong)
    {
        int jiazhi=0;
        scanf("%d",&zhonglei);
        for(i=1;i<=zhonglei;i++)
            scanf("%d%d",&f[i].qian,&f[i].v);
        sort(f+1,f+1+zhonglei,cmp);
        for(i=1;i<=zhonglei;i++)
        {
            if(rong-f[i].v>=0)
            {
                jiazhi+=f[i].v*f[i].qian;
                    rong-=f[i].v;
            }
            else
            {
                jiazhi+=f[i].qian*rong;
                break;
            }
        }
        printf("%d\n",jiazhi);
    }
    return 0;
}
