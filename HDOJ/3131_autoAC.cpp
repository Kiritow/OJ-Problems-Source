#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#define LL __int64
using namespace std;
LL a[20],cnt,k;
map<LL,LL> ans;
map<LL,LL>::iterator it;
bool cmp(LL a,LL b)
{
    return a>b;
}
LL cal(LL sum,LL temp,LL op)
{
    if(op==0)
        return sum+temp;
    if(op==1)
        return sum-temp>0? sum-temp:temp-sum;
    if(op==2)
        return sum*temp;
    if(op==3)
        return sum/temp;
}
void dfs(LL x,LL sum)
{
    if(x==cnt)
    {
        LL tempsum=sum;
        while(tempsum)
        {
            if(tempsum%10==3)
            {
                ans[sum]++;
                k++;
                break;
            }
            tempsum/=10;
        }
        return  ;
    }
    for(LL i=0;i<4;i++)
    {
        if(i==3 && a[x]==0)
            continue;
        LL temp=cal(sum,a[x],i);
        dfs(x+1,temp);
    }
}
int main()
{
    char s[100];
    LL len,i;
    while(gets(s))
    {
        if(s[0]=='#')
            break;
        ans.clear();
        len=strlen(s);
        LL temp;
        cnt=temp=0;
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                a[cnt++]=temp;
                temp=0;
                continue;
            }
            temp=temp*10+s[i]-'0';
        }
        a[cnt++]=temp;
        k=0;
        dfs(1,a[0]);
        if(k)
        {
            LL maxt=-1,maxans;
            for(it=ans.begin();it!=ans.end();it++)
            {
                if(maxt<=(it->second))
                {
                    maxt=it->second;
                    maxans=it->first;
                    if((it->first)>maxans)
                        maxans=it->first;
                }
            }
            printf("%I64d\n",maxans);
        }
        else
            printf("No result\n");
    }
    return 0;
}
