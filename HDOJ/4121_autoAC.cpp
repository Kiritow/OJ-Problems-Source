#include <iostream>
#include <algorithm>
using namespace std ;
int abs(int x)
{
    return x>0?x:-x ;
}
char map[11][11] ;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}} ;
int RGX,RGY ;
int xx,yy ;
int ok(int x,int y)
{
    if(y!=RGY)
        return 1 ;
    for(int i=x+1 ;i<RGX ;i++)
        if(map[i][y]!='0')
            return 1 ;
    return 0 ;
}
int cha(int x,int y)
{
    if(x!=xx && y!=yy)
        return 0 ;
    if(x==xx)
    {
        int minn=min(y,yy) ;
        int maxn=max(y,yy) ;
        for(int i=minn+1 ;i<maxn ;i++)
            if(map[x][i]!='0')
                return 0 ;
    }
    if(y==yy)
    {
        int minn=min(x,xx) ;
        int maxn=max(x,xx) ;
        for(int i=minn+1 ;i<maxn ;i++)
            if(map[i][y]!='0')
                return 0 ;
    }
    return 1 ;
}
int hor(int x,int y)
{
    if((abs(x-xx)==1 && abs(y-yy)==2) || (abs(x-xx)==2 &&abs(y-yy)==1))
    {
        if(xx-x==-2)
        {
            if(map[x-1][y]!='0')
                return 0 ;
        }
        if(xx-x==2)
        {
            if(map[x+1][y]!='0')
                return 0 ;
        }
        if(yy-y==-2)
        {
            if(map[x][y-1]!='0')
                return 0 ;
        }
        if(yy-y==2)
        {
            if(map[x][y+1]!='0')
                return 0 ;
        }
        return 1 ;
    }
    return 0 ;
}
int can(int x,int y)
{
    if(x!=xx && y!=yy)
        return 0 ;
    int flag=0 ;
    if(x==xx)
    {
        int minn=min(y,yy) ;
        int maxn=max(y,yy) ;
        for(int i=minn+1 ;i<maxn ;i++)
            if(map[x][i]!='0')
                flag++ ;
    }
    if(y==yy)
    {
        int minn=min(x,xx) ;
        int maxn=max(x,xx) ;
        for(int i=minn+1 ;i<maxn ;i++)
            if(map[i][y]!='0')
                flag++ ;
    }
    if(flag==1)
        return 1 ;
    return 0 ;
}
int main()
{
    int n ;
    int x,y ;
    while(~scanf("%d%d%d%*c",&n,&x,&y))
    {
        if(n==0 && x==0 && y==0)
            break ;
        for(int i=0 ;i<11 ;i++)
            for(int j=0 ;j<11 ;j++)
                map[i][j]='0' ;
        for(int i=0 ;i<n ;i++)
        {
            char chr ;
            int a,b ;
            cin >> chr >> a >> b ;
            map[a][b]=chr ;
            if(chr=='G')
            {
                RGX=a ;RGY=b ;
            }
        }
        int flag ;
        for(int i=0 ;i<4 ;i++)
        {
            flag=0 ;
            xx=x+dir[i][0] ;
            yy=y+dir[i][1] ;
            if(xx<1 || xx>3){flag=1 ;continue ;}
            if(yy<4 || yy>6){flag=1 ;continue ;}
            if(!ok(xx,yy)){flag=1 ;continue ;}
            char t=map[xx][yy] ;
            map[xx][yy]='0' ;
            for(int j=1 ;j<=10 ;j++)
            {
                for(int k=1 ;k<=9 ;k++)
                {
                    if(map[j][k]=='R')
                    {
                        if(cha(j,k))
                            flag=1 ;    
                    }
                    if(map[j][k]=='H')
                    {
                        if(hor(j,k))
                            flag=1 ;
                    }
                    if(map[j][k]=='C')
                    {
                        if(can(j,k))
                            flag=1 ;
                    }
                }
            }
            if(!flag)
                break ;
            map[xx][yy]=t ;
         }
        if(flag)
            puts("YES") ;
        else
            puts("NO") ;
    }
    return 0 ;
}
