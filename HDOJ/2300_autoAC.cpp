#include<iostream>
#include<cstring>
using namespace std;
int a[110][110];
struct Student
{
    int x;
    int y;
    int m;
}r[110];
int main()
{
    int t,x,y,num,cmd;
    int i,j;
    char str[110];
    int wu1[110],wu2[110],sji;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            memset(a,0,sizeof(a));
            scanf("%d %d",&x,&y);
            scanf("%d %d",&num,&cmd);
            for(i=0;i<num;i++)
            {
                scanf("%d %d %c",&r[i].x,&r[i].y,&str[0]);
                switch(str[0])
                {
                case 'N':r[i].m=0;break;
                case 'W':r[i].m=1;break;
                case 'S':r[i].m=2;break;
                case 'E':r[i].m=3;break;
                }
                a[r[i].x][r[i].y]=i+1;
            }
            for(i=0;i<cmd;i++)
            {
                scanf("%d %c %d",&wu1[i],&str[i],&wu2[i]);
            }
            for(i=0;i<cmd;i++)
            {
                switch(str[i])
                {
                case 'L':r[wu1[i]-1].m=(wu2[i]+r[wu1[i]-1].m)%4;break;
                case 'R':r[wu1[i]-1].m=(r[wu1[i]-1].m-wu2[i]%4+4)%4;break;
                case 'F':
                    a[r[wu1[i]-1].x][r[wu1[i]-1].y]=0;
                    switch (r[wu1[i]-1].m)
                    {
                    case 0:
                        for(j=r[wu1[i]-1].y;j<=r[wu1[i]-1].y+wu2[i];j++)
                        {
                            if(a[r[wu1[i]-1].x][j]!=0)
                            {
                                sji=a[r[wu1[i]-1].x][j];
                                goto leap3;
                            }
                        }
                        r[wu1[i]-1].y+=wu2[i];
                        if(r[wu1[i]-1].y>y)goto leap1;
                        a[r[wu1[i]-1].x][r[wu1[i]-1].y]=wu1[i];
                        break;
                    case 1:
                        for(j=r[wu1[i]-1].x;j>=r[wu1[i]-1].x-wu2[i];j--)
                        {
                            if(j<1)goto leap1;
                            if(a[j][r[wu1[i]-1].y]!=0)
                            {
                                sji=a[j][r[wu1[i]-1].y];
                                goto leap3;
                            }
                        }
                        r[wu1[i]-1].x-=wu2[i];
                        a[r[wu1[i]-1].x][r[wu1[i]-1].y]=wu1[i];
                        break;
                    case 2:
                        for(j=r[wu1[i]-1].y;j>=r[wu1[i]-1].y-wu2[i];j--)
                        {
                            if(j<1)goto leap1;
                            if(a[r[wu1[i]-1].x][j]!=0)
                            {
                                sji=a[r[wu1[i]-1].x][j];
                                goto leap3;
                            }
                        }
                        r[wu1[i]-1].y-=wu2[i];
                        a[r[wu1[i]-1].x][r[wu1[i]-1].y]=wu1[i];
                        break;
                    case 3:
                        for(j=r[wu1[i]-1].x+1;j<=r[wu1[i]-1].x+wu2[i];j++)
                        {
                            if(a[j][r[wu1[i]-1].y]!=0)
                            {
                                sji=a[j][r[wu1[i]-1].y];
                                goto leap3;
                            }
                        }
                        r[wu1[i]-1].x+=wu2[i];
                        if(r[wu1[i]-1].x>x)goto leap1;
                        a[r[wu1[i]-1].x][r[wu1[i]-1].y]=wu1[i];
                        break;
                    }
                }
            }
            printf("OK\n");continue;
leap1:{printf("Robot %d crashes into the wall\n",wu1[i]);continue;}      
leap3:printf("Robot %d crashes into robot %d\n",wu1[i],sji);
        }
    }
    return 0;
}
