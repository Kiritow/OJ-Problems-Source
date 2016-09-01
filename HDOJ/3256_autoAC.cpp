#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int M=10010;
const int N=510;
char s[110];
struct Line
{
    __int64 x1, y1, x2, y2;
} ll[N], pos;
int n, flag[M*2], ans;
void input(__int64 &a)
{
    scanf("%s", &s);
    int i, j, len=strlen(s);
    a = 0;
    i = 0;
    if(s[0]=='-')
        i++;
    for(; i<len && s[i]!='.'; i++)
    {
        a *= 10;
        a += s[i]-'0';
    }
    for(i++, j=0; i<len; i++, j++)
    {
        a *= 10;
        a += s[i]-'0';
    }
    while(j<4)
    {
        a *= 10;
        j++;
    }
    if(s[0]=='-')
        a = -a;
}
void cal(int i, Line li)
{
    if(li.x1==li.x2)
    {
        if(li.x1==i*10000)
        {
            if(li.y1>li.y2)
                swap(li.y1, li.y2);
            if(li.y1<=0)         
                li.y1 = li.y1/10000; 
            else
                li.y1 = li.y1/10000+1;
            if(li.y2>=0) //...
                li.y2 /= 10000;
            else
                li.y2 = li.y2/10000-1;
            for(int j=li.y1; j<=li.y2; j++)
            {
                if(flag[j+M]!=i)
                {
                    flag[j+M] = i;
                    ans++;
                }
            }
        }
        return;
    }
    if(!(li.x1<=i*10000 && i*10000<=li.x2) )
        return;
    if((i*10000-li.x1)*(li.y2-li.y1)%(li.x2-li.x1)==0)
    {
        int j = (i*10000-li.x1)*(li.y2-li.y1)/(li.x2-li.x1)+li.y1;
        if(j%10000==0)
        {
            j /= 10000;
            if(flag[j+M]!=i)
            {
                flag[j+M] = i;
                ans++;
            }
        }
    }
}
int main()
{
    int i, j, cas, cas1;
    scanf("%d", &cas);
    for(cas1=1; cas1<=cas; cas1++)
    {
        scanf("%d", &n);
        pos.x1 = M*M*10;
        pos.x2 = -M*M*10;
        for(i=0; i<n; i++)
        {
            input(ll[i].x1);
            input(ll[i].y1);
            input(ll[i].x2);
            input(ll[i].y2);
            if(ll[i].x1 > ll[i].x2)
            {
                swap(ll[i].x1, ll[i].x2);
                swap(ll[i].y1, ll[i].y2);
            }
            if(ll[i].x1<pos.x1)
                pos.x1 = ll[i].x1;
            if(ll[i].x2<pos.x1)
                pos.x1 = ll[i].x2;
            if(ll[i].x1>pos.x2)
                pos.x2 = ll[i].x1;
            if(ll[i].x2>pos.x2)
                pos.x2 = ll[i].x2;
        }
        for(i=0; i<M*2; i++)
            flag[i] = -1000000;
        ans = 0;
        pos.x1 /= 10000;
        pos.x1--; 
        pos.x2 /= 10000;
        pos.x2++;
        for(i=pos.x1; i<=pos.x2; i++)
        {
            for(j=0; j<n; j++)
            {
                cal(i, ll[j]);
            }
        }
        printf("Case %d: %d\n", cas1, ans);
    }
    return 0;
}
