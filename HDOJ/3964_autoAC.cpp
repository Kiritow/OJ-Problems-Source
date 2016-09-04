#include<iostream>
using namespace std;
bool map[15][15];
bool mark[15];
int val[15];
int n;
void dfs(int index,int num,int j)
{
    int i;
    if(num>1&&map[index][j])
    {
        for(int k=0;k<num;k++)
            printf("%d",val[k]);
        printf("\n");
    }
    for(i=j+1;i<n;i++)
    {
        if(mark[i]==0&&map[index][i])
        {
            mark[i]=1;
            val[num]=i;
            dfs(i,num+1,j);
            mark[i]=0;
        }
    }
}
int main()
{
    int i,j,a;
    //freopen("a.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a);
                if(a==0)map[i][j]=0;
                else map[i][j]=1;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                mark[j]=0;
            mark[i]=1;
            val[0]=i;
            dfs(i,1,i);
        }
        printf("\n");
    }
    return 0;
}
