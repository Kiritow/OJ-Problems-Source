#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n,m;
struct node
{
    int x;
    int y;
    char l;
}a[20005];
int c[10005];
int in[10005];
vector<int> ch[10005];
queue<int> q;
void init()
{
    int i;
    for(i=0;i<n;i++){
        c[i] = i;
        ch[i].clear();
        in[i]=0;
    }
    while(!q.empty()){
        q.pop();
    }
}
int find(int x)
{
    return x == c[x] ? x : c[x] = find(c[x]);
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m)){
        init();
        int sum = n;
        for(i=0;i<m;i++){
            scanf("%d %c %d",&a[i].x,&a[i].l,&a[i].y);
            if(a[i].l=='='){
                int xx = find(a[i].x);
                int yy = find(a[i].y);
                if(xx!=yy){
                    c[xx] = yy;
                }
                sum--;
            }
        }
        int flag = 0;    
        for(i=0;i<m;i++){
            if(a[i].l == '=') continue;
            int xx = find(a[i].x);
            int yy = find(a[i].y);
            if(xx==yy) flag=1;
            if(a[i].l == '>'&&!flag){
                ch[xx].push_back(yy);
                in[yy]++;
            }
            else if(a[i].l == '<'&&!flag){
                ch[yy].push_back(xx);
                in[xx]++;
            }
        }
        for(i=0;i<n;i++){
            if(in[i]==0&&find(i)==i){
                q.push(i);
            }
        }
        if(flag==0){
        while(!q.empty()){
            if(q.size()>1)
                flag=2;
            int t = q.front();
            q.pop();
            for(i=0;i<ch[t].size();i++){
                in[ch[t][i]]--;
                if(!in[ch[t][i]])
                    q.push(ch[t][i]);
            }
        }
        for(i=0;i<n;i++){
            if(in[i]!=0){
                flag = 1;
            }
        }
        }
        if(!flag) puts("OK");
        else if(flag == 1) puts("CONFLICT");
        else puts("UNCERTAIN");
    }
    return 0;
}
