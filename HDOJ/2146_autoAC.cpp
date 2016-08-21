#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long p[100000], mi[60], temp;
char v[60];
int main()
{
    int n,k,i,r,l,num,ans,max;
    for(i=0,temp=1;i<60;i++)
    {
        mi[i]=temp;
        temp<<=1;
    }
    while(scanf("%d%d%d",&n,&l,&k)!=EOF)
    {
        for(i=num=0;i<n;i++)
        {
            scanf("%s",v);
            temp=0;
            for(r=0;r<k;r++)
                temp+=(v[r]-'0')*mi[r];
            p[num++]=temp; 
            for(r=k;r<l;r++)
            {
                temp>>=1; 
                temp+=(v[r]-'0')*mi[k-1];
                p[num++]=temp;
            }
        }
        sort(p,p+num);
        ans=1; max=0;
        for(i=1;i<num;i++)
        {
            if(p[i]==p[i-1]) ans++;
            else
            {
                max=(max>ans?max:ans);
                ans=1;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
