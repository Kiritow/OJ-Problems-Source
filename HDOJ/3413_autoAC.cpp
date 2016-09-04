#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
double task[105];
double ans[105];
bool vis[105];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    int kase=0;
    while(T--)
    {
        cout<<"Case "<<++kase<<':'<<endl;
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>task[i];
        }
        double now=0;
        int pre=0;
        for(int i=0;i<n;++i)
        {
            for(int j=pre;;++j)
            {
                j%=n;
                if(!vis[j]){pre=j;break;}
            }
            pre%=n;
            double minn=floor(task[pre]);
            int rec=pre;
            if(task[pre]>1)
            for(int j=(pre+1)%n;j!=pre;++j)
            {
                j%=n;
                if(j==pre)break;
                if(vis[j])continue;
                if(task[j]<=1){rec=j;break;}
                if(floor(task[j])<minn)
                {
                    minn=floor(task[j]);
                    rec=j;
                }
            }
            vis[rec]=true;
            if(task[rec]<=1)
            {
                for(int k=pre;k!=rec;++k)
                {
                    k%=n;
                    if(k==rec)break;
                    if(vis[k])continue;
                    task[k]-=ceil(task[rec]);
                    now+=ceil(task[rec]);
                }
                now+=task[rec];
            }
            else{
                for(int k=pre;k!=rec;++k)
                {
                    k%=n;
                    if(k==rec)break;
                    if(vis[k])continue;
                    task[k]-=ceil(task[rec]);
                    now+=ceil(task[rec]);
                }
                for(int k=rec+1;k!=pre;++k)
                {
                    k%=n;
                    if(k==pre)break;
                    if(vis[k])continue;
                    task[k]-=(ceil(task[rec])-1);
                    now+=(ceil(task[rec])-1);
                }
                now+=task[rec];
            }
            ans[rec]=now;
            pre=rec+1;
            pre%=n;
        }
        for(int i=0;i<n;++i)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans[i]<<endl;
        }
    }
    return 0;
}
