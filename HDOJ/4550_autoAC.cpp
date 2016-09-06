#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN=110;
char str[MAXN];
char sta1[MAXN],sta2[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",&str);
        int n=strlen(str);
        int t1=0,t2=0;
        int t=n-1;
        while(t>0 && str[t]=='0')t--;
        for(int i=t;i>=0;i--)
            if(str[i]!='0'&&str[i]<str[t])
                t=i;
        sta1[t1++]=str[t];
        for(int i=n-1;i>t;i--)sta2[t2++]=str[i];
        while(t1+t2<n && t>0)
        {
            int tmp=t-1;
            for(int j=tmp-1;j>=0;j--)
                if(str[j]<str[tmp])
                    tmp=j;
            sta1[t1++]=str[tmp];
            for(int i=t-1;i>tmp;i--)sta2[t2++]=str[i];
            t=tmp;
        }
        for(int i=0;i<t1;i++)printf("%c",sta1[i]);
        for(int i=t2-1;i>=0;i--)printf("%c",sta2[i]);
        printf("\n");
    }
}
