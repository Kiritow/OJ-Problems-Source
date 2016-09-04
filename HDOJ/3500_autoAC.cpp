#include<cstdio>
#include<cstring>
int t,n=7,m=8,num,dir[4][2]={-1,0,0,-1,0,1,1,0};
int path[15],f[15];
char map[15][15],p[]="ULRD",pathc[15];
int ok(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m)
        return 0;
    return 1;
}
int dfs(int pos)
{
    if(pos==num-1)
        return 1;
    int i,j,k,x,y,tx[15],ty[15];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(map[i][j]=='O')
                for(k=0;k<4;k++)
                {
                    int flag=0,cnt=0;
                    x=i+dir[k][0];
                    y=j+dir[k][1];
                    if(map[x][y]=='O')
                        continue;
                    while(ok(x,y))
                    {
                        if(map[x][y]=='O')
                        {
                            flag=1;
                            tx[cnt]=x;
                            ty[cnt++]=y;
                        }
                        x+=dir[k][0];
                        y+=dir[k][1];
                    }
                    if(flag)
                    {
                        map[i][j]='X';
                        for(int ii=0;ii<cnt;ii++)
                        {
                            map[tx[ii]][ty[ii]]='X';
                            map[tx[ii]-dir[k][0]][ty[ii]-dir[k][1]]='O';
                        }
                        path[pos]=i*m+j;
                        pathc[pos]=p[k];
                        if(dfs(pos+1))
                            return 1;
                        map[i][j]='O';
                        x=i+dir[k][0];
                        y=j+dir[k][1];
                        while(ok(x,y))
                        {
                            if(map[x][y]=='O')
                                map[x][y]='X';
                            x+=dir[k][0];
                            y+=dir[k][1];
                        }
                        for(int ii=0;ii<cnt;ii++)
                            map[tx[ii]][ty[ii]]='O';
                    }
                }
    return 0;
}
int main()
{
    while(~scanf("%s",map[0]))
    {
        int i,j;
        num=0;
        memset(f,0,sizeof(f));
        for(i=1;i<n;i++)
            scanf("%s",map[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(map[i][j]=='O')
                    num++;
        dfs(0);
        if(t)
            puts("");
        printf("CASE #%d:\n",++t);
        for(i=0;i<num-1;i++)
            printf("%d %d %c\n",path[i]/m,path[i]%m,pathc[i]);
    }
}
