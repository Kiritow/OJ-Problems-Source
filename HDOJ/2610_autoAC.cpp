#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,p,len,count_num;
int num[1001];
bool flag;
typedef struct
{
    int n,pos;
}Tem;
Tem tem[1001];
bool check(int s,int e)
{
    for(int i = s+1; i < e; i++)
    if(num[i]==num[e])return false;
    return true;
}
void print_sequence(int length)
{
    for(int i = 0; i < length-1;i++)
    cout<<tem[i].n<<" ";
    cout<<tem[length-1].n<<endl;
}
void dfs(int dep,int pos)
{
    if(count_num >= p)return;
    if(dep==len)
    {
        count_num++;
        flag = true;
        print_sequence(len);
        return;
    }
    for(int i=pos;i<n;i++)
    {
        if((dep!=0&&tem[dep-1].n<=num[i])||dep==0)
        {
            if(dep==0&&!check(-1,i))
            continue;
            if(dep!=0&&!check(tem[dep-1].pos,i))
            continue;
            tem[dep].n = num[i];
            tem[dep].pos = i;
            dfs(dep+1,i+1);
        }
    }
    return;
}
int main()
{
    while(cin>>n>>p)
    {
        for(int i=0;i<n;i++)
        cin>>num[i];
        count_num = 0;
        for(int i = 1;i < n;i++)
        {
            flag=false;
            len = i;
            dfs(0,0);
            if(count_num>=p||!flag)break;
        }
        cout<<endl;
    }
    return 0;
}
