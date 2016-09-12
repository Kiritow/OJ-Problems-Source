#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define sf scanf
#define mx 100000000
struct node{
int id,v;
//friend bool operator<(node a,node b){return (a.v==b.v)?(a.id>b.id):(a.v>b.v);}
bool operator < (const node &a)const {
    if(a.v==v)return id>a.id;
    return v<a.v;
}
};
priority_queue<node> que1,que2;
queue<int> que;
int n,m,k;
int g[1000000],sum[1000000],a[1000000],r[1000000];
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        while(!que1.empty()) que1.pop();
        while(!que2.empty())que2.pop();
        for(int i = 1;i<=n;i++) {sf("%d",a+i);sum[i]=sum[i-1]+a[i];}
        int t = 0;
        for(int i = 0;i<=n;i++){while(t<=n&&sum[t]<i*k + m) t++;r[i] = t-1;}
        for(int i = n;i>0;i--)
        {
            g[i] = 0;
            if(r[i] == n) g[i] = mx + i;
            else
            {
                while(!que1.empty()){
                        node tmp = que1.top();
                        if(tmp.id>r[i])que1.pop();
                        else if(tmp.v*2>=g[tmp.id] + i)
                            {
                                que2.push(node{tmp.id,g[tmp.id]-tmp.id});
                                que1.pop();
                            }
                        else break;
                }
                while(!que2.empty())
                    {
                        node tmp = que2.top();
                        if(tmp.id>r[i])que2.pop();
                        else break;
                    }
                if(!que1.empty())g[i] = max(g[i],que1.top().v);
                if(!que2.empty())g[i] = max(g[i],que2.top().v+i);
            }
            if(g[i]>i) que1.push((node){i,i});
            else que2.push((node){i,g[i]-i});
        }
        for(int i = 1;i<=n;i++)g[i]-=i;
        g[0] = 0;
        for(int i = 1;i<=r[0];i++) g[0] = max(g[0],g[i]);
        if(g[0] > n) puts("Poor JRY!");
        else if(!g[0]) puts("Poor Hero!");
        else
        {
            printf("%d\n",g[0]);
            int i = 1;
            while(g[i]!=g[0]) i++;
            que.push(i);
            while(g[i]!=mx)
            {
                int j=i+g[0];
                while(g[j]<g[0]) {
                        j++;
                }
                i = j;
                que.push(i);
            }
            printf("%d\n",que.size());
            while(!que.empty())
            {
                int tmp = que.front();
                printf("%d",tmp);
                que.pop();
                if(que.size())printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
