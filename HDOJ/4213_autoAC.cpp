#include<cstdio>
#include<cstring>
#define maxn 20
char map[maxn][maxn];
bool aim[maxn][maxn];
bool complete;
int dirx[4]={-1,1,0,0},diry[4]={0,0,-1,1};
int startx,starty;
int n,m;
void run(char *s)
{
    for(;*s;s++)
    {
        int dir;
        if(*s=='U') dir=0;
        else if(*s=='D') dir=1;
        else if(*s=='L') dir=2;
        else dir=3;
        int tx=startx+dirx[dir],ty=starty+diry[dir];
        if(map[tx][ty]!='#')
        {
            int nextx=tx+dirx[dir],nexty=ty+diry[dir];
            bool flag=false;
            if(map[tx][ty]=='b'&&map[nextx][nexty]!='b'&&map[nextx][nexty]!='#')
            {
                map[tx][ty]='w';
                map[nextx][nexty]='b';
                map[startx][starty]='.';
                startx=tx,starty=ty;
                flag=true;
            }
            else if(map[tx][ty]=='.'||map[tx][ty]=='+')
            {
                map[tx][ty]='w';
                map[startx][starty]='.';
                startx=tx,starty=ty;
            }
            if(flag)
            {
                int t1=0,t2=0;
                for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                    {
                        if(aim[i][j])
                        {
                            t1++;
                            if(map[i][j]=='b')
                                t2++;
                        }
                    }
                if(t1==t2)
                {
                    complete=true;
                    return;
                }
            }
        }
    }
}
int main()
{
    int cas=1;
    while(scanf("%d %d",&n,&m),n||m)
    {
        int i,k;
        complete=false;
        for(i=0;i<n;i++)
            for(k=0;k<m;k++)
            {
                scanf(" %c",&map[i][k]);
                aim[i][k]=false;
                if(map[i][k]=='+'||map[i][k]=='B'||map[i][k]=='W')
                {
                    aim[i][k]=true;
                    if(map[i][k]!='+')
                        map[i][k]+=32;
                }
                if(map[i][k]=='w')
                    startx=i,starty=k;
            }
        char str[100];
        scanf("%s",str);
        run(str);
        printf("Game %d: ",cas++);
        puts(complete?"complete":"incomplete");
        for(i=0;i<n;i++)
        {
            for(k=0;k<m;k++)
            {
                if(aim[i][k])
                {
                    if(map[i][k]=='b'||map[i][k]=='w')
                        map[i][k]-=32;
                    else
                        map[i][k]='+';
                }
                printf("%c",map[i][k]);
            }
            printf("\n");
        }
    }
    return 0;
}
