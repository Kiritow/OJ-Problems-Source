#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
int N;
int C;
int a[101];
int _open[101];
int _close[101];
string ss[300];
void do1()
{
    for(int i=1;i<=100;++i)
        a[i]^=1;
}
void do2()
{
    for(int i=2;i<=N;i+=2)
        a[i]^=1;
}
void do3()
{
    for(int i=1;i<=N;i+=2)
        a[i]^=1;
}
void do4()
{
    for(int i=1;i<=N;i+=3)
        a[i]^=1;
}
int cnt=0;
int check()
{
    for(int i=1;i<=N;++i){
        if(_open[i]==1&&a[i]==0)return 1;
        if(_close[i]==1&&a[i]==1)return 1;
    }
    return 0;
}
void dfs(int c)
{
    if(c==C)
    {
        if(check()==0)
        {
            ss[cnt]="";
            for(int i=0; i<N; i++)
                ss[cnt]+=(a[i+1]+'0');
            cnt++;
        }
        return;
    }
    for(int i=1;i<=4;++i)
    {
        switch(i)
        {
        case 1:
            do1();//????
            dfs(c+1);
            do1();//?????????
            break;
        case 2:
            do2();
            dfs(c+1);
            do2();
            break;
        case 3:
            do3();
            dfs(c+1);
            do3();
            break;
        case 4:
            do4();
            dfs(c+1);
            do4();
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    //   freopen("1176.in","r",stdin);
    scanf("%d",&N);
    scanf("%d",&C);
    memset(_open,0,sizeof(_open));
    memset(_close,0,sizeof(_close));
    for(int i=1;i<=N;++i)
        a[i]=1;
    int tmp;
    while(scanf("%d",&tmp)==1&&tmp!=-1)
        _open[tmp]=1;
    while(scanf("%d",&tmp)==1&&tmp!=-1)
        _close[tmp]=1;
    if(C>4)
    {
        C%=2;
        if (C==1)
        {
            C=3;
        }
        else
        {
            C=4;
        }
    }
    dfs(0);
    sort(ss,ss+cnt);
    cout<<ss[0]<<endl;
    int i,j;
    for(i=0,j=1;j<cnt;j++)
        if(ss[i]!=ss[j])
        {
            i=j;
            cout<<ss[i]<<endl;
        }

    return 0;
}
