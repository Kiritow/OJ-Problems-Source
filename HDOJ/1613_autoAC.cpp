#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=6;
const int inf=1<<29;
int sum[maxn],val[maxn][maxn];
char str[maxn][10]={"BCG","BGC","CBG","CGB","GBC","GCB"};
int main()
{
    while(scanf("%d%d%d",&val[0][0],&val[0][1],&val[0][2])!=EOF)
    {
    for(int i=1;i<=2;i++)
        for(int j=0;j<3;j++)
        scanf("%d",&val[i][j]);
    sum[0]=val[1][0]+val[2][0]+val[0][2]+val[2][2]+val[0][1]+val[1][1];
    sum[1]=val[1][0]+val[2][0]+val[0][1]+val[2][1]+val[0][2]+val[1][2];
    sum[2]=val[1][2]+val[2][2]+val[0][0]+val[2][0]+val[0][1]+val[1][1];
    sum[3]=val[1][2]+val[2][2]+val[0][1]+val[2][1]+val[0][0]+val[1][0];
    sum[4]=val[1][1]+val[2][1]+val[0][0]+val[2][0]+val[0][2]+val[1][2];
    sum[5]=val[1][1]+val[2][1]+val[0][2]+val[2][2]+val[0][0]+val[1][0];
    int ans=inf,pos;
    for(int i=0;i<maxn;i++)
        if(ans>sum[i])
        {
        ans=sum[i];
        pos=i;
        }
    printf("%s %d\n",str[pos],ans);
    }
    return 0;
}
