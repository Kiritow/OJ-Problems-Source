#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int num[100010];
int zuo[100010];
int you[100010];
int has[10010];
int Scan()
{
    int res = 0, ch, flag = 0;
    if((ch = getchar()) == '-')               
        flag = 1;
    else if(ch >= '0' && ch <= '9')            
        res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9' )
        res = res * 10 + ch - '0';
    return flag ? -res : res;
}
vector<int>my[10010];
int main()
{
    int n;
    for(int i=1;i<=10000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                my[i].push_back(j); 
            } 
        } 
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            num[i]=Scan();
        }
        memset(zuo,-1,sizeof zuo);
        memset(you,-1,sizeof you);
        /*
        memset(has,0,sizeof has);
        for(int i=1;i<=n;i++)
        {
            if(has[num[i]]!=0) 
                zuo[i]=has[num[i]]+1;
            has[num[i]]=i;
        }
        memset(has,0,sizeof has);
        for(int i=n;i>=1;i--)
        {
            if(has[num[i]]!=0) 
                you[i]=has[num[i]]-1;
            has[num[i]]=i;
        }
        */
        memset(has,0,sizeof has);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<my[num[i]].size();j++)
            {
                int tt=my[num[i]][j];
                if(has[tt])
                {
                    if(num[i]%tt==0)
                    {
                        if(zuo[i]!=-1)
                            zuo[i]=max(zuo[i],has[tt]+1);
                        else
                            zuo[i]=has[tt]+1;
                    }
                }
            }
            has[num[i]]=i; 
        }
        memset(has,0,sizeof has);
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<my[num[i]].size();j++)
            {
                int tt=my[num[i]][j];
                if(has[tt])
                {
                    if(num[i]%tt==0)
                    {
                        if(you[i]!=-1)
                            you[i]=min(you[i],has[tt]-1);
                        else
                            you[i]=has[tt]-1;
                    }
                }
            }
            has[num[i]]=i; 
        }
        for(int i=1;i<=n;i++)
        {
            if(zuo[i]==-1)
                zuo[i]=1;
            if(you[i]==-1)
                you[i]=n;
        }
        __int64 ans=0;
        for(int i=1;i<=n;i++)
        {
            __int64 l,r;
            l=(__int64)(i-zuo[i]+1);
            r=(__int64)(you[i]-i+1);
            ans=(ans+l*r)%1000000007;
        }
        printf("%I64d\n",ans);
    } 
    return 0;
}
