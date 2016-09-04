#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct T
{
    string name;
    int s;
}t[200];
string stu[200];
bool flag;
int n;
bool cmp(T a,T b)
{
    return a.s>b.s;
}
bool cmp2(string a,string b)
{
    return a<b;
}
void dfs(int x,int sum,int step)
{
    if(sum==0)
    {
        if(step==2||step==3)  flag=true;
        return;
    }
    if(step==3&&sum!=0)   return;
    if(sum<t[n-1].s)  return;
    if(x+1>=n)   return;
    for(int i=x+1;i<n;i++)
    {
        if(flag)   return;
        if(sum-t[i].s>=0&&step+1<=3)   dfs(i,sum-t[i].s,step+1);
    }
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)   cin>>t[i].name>>t[i].s;
        sort(t,t+n,cmp);
        int k=0;
        for(int i=n-3;i>=0;i--)
        {
            flag=false;
            dfs(i,t[i].s,0);
            if(flag)  stu[k]=t[i].name,k++;
        }
        sort(stu,stu+k,cmp2);
        cout<<k<<endl;
        for(int i=0;i<k;i++)
        cout<<stu[i]<<endl;
    }
    return 0;
}
