#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<time.h>
#include<string.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int p[9000];
int ans[9000];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(p,0,sizeof(p));
        int i,cas,t=-1;
        for(i=2;i<=n;i++){
            scanf("%d",p+i);
        }
        for(cas=1;cas<=n;cas++){
            t=-1;
            for(i=2;i<=n;i++){
                if(p[i]==0){
                    t=i;
                }
            }
            if(t==-1)
                t=1;
            ans[t]=cas;
            for(i=t;i<=n;i++)
                p[i]--;
        }
        for(i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
