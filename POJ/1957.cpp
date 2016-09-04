#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct Point2D
{
    int x,y;
};
int nextvec[6][2]=
{
    {
        1,0
    },
    {
        1,1
    },
    {
        0,1
    },
    {
        -1,0
    },
    {
        -1,-1
    },
    {
        0,-1
    }
};

char stra[1024];
char strb[1024];
char buff[1024];
Point2D pa[2000];
Point2D pb[2000];

bool cmp(const Point2D& a,const Point2D& b)
{
    if(a.x==b.x)
    {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main()
{
    int N;
    scanf("%d%*c",&N);
    while(N--)
    {
        memset(pa,0,sizeof(pa));
        memset(pb,0,sizeof(pb));
        gets(stra);
        gets(strb);
        gets(buff);
        int lena=strlen(stra);
        int lenb=strlen(strb);
        if(lena==0&&lenb==0)
        {
            printf("true\n");
            continue;
        }
        else if(lena!=lenb)
        {
            printf("false\n");
            continue;
        }
        int x=0;
        int y=0;
        for(int i=0;i<lena;i++)
        {
            int dir=(stra[i]-'a');
            x+=nextvec[dir][0];
            y+=nextvec[dir][1];
            pa[i].x=x;
            pa[i].y=y;
        }
        pa[lena].x=0;
        pa[lena].y=0;
        sort(pa,pa+lena+1,cmp);

        int flag=0;
        for(int dirCLT=0;dirCLT<6;dirCLT++)
        {
            for(int startID=0;startID<=lena;startID++)
            {
                x=pa[startID].x;
                y=pa[startID].y;
                for(int i=0;i<lenb;i++)
                {
                    int dir=(strb[i]-'a'+dirCLT)%6;
                    x+=nextvec[dir][0];
                    y+=nextvec[dir][1];
                    pb[i].x=x;
                    pb[i].y=y;
                }
                pb[lenb].x=pa[startID].x;
                pb[lenb].y=pa[startID].y;
                sort(pb,pb+lenb+1,cmp);
                int tflag=0;
                for(int i=0;i<=lena;i++)
                {
                    if(pa[i].x!=pb[i].x||pa[i].y!=pb[i].y)
                    {
                        tflag=1;
                        break;
                    }
                }
                if(tflag==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}
