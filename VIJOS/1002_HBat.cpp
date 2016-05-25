#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int stone[1000001],map[1000001],f[1000001];

//int ans;
int w=2000;
int l,s,t,m;
int p=0,k;/*
inline void findd(int a)
{
    if(ans>w)return;
    if(a>=p)
    {
        if(ans<w)w=ans;
        return;
    }
    int i;
    for(i=a+s;i<=a+t;++i)
    {
        if(map[i]==1)ans++;
        findd(i);
        if(map[i]==1)ans--;
    }
    return;
}
*/
int main()
{


    scanf("%d%d%d%d",&l,&s,&t,&m);

    int i,j;

    for(i=1;i<=m;++i)
        scanf("%d",&stone[i]);

    sort(stone+1,stone+m+1);



    for(i=1;i<=m;++i)
    {
        l=stone[i]-stone[i-1];
        if(l%t==0)k=t;
        else k=l%t+t;
        if(l<k)k=l;
        p+=k;
        map[p]=1;
    }
    for(i=1;i<=p+t;++i)
    {
        w=200;
        for(j=i-t;j<=i-s;++j)
        {
            if(j>=0&&f[j]<w)w=f[j];
        }
        /*for(j=i-t;j>=0&&j<=i-s;++j)                //把j>=0放在循环头，有时候可能导致循环不进行（开始的时候） 
        {
            if(f[j]<w)w=f[j];
        }*/
        f[i]=w+map[i];
    }
    w=200;
    for(i=p;i<=p+t;++i)
    {
        if(f[i]<w)w=f[i];
    }

    //findd(0);
    cout<<w;

    return 0;
}
