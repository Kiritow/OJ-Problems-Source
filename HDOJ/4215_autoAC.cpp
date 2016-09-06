#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int answer[31]={0,1,1,2,2,4,5,5,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,9,9,9,9,9,9,10};
    int n,c;
    scanf("%d",&c);
    for(int t=1;t<=c;t++)
    {
        scanf("%d",&n);
        if(n<30)
            printf("Case %d: %d\n",t,answer[n]);
        else
            printf("Case %d: 10\n",t);
    }
    return 0;
}
