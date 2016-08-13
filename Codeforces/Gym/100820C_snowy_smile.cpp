#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1,class T2>inline void gmax(T1 &a,T2 b){if(b>a)a=b;}
template <class T1,class T2>inline void gmin(T1 &a,T2 b){if(b<a)a=b;}
const int N=0,M=0,Z=1e9+7,ms63=1061109567;
int casenum,casei;
int n;
struct A
{
    char name[300];
    int b[50];
    bool operator < (const A& bb)const
    {
        for(int i=0;i<48;++i)
        {
            if(b[i]>bb.b[i])return 1;
            if(b[i]<bb.b[i])return 0;
        }
        return strcmp(name,bb.name)<0;
    }
}a[1010];
char s[300];
int b[50];
int main()
{
    while(~scanf("%d",&n))
    {
        MS(a,0);
        for(int i=1;i<=n;++i)
        {
            scanf("%s",a[i].name);
            int l=strlen(a[i].name);
			a[i].name[l-1]=0;
            int top=0;
            while(1)
            {
                scanf("%s",s);
                if(s[0]=='c')break;
                if(s[0]=='u')b[++top]=1;
                else if(s[0]=='m')b[++top]=0;
                else if(s[0]=='l')b[++top]=-1;
            }
            int p=0;
            while(top)a[i].b[p++]=b[top--];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i)printf("%s\n",a[i].name);
    }
}
/*
【题意】
n（1<=n<=1000）个人，参加了n种难度的课程。
我们要把这n个人的课程难度按照从大到小排序，并依次输出人名。

具体的排序规则是——
课程前缀由 upper>middle>lower的顺序排序。
多个前缀关键字，位于最后的关键字作为第一关键字，依次类推。
如果发生关键字数量差别，空关键字被认定为middle。
如果最后依然重复，则按照人名字典序。

【类型】
模拟 排序 多关键字排序

【分析】
这题只是一个关键字有点多的排序而已。
最多会有256/6个关键字。我们直接把所有的关键字提取出来，位置越后，级别越高。
upper=1
middle=0（初始也为0）
lower=-1
然后排个序，这道题就做完啦！

【时间复杂度&&优化】
O（关键字数*nlogn）

【数据】
5
mom: upper upper lower middle class
dad: middle middle lower middle class
queenelizabeth: upper upper class
chair: lower lower class
unclebob: middle lower middle class

*/
