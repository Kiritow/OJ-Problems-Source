#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[20];
int map[15],r,step;
int check(int a[])
{
    int i;
    for(i = 1; i<=9; i++)
        if(a[i] != i)
            return 0;
    return 1;
}
void swap(int s[],int a,int b,int c,int d)
{
    int t=s[a];
    s[a]=s[b],s[b]=s[c],s[c]=s[d];
    s[d]=t;
}
void work(int a[],int id)
{
    if(id==1) swap(a,1,2,5,4);
    if(id==2) swap(a,2,3,6,5);
    if(id==3) swap(a,4,5,8,7);
    if(id==4) swap(a,5,6,9,8);
    if(id==5) swap(a,8,9,6,5);
    if(id==6) swap(a,7,8,5,4);
    if(id==7) swap(a,5,6,3,2);
    if(id==8) swap(a,4,5,2,1);
}
int dfs(int a[],int deep)
{
    if(check(a))
        return 1;
    if(deep>=step)
        return 0;
    for(int i = 1; i<=8; i++)
    {
        work(a,i);
        if(dfs(a,deep+1)) return 1;
        work(a,9-i);
    }
    return 0;
}
int main()
{
    int i,j,cas = 1;
    while(~scanf("%s",s))
    {
        if(!strcmp(s,"0000000000"))
            break;
        r = s[0]-'0';
        for(i = 1; i<=9; i++)
            map[i] = s[i]-'0';
        step = 0;
        while(step<=r)
        {
            if(dfs(map,0))break;
            step++;
        }
        if(step<=r)
            printf("%d. %d\n",cas++,step);
        else
            printf("%d. -1\n",cas++);
    }
    return 0;
}
