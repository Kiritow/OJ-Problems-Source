#include<stdio.h>
#include<string.h>
int map[110][110],last_y[110],hav[110],N,M;
int findmax(int m);
int main()
{
    int i,j,a,b,Sum;
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(last_y,-1,sizeof(last_y));
        Sum=0;
        for(i=1;i<=M;i++)
        {
            scanf("%d",&a);
            for(j=0;j<a;j++)
            {
                scanf("%d",&b);
                map[b][i]=1;
            }
        }    
        for(i=1;i<=N;i++)
        {
            if(findmax(i))
            {
                memset(hav,0,sizeof(hav));
                Sum++;
            }
        }
        printf("%d\n",Sum);
    }
    return 0;
} 
int findmax(int m)
{
    int i;
    for(i=1;i<=M;i++)
    {
        if(!hav[i]&&map[m][i])
        {
            hav[i]=1;
            if(last_y[i]==-1||findmax(last_y[i]))
            {
                last_y[i]=m;
                return 1;
            }
        }
    }
    return 0;
}
