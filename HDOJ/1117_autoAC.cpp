#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<math.h>
#include<string>
using namespace std;
typedef long long ll;
using namespace std;
#define INF 10000000
int a[54][2];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        memset(a,0,sizeof(a));
        if(n==1)
        {
            printf("Printing order for %d pages:\n", n);
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }
        int i,j,k = n/4;
        if(n%4!=0 ) k++;
        for(i=1;i<=2*k;i++)
            a[i][0] =i;
        for(i=2*k,j=i+1;i>=1;i--,j++)
        {
            if(j<=n)
                a[i][1]=j;
        }
        printf("Printing order for %d pages:\n",n);
        char s[2][10]={"front","back "};
        char *p;
        for(i=1;i<=2*k;i++)
        {
            if(a[i][0]==0 && a[i][0]==0 )continue;
            j=i/2;
            if( i&1 )
            {
                p=s[0];
                j++;
            }
            else 
                p=s[1];
            printf("Sheet %d, %s:",j,p);
            if( i&1 )
                swap(a[i][0],a[i][1]);
            for(int m=0;m<2;m++)
            {
                if(a[i][m] ) printf(" %d",a[i][m]);
                else printf(" Blank");
                if(!m) putchar(',');
            }
            printf("\n");
        }
    }
}
