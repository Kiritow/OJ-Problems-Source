#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
using namespace std;
int mp[300][300];
int n;
void add(int a,int b){
    mp[a][b]=1;
    for(int i=1;i<=n;i++)
        if(mp[i][a]){
            mp[i][b]=1;
            for(int j=1;j<=n;j++)
                if(mp[a][j])
                    mp[i][j]=1;
        }
    for(int i=1;i<=n;i++)
        if(mp[b][i]){
            mp[a][i]=1;
            for(int j=1;j<=n;j++)
                if(mp[j][b])
                    mp[j][i]=1;
        }
}
int main(){
    int t;
    int cas=1;
    while(~scanf("%d%d",&n,&t)){
        if(!n && !t)break;
        memset(mp,0,sizeof(mp));
        int ans=0;
        while(t--){
            int a,b;
            scanf("%d%d",&a,&b);    
            if(mp[b][a])ans++;
            else if(a==b)ans++;
            else if(!mp[a][b]) add(a,b);
        }
        printf("%d. %d\n",cas++,ans);
    }
    return 0;
}
