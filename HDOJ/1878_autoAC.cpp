#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;
int a[1024],b[1024];
int main()
{
    int n,i,j,m,ji1,ji2,ji,sji;
    while(~scanf("%d",&n))
    {
        if(!n)break;
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        {
            a[i]=i;
        }
        memset(b,0,sizeof(b));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&ji1,&ji2);
            b[ji1]++;
            b[ji2]++;
            while(a[ji1] != ji1)
            {
                ji1=a[ji1];
            }
            while(a[ji2] != ji2)
            {
                ji2=a[ji2];
            }
            if(ji1>ji2)
            {
                ji=ji1;
                ji1=ji2;
                ji2=ji;
            }
            a[ji2]=ji1;
        }
        sji=0;
        for(i=2;i<=n;i++)
        {
            if(a[i] == i)
            {
                sji=1;
                break;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(b[i]%2)
            {
                sji=1;
                break;
            }
        }
        if(sji)
        {
            printf("0\n");
        }
        else 
        {
            printf("1\n");
        }
    }
    return 0;
}
