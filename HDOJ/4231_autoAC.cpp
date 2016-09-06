#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define M 105
struct info
{
    char side;
    int sou;
    int v;
};
info fold[30];
int w,h,n;
int we,he;
int x,y;
void getdata(void);
int cal(int ws,int hs,int px,int py,int step);
int main()
{
    while (scanf("%d%d%d",&w,&h,&n),w+h+n)
    {
        getdata();
        printf("%d\n",cal(we,he,x,y,n));
    }
    return 0;
}
void getdata(void)
{
    int i;
    we=w;
    he=h;
    for (i=1;i<=n;i++)
    {
        scanf(" %c%d",&fold[i].side,&fold[i].v);
        switch(fold[i].side)
        {
        case 'T':
        case 'B':
            fold[i].sou=he;
            if (he-fold[i].v>=fold[i].v)
                he-=fold[i].v;
            else
            {
                he=fold[i].v;
                /*fold[i].v=he-fold[i].v;
                fold[i].side=fold[i].side=='B'?'T':'B';
                he-=fold[i].v;*/
            }
            break;
        case 'L':
        case 'R':
            fold[i].sou=we;
            if (we-fold[i].v>=fold[i].v)
                we-=fold[i].v;
            else
            {
                we=fold[i].v;
                /*fold[i].v=we-fold[i].v;
                fold[i].side=fold[i].side=='R'?'L':'R';
                we-=fold[i].v;*/
            }
            break;
        }
    }
    scanf("%d%d",&x,&y);
}
int cal(int ws,int hs,int px,int py,int step)
{
    int ans=0;
    int line;
    if (step<1)
        return 1;
    else
    {
        switch (fold[step].side)
        {
        case 'T':
            if (hs>fold[step].v)
            {
                if (py<hs-fold[step].v)
                {
                    ans+=cal(ws,hs+fold[step].v,px,py,step-1);
                }
                else
                {
                    ans+=cal(ws,hs+fold[step].v,px,py,step-1);
                    ans+=cal(ws,hs+fold[step].v,px,hs+(hs-py),step-1);
                }
            }
            else
            {
                line=2*fold[step].v-fold[step].sou;
                if (py>line)
                {
                    ans+=cal(ws,fold[step].sou,px,hs+(hs-py)-line,step-1);
                    ans+=cal(ws,fold[step].sou,px,py-line,step-1);
                }
                else
                {
                    ans+=cal(ws,fold[step].sou,px,hs+(hs-py)-line,step-1);
                }
            }
            break;
        case 'B':
            if (hs>fold[step].v)
            {
                if (py>fold[step].v)
                {
                    ans+=cal(ws,hs+fold[step].v,px,py+fold[step].v,step-1);
                }
                else
                {
                    ans+=cal(ws,hs+fold[step].v,px,py+fold[step].v,step-1);
                    ans+=cal(ws,hs+fold[step].v,px,fold[step].v-py,step-1);
                }
            }
            else
            {
                line=2*fold[step].v-fold[step].sou;
                if (py<hs-line)
                {
                    ans+=cal(ws,fold[step].sou,px,py+fold[step].v,step-1);
                    ans+=cal(ws,fold[step].sou,px,fold[step].v-py,step-1);
                }
                else
                {
                    ans+=cal(ws,fold[step].sou,px,fold[step].v-py,step-1);
                }
            }
            break;
        case 'L':
            if (ws>fold[step].v)
            {
                if (px>fold[step].v)
                {
                    ans+=cal(ws+fold[step].v,hs,px+fold[step].v,py,step-1);
                }
                else
                {
                    ans+=cal(ws+fold[step].v,hs,px+fold[step].v,py,step-1);
                    ans+=cal(ws+fold[step].v,hs,fold[step].v-px,py,step-1);
                }
            }
            else
            {
                line=2*fold[step].v-fold[step].sou;
                if (px<ws-line)
                {
                    ans+=cal(fold[step].sou,hs,px+fold[step].v,py,step-1);
                    ans+=cal(fold[step].sou,hs,fold[step].v-px,py,step-1);
                }
                else
                {
                    ans+=cal(fold[step].sou,hs,fold[step].v-px,py,step-1);
                }
            }
            break;
        case 'R':
            if (ws>fold[step].v)
            {
                if (px<ws-fold[step].v)
                {
                    ans+=cal(fold[step].sou,hs,px,py,step-1);
                }
                else
                {
                    ans+=cal(fold[step].sou,hs,px,py,step-1);
                    ans+=cal(fold[step].sou,hs,ws+(ws-px),py,step-1);
                }
            }
            else
            {
                line=2*fold[step].v-fold[step].sou;
                if (px>line)
                {
                    ans+=cal(fold[step].sou,hs,px-line,py,step-1);
                    ans+=cal(fold[step].sou,hs,ws+(ws-px)-line,py,step-1);
                }
                else
                {
                    ans+=cal(fold[step].sou,hs,ws+(ws-px)-line,py,step-1);
                }
            }
            break;
        }
    }
    return ans;
}
