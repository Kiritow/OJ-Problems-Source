#include<cstdio>
#include<cstring>
using namespace std;
__int64 dp[100][30][30];
int ans[100];
int main(){
    memset(dp,0,sizeof(dp));
    dp[0][1][0]=1;
    for(int i=2;i<=75;i++){
        for(int j=1;j<=27;j++){
            for(int k=0;k<=20;k++){
                __int64 val=0;
                if(j==1){
                    if(k==0) continue;
                    for(int jj=2;jj<=27;jj++){
                        if(i>=j) val+=dp[i-j][jj][k-1];
                    }
                }else{
                    for(int jj=1;jj<=27;jj++){
                        if(i>=j) val+=dp[i-j][jj][k];
                    }
                }
                dp[i][j][k]=val;
            }
        }
    }
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int V,W;
        __int64 I;
        scanf("%d%d%I64d",&V,&W,&I);
        printf("Case #%d: ",++cas);
        W-=1;
        I-=1;
        ans[0]=-1;
        for(int i=2;i<=27;i++){
            if(I>=dp[V][i][W]){
                I-=dp[V][i][W];
            }else{
                V-=i;
                ans[0]=i;
                break;
            }
        }
        if(ans[0]==-1){
            puts("Corrupted!");
            continue;
        }
        int cnt=1;
        bool flag=false;
        while(true){
            for(int i=1;i<=27;i++){
                if(flag&&(i==1)) continue;
                if((W==0)&&(i==1)) continue;
                flag=false;
                if(I>=dp[V][i][W]){
                    I-=dp[V][i][W];
                }else{
                    V-=i;
                    if(i==1){W-=1;flag=true;}
                    ans[cnt++]=i;
                    break;
                }
            }
            if(V==0) break;
        }
        for(int i=0;i<cnt;i++){
            if(ans[i]==1) putchar(' ');
            else putchar(ans[i]-2+'a');
        }
        puts("");
    }
}
