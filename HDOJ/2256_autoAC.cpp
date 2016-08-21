#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
struct node
{
    int matrix[3][3];
}ma,e;
node operator *(node x,node y)
{
    node temp;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            temp.matrix[i][j]=0;
            for(int k=1;k<=2;k++)
                temp.matrix[i][j]+=(x.matrix[i][k]*y.matrix[k][j])%1024;
            temp.matrix[i][j]%=1024;
        }
    return temp;
}
node operator ^ (node ma,int k)
{
    node ans=e,p=ma;
    if(k==0)
        return e;
    while(k)
    {
        if(k%2==1)
        {
            ans=ans*p;
        }
        k=k/2;
        p=p*p;
    }
    return ans;
}
int main()
{
    int T,n;
    memset(e.matrix,0,sizeof(e.matrix));
    e.matrix[1][1]=e.matrix[2][2]=1;
    scanf("%d",&T);
    ma.matrix[1][1]=5,ma.matrix[1][2]=12,ma.matrix[2][1]=2,ma.matrix[2][2]=5;
    while(T--)
    {
        scanf("%d",&n);
        node temp=ma^(n-1);
        int ans=(2*(temp.matrix[1][1]*5+temp.matrix[1][2]*2)-1)%1024;
        printf("%d\n",ans);
    }
    return 0;
}
