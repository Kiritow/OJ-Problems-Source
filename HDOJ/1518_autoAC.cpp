#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[25],sji,d[25],ji,n;
bool b[25];
void dfs(int digit,int num,int bj)
{
    if(num == ji)
    {
        digit++;
        num=0;
    }
    if(digit == 3)
    {
        sji=1;
        return ;
    }
    int i;
    if(num == 0)bj=digit;
    for(i=bj+1;i<n;i++)
    {
        if(b[i] && a[i]+num<=ji)
        {
            b[i]=false;
            dfs(digit,a[i]+num,i);
            b[i]=true;
        }
        if(sji)return ;
    }
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int t,i,j;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            ji=0;
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                b[i]=true;
                ji+=a[i];
            }
            if(ji%4)
            {
                printf("no\n");
                continue;
            }
            ji/=4;
            sort(a,a+n,cmp);
            if(a[0] >ji)
            {
                printf("no\n");
                continue;
            }
            b[0]=false;
            sji=0;
            dfs(0,a[0],0);
            if(!sji)printf("no\n");
            else printf("yes\n");
        }
    }
    return 0;
}
