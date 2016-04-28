#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct
{
    char data;
    int vis;
}pack;
 
pack screen[102][102];
 
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
 
void deal(int incmax)
{
    memset(screen,0,sizeof(pack)*102*102);
    char letter='A';
    int cx,cy,towards,i;
    int times=incmax*incmax;
    for(i=0;i<incmax+2;i++)
    {
        screen[0][i].vis=1;
        screen[i][0].vis=1;
        screen[incmax+1][i].vis=1;
        screen[i][incmax+1].vis=1;
    }
    for(cx=1,cy=1,towards=RIGHT;times>0;times--)
    {
        screen[cx][cy].data=letter++;
        screen[cx][cy].vis=1;
        (letter>'Z')?(letter='A'):(NULL);
        switch(towards)
        {
        case RIGHT:
            {
                if(screen[cx][cy+1].vis==1)
                {
                    towards++;
                    cx++;
                }
                else
                {
                    cy++;
                }
                break;
            }
        case DOWN:
            {
                if(screen[cx+1][cy].vis==1)
                {
                    towards++;
                    cy--;
                }
                else
                {
                    cx++;
                }
                break;
            }
        case LEFT:
            {
                if(screen[cx][cy-1].vis==1)
                {
                    towards++;
                    cx--;
                }
                else
                {
                    cy--;
                }
                break;
            }
        case UP:
            {
                if(screen[cx-1][cy].vis==1)
                {
                    towards=0;
                    cy++;
                }
                else
                {
                    cx--;
                }
                break;
            }
        }
    }
}
 
void print_map(int incmax)
{
    int x,y;
    for(x=1;x<incmax+1;x++)
    {
        for(y=1;y<incmax;y++)
        {
            printf("%c ",screen[x][y].data);
        }
        printf("%c\n",screen[x][y].data);
    }
}
 
int main()
{
    int all,inc;
    scanf("%d",&all);
    for(;all>0;all--)
    {
        scanf("%d",&inc);
        deal(inc);
        print_map(inc);
    }
    return 0;
}
