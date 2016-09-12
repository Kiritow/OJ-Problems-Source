#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=100000+100;
char s[maxn];
char ts[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s,ts);
        int n1=strlen(s);
        int n2=strlen(ts);
        int cur=0;
        for(int i=0;i<n2;i++)
        {
            if(ts[i]==s[cur])
            cur++;
            if(cur==n1)
            break;
        }
        if(cur==n1)
        {
            int a1=1,a2=1;
            for(int j=1;j<n1;j++)
            {
                if(s[j]==s[0])
                a1++;
                else
                break;
            }
            for(int j=1;j<n2;j++)
            {
                if(ts[j]==ts[0])
                a2++;
                else
                break;
            }
            if(a2>a1||s[0]!=ts[0])
            printf("No\n");
            else
            printf("Yes\n");
        }
        else
        printf("No\n");
    }
    return 0;
}
