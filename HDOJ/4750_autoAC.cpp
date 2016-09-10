#include <iostream>      
#include <stdio.h>      
#include <cmath>      
#include <algorithm>      
#include <iomanip>      
#include <cstdlib>      
#include <string>      
#include <memory.h>      
#include <vector>      
#include <queue>      
#include <stack>      
#include <map>    
#include <set>    
#include <ctype.h>      
#define INF 1000000010  
#define ll long long  
#define max3(a,b,c) max(a,max(b,c))  
#define MAXN 100010  
using namespace std;
struct edge{
    int u;
    int v;
    int w;
};
edge E[500010];
bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}
int p[10010];
int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}
int setsize[10010];
void _union(int a,int b){
    int fa=find(a);
    int fb=find(b);
    p[fa]=fb;
    setsize[fb]+=setsize[fa];
}
map<ll,int> mp;
int cnt[500010];
int num[500010];
int ans[10010];
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)p[i]=i;
        for(int i=0;i<n;i++)setsize[i]=1;
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));
        mp.clear();
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
        }
        sort(E+1,E+m+1,cmp);
        for(int i=1;i<=m;i++){
            int u=E[i].u;
            int v=E[i].v;
            int fu=find(u);
            int fv=find(v);
            int su=setsize[fu];
            int sv=setsize[fv];
            if(fu!=fv){
                mp[E[i].w]+=su*sv*2; 
                _union(u,v);
            }
        }
        int q=1;
        for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++){
            num[q]=it->first;
            cnt[q]=it->second;
            q++;
        }
        int size=mp.size();
        num[size+1]=INF;
        for(int i=size;i>=0;i--){
            cnt[i]+=cnt[i+1];  
        }
        int p;
        cin>>p;
        for(int k=0;k<p;k++){
            int t;
            scanf("%d",&t);
            int l=0;
            int r=size+1;
            while(true){
                int mid=(r+l)/2;
                if(num[mid]==t){
                    printf("%d\n",cnt[mid]);
                    break;
                }
                if(num[mid]>t){
                    r=mid;
                }else{
                    if(num[mid+1]>t){
                        printf("%d\n",cnt[mid+1]);
                        break;
                    }
                    l=mid;
                }
            }  
        }
    }
    return 0;
}
