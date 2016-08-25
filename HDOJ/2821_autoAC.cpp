#include <cstdio>
#include <iostream>
#include <deque>
#define M 28
using namespace std;
int n,m,res,found;
int mp[M][M];
deque<char>deq;
void dfs(int y,int x){
    if(res==0){
        found=1;
        return;
    }
    if(found)return;
    int flag=0,i;
    for(i=y-2;i>=0;i--)
        if(mp[i][x]){
            flag=1;
            break;
        }
    if(y>0&&mp[y-1][x])flag=0;
    if(flag){
        int d=mp[i][x];
        if(i==0){
            res-=mp[i][x];
            mp[i][x]=0;
            deq.push_back('U');
            dfs(i,x);if(found)return;
            mp[i][x]=d;
            deq.pop_back();
            res+=mp[i][x];
        }
        else {
            res--;
            mp[i][x]=0;
            deq.push_back('U');
            mp[i-1][x]+=d-1;
            dfs(i,x);if(found)return;
            mp[i][x]=d;
            mp[i-1][x]-=d-1;
            deq.pop_back();
            res++;
        }
    }
    flag=0;
    for(i=y+2;i<n;i++)
        if(mp[i][x]){
            flag=1;
            break;
        }
    if(y<n-1&&mp[y+1][x])flag=0;
    if(flag){
        int d=mp[i][x];
        if(i==n-1){
            res-=mp[i][x];
            mp[i][x]=0;
            deq.push_back('D');
            dfs(i,x);if(found)return;
            mp[i][x]=d;
            deq.pop_back();
            res+=mp[i][x];
        }
        else {
            res--;
            mp[i][x]=0;
            deq.push_back('D');
            mp[i+1][x]+=d-1;
            dfs(i,x);if(found)return;
            mp[i][x]=d;
            deq.pop_back();
            mp[i+1][x]-=d-1;
            res++;
        }
    }
    flag=0;
    for(i=x-2;i>=0;i--)
        if(mp[y][i]){
            flag=1;
            break;
        }
    if(x>0&&mp[y][x-1])flag=0;
    if(flag){
        int d=mp[y][i];
        if(i==0){
            mp[y][i]=0;
            deq.push_back('L');
            res-=d;
            dfs(y,i);if(found)return;
            deq.pop_back();
            res+=d;
            mp[y][i]=d;
        }
        else {
            mp[y][i]=0;
            deq.push_back('L');
            res--;
            mp[y][i-1]+=d-1;
            dfs(y,i);if(found)return;
            deq.pop_back();
            res++;
            mp[y][i]=d;
            mp[y][i-1]-=d-1;
        }
    }
    flag=0;
    for(i=x+2;i<m;i++)
        if(mp[y][i]){
            flag=1;
            break;
        }
    if(x<m-1&&mp[y][x+1])flag=0;
    if(flag){
        int d=mp[y][i];
        if(i==m-1){
            mp[y][i]=0;
            deq.push_back('R');
            res-=d;
            dfs(y,i);if(found)return;
            deq.pop_back();
            res+=d;
            mp[y][i]=d;
        }
        else {
            mp[y][i]=0;
            deq.push_back('R');
            res--;
            mp[y][i+1]+=d-1;
            dfs(y,i);if(found)return;
            deq.pop_back();
            res++;
            mp[y][i]=d;
            mp[y][i+1]-=d-1;
        }
    }
}
int main(void){
    while(~scanf("%d%d",&m,&n)){
        res=0;
        char c;
        for(int i=0;i<n;i++){
            getchar();
            for(int j=0;j<m;j++){
                c=getchar();
                if(c!='.'){
                    mp[i][j]=(c-'a')+1;
                    res+=(c-'a')+1;
                }
                else mp[i][j]=0;
            }
        }
        found=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]!=0)continue;
                dfs(i,j);
                if(found){
                    printf("%d\n%d\n",i,j);
                    while(!deq.empty()){
                        putchar(deq.front());
                        deq.pop_front();
                    }
                    puts("");
                    break;
                }
            }
            if(found)break;
        }
    }
    return 0;
}
