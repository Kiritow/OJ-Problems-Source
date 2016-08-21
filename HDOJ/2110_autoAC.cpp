#include <stdio.h>
#include <memory.h>
using namespace std;
int num[100],price[100],c1[10050],c2[10050];
int main(){
    int n,sum;
    int m;
    while(~scanf("%d",&n)&&n)
    {
        sum=0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
    for(int i=1;i<=n;i++)
    {
            scanf("%d%d",&price[i],&num[i]);
            sum+=price[i]*num[i];
    }
    m=sum/3;
    if(sum%3!=0)
    {
        printf("sorry\n");
        continue;
    }
    for(int i=0;i<=num[1]*price[1]&&i<=m;i+=price[1])
        c1[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=num[i]*price[i]&&k+j<=m;k+=price[i])
                c2[k+j]+=c1[j]%10000;
        }
        for(int j=0;j<=m;j++)
        {
            c1[j]=c2[j]%10000;
            c2[j]=0;
        }
    }
    if(c1[m]==0)
        printf("sorry\n");
    else
       printf("%d\n",c1[m]);
    }
    return 0;
}
