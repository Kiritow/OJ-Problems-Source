#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char str1[200];
char str2[200];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int d,n;
        scanf("%d%*c",&d);
        gets(str1);
        int len=strlen(str1);
        scanf(" %d",&n);
        int p=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            p = (p+x+len)%len;
            str2[i]=str1[p];
        }
        printf("%d ",d);
        for(int i=0;i<n;i++)
            printf("%c",str2[i]);
        printf("\n");
    }
    return 0;
}
