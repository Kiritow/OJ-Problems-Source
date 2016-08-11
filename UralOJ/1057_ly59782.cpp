#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x,y,k,b;
int f[40][40];//高度为i的树有j个1的 方案数
void init()
{
    f[0][0]=1;
    for(int i=1;i<=35;++i)
    {
        f[i][0]=f[i-1][0];//不管高度是几，有0个1的方案数都相同。
        for(int j=1;j<=i;++j)
            f[i][j]=f[i-1][j]+f[i-1][j-1];//左子树＋右子树。5
    }
}

int exchange(int n,int b)//把n换成b进制后，将非1、0位变为1后再当成2进制转为十进制得数
{
    int i=0,num=0,ans=0;
    int t[40]={0};
    while(n>0)
    {
        t[num++]=n%b;
        n/=b;
    }
    i=num-1;
    while(t[i]<=1) i--;//最高位开始找到第一个不是0或1的
    while(i>=0)
    {
        t[i]=1;//从这位开始后面都取1，才能得到跟这个数n最接近的数
        i--;
    }


    while(num>=0)//转化为十进制
    {
        ans=ans*2+t[num];
        num--;
    }

    return ans;
}

int cacl(int x,int k)
{
    int ans=0,tot=0;
    for(int i=31;i>0;--i)//从高位的开始找
    {
        if(x & (1<<i))
        {
            tot++;
            if(tot>k) break;
            x ^= (1<<i);
        }
        if(x & 1<<(i-1))//下一位还是1（向右子树走）
        {
            ans+=f[i-1][k-tot];
        }
    }
    if(x+tot==k) ans++;//上面循环并没有到0，单独判断高度为0，需要注意的是现在这个x已经变了，要么是1要么是0；
    return ans;
}

int main()
{
    scanf("%d%d%d%d",&x,&y,&k,&b);
    init();
    if(b==2)
    {
        printf("%d\n",cacl(y,k)-cacl(x-1,k));
    }
    else
    {
        x=exchange(x,b);
        y=exchange(y,b);
        printf("%d\n",cacl(y,k)-cacl(x-1,k));
    }

    return 0;
}
