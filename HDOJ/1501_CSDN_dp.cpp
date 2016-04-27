#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,al,bl,cl,lim;
char a[205],b[205],c[405];
bool dp[205][205];//dp[i][j]表示串a的前i个字符与串b的前j个字符是否能形成串c的前i+j个字符

int main() {
    int T,kase=0;
    scanf("%d",&T);
    while(kase<T) {
        scanf("%s%s%s",a+1,b+1,c+1);
        al=strlen(a+1);
        bl=strlen(b+1);
        cl=al+bl;
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int k=1;k<=cl;++k) {//枚举串c的字符
            lim=min(k,al);
            for(int i=max(1,k-bl);i<=lim;++i) {//在a串上进行状态转移
                if(dp[i-1][k-i]&&a[i]==c[k])//如果串a前i-1个字符与串b前k-i个字符能构成串c的前k个字符，并且当前a[i]==c[k]
                    dp[i][k-i]=true;
            }
            lim=min(k,bl);
            for(int j=max(1,k-al);j<=lim;++j) {//在b串上进行状态转移
                if(dp[k-j][j-1]&&b[j]==c[k])//如果串a前k-j个字符与串b前j-1个字符能构成串c的前k个字符，并且当前b[j]==c[k]
                    dp[k-j][j]=true;
            }
        }
        printf("Data set %d: %s\n",++kase,dp[al][bl]?"yes":"no");
    }
    return 0;
}
