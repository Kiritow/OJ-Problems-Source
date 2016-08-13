#include<stdio.h>
#include<string.h>
char a[10009],b[10009];
int c[10009][10009];
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
    }
int main()
{
    int i,j,x,y;
    while(scanf("%s %s",a,b)!=EOF)
    {
        x=strlen(a);
        y=strlen(b);
        for(i=0;i<=x;i++)
            c[0][i]=0;
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(a[i]==b[j])
                    c[i+1][j+1]=c[i][j]+1;
                else
                    c[i+1][j+1]=max(c[i][j+1],c[i+1][j]);
                }
        }
        printf("%d\n",c[x][y]);
    }
    return 0;
}
