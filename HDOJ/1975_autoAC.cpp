#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[30];
bool vis[30];
int cnt[30];
bool confirm(){
    bool flag=true;
    for(int i=1;i<=26;i++)
    if(i%2==0){
        if(cnt[i]%2){
            flag=false;
            break;
        }
    }
    return flag;
}
int main(){
    int T,cnted;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        memset(vis,false,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<26;i++){
            if(!vis[i]){
                int k=i;
                cnted=0;
                while(!vis[k]){
                    vis[k]=true;
                    k=str[k]-'A';
                    cnted++;
                }
                cnt[cnted]++;
            }
        }
        if(confirm())
        printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
