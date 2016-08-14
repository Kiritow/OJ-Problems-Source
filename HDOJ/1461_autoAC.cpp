#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 11
using namespace std;
struct Node
{
    char map[10][N];
    int flag;
};
char endstate[10][N];
Node t1,t2,t3;
int n,i,j,k;
bool isEnd(Node tt)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(tt.map[i][j]!=endstate[i][j])
                return false;
        }
    }
    return true;
}
void rt90()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t1.map[j][n-i-1]=t2.map[i][j];
        }
    }
}
void rt180()
{
    rt90();
    t3=t2;
    t2=t1;
    rt90();
    t2=t3;
}
void rt270()
{
    rt90();
    t3=t2;
    t2=t1;
    rt90();
    t2=t1;
    rt90();
    t2=t3;
}
void reflect()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t1.map[n-i-1][j]=t2.map[i][j];
        }
    }
}
void BFS()
{
    queue<Node> qu;
    if(isEnd(t1))
    {
        printf("Preserved\n");
        return;
    }
    t1.flag=0;
    qu.push(t1);
    while(!qu.empty())
    {
        t2=qu.front();
        qu.pop();
        if(t2.flag==0)
        {
            t1.flag=1;
            rt90();
            if(isEnd(t1))
            {
                printf("Rotated through 90 degrees\n");
                return;
            }
            rt180();
            if(isEnd(t1))
            {
                printf("Rotated through 180 degrees\n");
                return;
            }
            rt270();
            if(isEnd(t1))
            {
                printf("Rotated through 270 degrees\n");
                return;
            }
            reflect();
            if(isEnd(t1))
            {
                printf("Reflected\n");
                return;
            }
            qu.push(t1);
        }
        else if(t2.flag==1)
        {
            rt90();
            if(isEnd(t1))
            {
                printf("Reflected and rotated through 90 degrees\n");
                return;
            }
            rt180();
            if(isEnd(t1))
            {
                printf("Reflected and rotated through 180 degrees\n");
                return;
            }
            rt270();
            if(isEnd(t1))
            {
                printf("Reflected and rotated through 270 degrees\n");
                return;
            }
            printf("Improper\n");
        }
    }
}
int main()
{
     while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s%s",t1.map[i],endstate[i]);
        }
        BFS();
    }
}
