#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int dir[7][4][4][2]={
{{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}},
{{{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {-1, 2}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
{{{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}},
{{{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
{{{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {0, 1}, {-1, 1}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 0}, {1, 0}, {0, 1}, {-1, 1}}}, 
{{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, {{0, 0}, {0, 1}, {0, 2}, {-1, 1}}, {{0, 0}, {0, 1}, {-1, 1}, {1, 1}}},
{{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}}, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}}
};  
int map[30][15]; 
int state[30][15];  
int sum[30];  
int safe(int x, int y)
{
    if(x>0&&y>0&&y<=10&&map[x][y]==0)  return 1;
    return 0;
}
int main()
{
    int m, id, de, pos, i, j, k, x1, y1, x2, y2, x3, y3, x4, y4, jj;
    int frx1, frx2, frx3, frx4, fry1, fry2, fry3, fry4;
    while(scanf("%d", &m)!=EOF)
    {
        memset(map, 0, sizeof(map));
        memset(sum, 0, sizeof(sum));
        memset(state, 0, sizeof(state)); 
        int flag=0;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d", &id, &de, &pos);
            if(flag==1) continue; 
            id--; de/=90;
            for(j=23; j>0; j--)  
            {
                x1=j+dir[id][de][0][0], y1=pos+dir[id][de][0][1];
                x2=j+dir[id][de][1][0], y2=pos+dir[id][de][1][1];
                x3=j+dir[id][de][2][0], y3=pos+dir[id][de][2][1];
                x4=j+dir[id][de][3][0], y4=pos+dir[id][de][3][1];
                if(safe(x1, y1)&&safe(x2, y2)&&safe(x3, y3)&&safe(x4, y4))
                {
                    frx1=x1, frx2=x2, frx3=x3, frx4=x4;
                    fry1=y1, fry2=y2, fry3=y3, fry4=y4;
                }  
                else break;
            }
            if(j==23) flag=1;
            if(flag) continue;
            map[frx1][fry1]=1, map[frx2][fry2]=1, map[frx3][fry3]=1, map[frx4][fry4]=1;
            sum[frx1]++, sum[frx2]++, sum[frx3]++, sum[frx4]++; 
            for(j=1; j<=20; j++)
            {
                while(sum[j]==10) 
                {
                    for(jj=j+1; jj<25; jj++)
                    {
                        for(k=1; k<=10; k++)
                            map[jj-1][k]=map[jj][k];
                        sum[jj-1]=sum[jj];
                    }
                }
            }
            for(j=21; j<25; j++)
                if(sum[j]) flag=1; 
            if(flag!=1) 
            {
                for(j=0; j<=20; j++)
                    for(jj=0; jj<=10; jj++)
                        state[j][jj]=map[j][jj];
            }
        }
        printf("+--------------------+\n");
        for(i=20; i>=1; i--)
        {
            printf("|");
            for(j=1; j<=10; j++)
            {
                if(state[i][j]==1) printf("[]");
                else printf("..");
            }
            printf("|\n");
        }
        printf("+--------------------+\n\n");
    }
    return 0;   
}
