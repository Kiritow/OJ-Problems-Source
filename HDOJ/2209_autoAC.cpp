#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 99999999
int num[25];
char s[25];
int dfs(int n,int len,int step)
{
    if(n==len)
    {
        return num[len-1]?INF:step;
    }
    if(num[n-1])
    {
        num[n-1]=0;
        num[n]=!num[n];
        num[n+1]=!num[n+1];
        step++;
    }
    return dfs(n+1,len,step);
}
int main()
{
    while(gets(s))
    {
        int len=strlen(s);
        int step=INF,t;
        for(int i=0;i<len;i++)
        {
            num[i]=s[i]-'0';
        }
        num[0]=!num[0];
        num[1]=!num[1];
        step=min(step,dfs(1,len,1));
        for(int i=0;i<len;i++)
        {
            num[i]=s[i]-'0';
        }
        step=min(step,dfs(1,len,0));
        if(step==INF)
            cout<<"NO"<<endl;
        else
            cout<<step<<endl;
    }
    return 0;
}
