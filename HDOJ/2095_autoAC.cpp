#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    int temp;
    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;
        int ans,i;
        for(i=0,ans=0;i<n;i++)
        {
            scanf("%d",&temp);
            ans^=temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
