#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int map[5][5];
int deep;
int check()
{
    int i,j;
    if(map[1][1]!=map[1][2])
    {
        for(i = 1; i<=4; i++)
            for(j = 1; j<=4; j++)
                if(map[j][i]!=map[i][i])
                    return 0;
    }
    else
    {
        for(i = 1; i<=4; i++)
            for(j = 1; j<=4; j++)
                if(map[i][j]!=map[i][i])
                    return 0;
    }
    return 1;
}
int get_h()
{
    int s1 = 0,s2 = 0,i,j;
    for(i = 1; i<=4; i++)
    {
        int a[10] = {0},ans = 0;
        for(j = 1; j<=4; j++)
            a[map[i][j]]++;
        for(j = 1; j<=4; j++)
            ans+=a[j];
        s1 = max(s1,4-ans);
    }
    for(j = 1; j<=4; j++)
    {
        int a[10] = {0},ans = 0;
        for(i = 1; i<=4; i++)
            a[map[i][j]]++;
        for(i = 1; i<=4; i++)
            ans+=a[j];
        s2 = max(s2,4-ans);
    }
    return min(s1,s2);
}
void mov_l(int i)
{
    int j;
    int t = map[i][1];
    for(j = 2; j<=4; j++)
        map[i][j-1] = map[i][j];
    map[i][4] = t;
}
void mov_r(int i)
{
    int j;
    int t = map[i][4];
    for(j = 4; j>=2; j--)
        map[i][j] = map[i][j-1];
    map[i][1] = t;
}
void mov_u(int j)
{
    int i;
    int t = map[1][j];
    for(i = 2; i<=4; i++)
        map[i-1][j] = map[i][j];
    map[4][j] = t;
}
void mov_d(int j)
{
    int i;
    int t = map[4][j];
    for(i = 4; i>=2; i--)
        map[i][j] = map[i-1][j];
    map[1][j] = t;
}
int IDA(int step)
{
    if(step == deep)
        return check();
    if(step+get_h()>deep)
        return 0;
    int i;
    for(i = 1; i<=4; i++)
    {
        mov_l(i);
        if(IDA(step+1))
            return 1;
        mov_r(i);
        mov_r(i);
        if(IDA(step+1))
            return 1;
        mov_l(i);
    }
    for(i = 1; i<=4; i++)
    {
        mov_u(i);
        if(IDA(step+1))
            return 1;
        mov_d(i);
        mov_d(i);
        if(IDA(step+1))
            return 1;
        mov_u(i);
    }
    return 0;
}
int main()
{
    int t,i,j;
    cin >> t;
    while(t--)
    {
        for(i = 1; i<=4; i++)
            for(j = 1; j<=4; j++)
                cin>>map[i][j];
        if(check())
        {
            cout<<"0"<<endl;
            continue;
        }
        deep = 1;
        while(deep<=5)
        {
            if(IDA(0))
                break;
            deep++;
        }
        if(deep<=5)
            cout<<deep<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
