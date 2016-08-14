#include<stdio.h>
int a[10][2];
int s,min;
int abs(int i,int j)
{
    i-=j;
    if(i>0) return i;
    else return -i;
}
void DFS()
{
    int i,j,flog=0;
    int i0,i1,j0,j1;
    for(i=0;i<10;i++)
    {
        if(a[i][0]!=-1&&a[i][0]!=10)
        {
            flog=1;
            for(j=0;j<10;j++)
            {
                if(a[j][1]==a[i][0]&&s+abs(i,j)<min)
                {
                    i0=a[i][0];
                    i1=a[i][1];
                    j0=a[j][0];
                    j1=a[j][1];
                    a[i][0]=-1;
                    a[j][1]=a[i][1];
                    s+=abs(i,j);
                    DFS();
                    s-=abs(i,j);
                    a[i][0]=i0;
                    a[i][1]=i1;
                    a[j][0]=j0;
                    a[j][1]=j1;
                }
            }
        }
    }
    if(!flog)
    {
        if(min>s) min=s;
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&a[i][0]);
            a[i][1]=a[i][0]-1;
        }
        min=99999;
        s=0;
        DFS();
        printf("%d\n",min);
    }
    return 0;
}
