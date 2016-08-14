#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vis[2010];
int num[2010];
int main(){
    int n;
    int t1,t2;
    bool flag;
    char a[7000];
    while(~scanf("%d",&n)){
            memset(num,0,sizeof(num));
            flag=1;
            for(int i=1;i<=n-1;i++){
                    memset(vis,0,sizeof(vis));
                    for(int j=1;j<=n/2;j++){
                            scanf("%d-%d",&t1,&t2);
                            if(vis[t1]||vis[t2]){
                                flag=0;
                            }
                            vis[t1]=1;
                            vis[t2]=1;
                            num[t1]++;
                            num[t2]++;
                    }
            }
            if(flag){
              for(int i=1;i<=n;i++){
                    if(num[i]!=n-1){
                            flag=0;
                            break;
                    }
              }
            }
            if(flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
    return 0;
}
