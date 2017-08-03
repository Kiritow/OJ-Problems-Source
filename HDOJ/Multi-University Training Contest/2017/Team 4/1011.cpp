#include <cstdio>
#include <cstdlib>
#include <cstring>

const char* lb[10]=
{
    ".XX.X..XX..X....X..XX..X.XX.", //0
    ".......X...X.......X...X....", // 1
    ".XX....X...X.XX.X...X....XX.",// 2
    ".XX....X...X.XX....X...X.XX.",//3
    "....X..XX..X.XX....X...X....",//4
    ".XX.X...X....XX....X...X.XX.",//5
    ".XX.X...X....XX.X..XX..X.XX.",//6
    ".XX....X...X.......X...X....",//7
    ".XX.X..XX..X.XX.X..XX..X.XX.",//8
    ".XX.X..XX..X.XX....X...X.XX."//9
};

char buff[8][32];

char num[4][32];
int x[4];

char xbuf[8];

int main()
{
    /*
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<7;j++)
        {
            strncpy(xbuf,lb[i]+4*j,4);
            printf("%s\n",xbuf);
        }
        printf("\n");
    }
    //*/

    int t;
    scanf("%d%*c",&t);
    for(int i=0;i<t;++i)
    {
        for(int j=0;j<7;j++)
        {
            gets(buff[j]);
        }

        memset(num,0,4*32);
        /// ? _:_ _
        strncpy(num[0],buff[0],4);
        for(int j=1;j<8;j++)
        strncat(num[0],buff[j],4);

        strncpy(num[1],buff[0]+5,4);
        for(int j=1;j<8;j++)
        strncat(num[1],buff[j]+5,4);

        strncpy(num[2],buff[0]+12,4);
        for(int j=1;j<8;j++)
        strncat(num[2],buff[j]+12,4);

        strncpy(num[3],buff[0]+17,4);
        for(int j=1;j<8;j++)
        strncat(num[3],buff[j]+17,4);

        for(int j=0;j<4;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(strcmp(num[j],lb[k])==0)
                {
                    x[j]=k;
                    break;
                }
            }
        }

        printf("%d%d:%d%d\n",x[0],x[1],x[2],x[3]);

    }

    return 0;
}
