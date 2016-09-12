#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define maxn 110
class node
{
public:
    string sex,name;
    double sum;
    int r1,r2;
    void set(string n,string s,int o,int t)
    {
        sex=s,name=n;
        r1=o,r2=t;
    }
}male[maxn],fe[maxn],ans[maxn];
bool cmp(node x,node y)
{
    return x.sum>y.sum;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        string name,sex;
        int r1,r2,rr1=0,rr2=0;
        int f=0,p=0,top=0;
        for(int i=0;i<n;i++)
        {
            cin>>name>>sex>>r1>>r2;
            rr1=max(rr1,r1);
            rr2=max(rr2,r2);
            if(sex=="male") male[p++].set(name,sex,r1,r2);
            else fe[f++].set(name,sex,r1,r2);
        }
        double m1,m2;
        m1=300*1.0/rr1,m2=300*1.0/rr2;
        for(int i=0;i<p;i++)
            male[i].sum=male[i].r1*(m1)*0.3+male[i].r2*(m2)*0.7;
        for(int i=0;i<p;i++)
            fe[i].sum=fe[i].r1*(m1)*0.3+fe[i].r2*(m2)*0.7;
        sort(male,male+p,cmp);
        sort(fe,fe+f,cmp);       
        if(f)
            ans[top++]=fe[0];
        for(int i=0;i<p;i++)
        {
            ans[top++]=male[i];
        }
        for(int i=0;i<f;i++)
        {
            if(fe[i].name!=ans[0].name)
                ans[top++]=fe[i];
        }
        sort(ans+1,ans+top,cmp);
        sort(ans,ans+m,cmp);
        cout<<"The member list of Shandong team is as follows:"<<endl;
        for(int i=0;i<m;i++) cout<<ans[i].name<<endl;
    }
    return 0;
}
