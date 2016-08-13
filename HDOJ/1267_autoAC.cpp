#include<cstdio>
#include<cstring>
__int64 d[1010][1010];
int fun()
{
    int i,j;
    memset(d,0,sizeof(d));
    for(i=1; i<=20; i++)
    {  
        d[i][1]=i;
    }
    for(i=2; i<=20; i++)
    {
        for(j=2; j<=20; j++)
        {
            if(i>=j)        
            d[i][j] = d[i][j-1]+d[i-1][j];
        }
    }
}
int main()
{
    int m,n;
    fun();
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        printf("%I64d\n",d[m][n]);
    }
    return 0;
}
