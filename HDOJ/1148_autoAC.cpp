#include<iostream>
#include<iomanip>
#include<string.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dec(char *a,char *b)
{
    int a1,b1;
    a1=strcmp(a,"rock");
    b1=strcmp(b,"rock");
    if(a1>0)
    {
        if(b1>0)
            return 0;
        else if(b1<0)
            return 1;
        else
            return -1;
    }
    else if(a1<0)
    {
        if(b1>0)
            return -1;
        else if(b1<0)
            return 0;
        else return 1;
    }
    else
    {
        if(b1>0)
            return 1;
        else if(b1<0)
            return -1;
        else
            return 0;
    }
}
int main()
{
    char s1[10],s2[10];
    double win[1000]={0},lose[1000]={0};
    int m,n,i,j,k,a,b;
    k=1;
    while(cin>>m&&m)
    {
        if(k!=1)
         cout<<endl;
        cin>>n;
        for(i=0;i<n;i++)
        {
        cin>>a>>s1>>b>>s2;
        if(dec(s1,s2)==1)
        {
            win[a]++;
            lose[b]++;
        }
        else if(dec(s1,s2)==-1)
        {
            win[b]++;
            lose[a]++;
        }
        }
        for(j=1;j<m+1;j++)
        {
            if(win[j]==0&&lose[j]==0)
                cout<<"-"<<endl;
            else
                cout<<setiosflags(ios::fixed)<<setprecision(3)<<(win[j]/(win[j]+lose[j]))<<endl;
        }
         k++;
        memset(win,0,sizeof(win));
        memset(lose,0,sizeof(lose));
    }
    return 0;
}
