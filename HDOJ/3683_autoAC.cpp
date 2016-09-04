#include<stdio.h>
#include<string.h>
int a[20][20],nx,ny;
char b[][10]={"white","black"};
int judge(int now)
{
    int i,j;
    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
        {
            if(i<11&&j<11)
                if(a[i][j]==now&&a[i+1][j+1]==now
                &&a[i+2][j+2]==now&&a[i+3][j+3]==now
                &&a[i+4][j+4]==now)
                    return 1;
            if(i<11)
                if(a[i][j]==now&&a[i+1][j]==now
                &&a[i+2][j]==now&&a[i+3][j]==now
                &&a[i+4][j]==now)
                    return 1;
            if(j<11)
                if(a[i][j]==now&&a[i][j+1]==now
                &&a[i][j+2]==now&&a[i][j+3]==now
                &&a[i][j+4]==now)
                    return 1;
            if(i>3&&j<11)
                if(a[i][j]==now&&a[i-1][j+1]==now
                &&a[i-2][j+2]==now&&a[i-3][j+3]==now
                &&a[i-4][j+4]==now)
                    return 1;
        }
    return 0;
}
int judge1(int now)
{
    int i,j,num=0,ok;
    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
            if(a[i][j]<0)
            {
                a[i][j]=now;
                ok=judge(now);
                a[i][j]=-1;
                if(ok)
                {
                    nx=i;
                    ny=j;
                    return 1;
                }
            }
    return 0;
}
int judge2(int now)
{
    int i,j,num=0,ok;
    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
            if(a[i][j]<0)
            {
                a[i][j]=!now;
                ok=judge(!now);
                a[i][j]=-1;
                if(ok)
                {
                    num++;
                    nx=i;
                    ny=j;
                    if(num==2)
                        return num;
                }
            }
    return num;
}
int judge3(int now)
{
    int i,j,ok;
    if(judge2(now)==1)
    {
        i=nx;
        j=ny;
        a[i][j]=now;
        if(judge2(!now)==2)
        {
            nx=i;
            ny=j;
            return 1;
        }
        else
            return 0;
    }
    for(i=0;i<15;i++)
        for(j=0;j<15;j++)
            if(a[i][j]<0)
            {
                a[i][j]=now;
                ok=judge2(!now);
                a[i][j]=-1;
                if(ok==2)
                {
                    nx=i;
                    ny=j;
                    return 1;
                }
            }    
    return 0;
}
int main()
{
    int i,j,k,n,x,y,now;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        memset(a,-1,sizeof(a));
        now=1;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&k);
            if(k)
                now--;
            else
                now++;
            a[x][y]=k;
        }
        if(now!=0&&now!=1)
        {
            printf("Invalid.\n");
            continue;
        }
        if(n<=5)
        {
            printf("Cannot win in 3 moves.\n");
            continue;
        }
        if(judge1(now))
            printf("Place %s at (%d,%d) to win in 1 move.\n",b[now],nx,ny);
        else if(judge2(now)==2)
            printf("Lose in 2 moves.\n");
        else if(judge3(now))
            printf("Place %s at (%d,%d) to win in 3 moves.\n",b[now],nx,ny);
        else
            printf("Cannot win in 3 moves.\n");
    }
    return 0;    
}
