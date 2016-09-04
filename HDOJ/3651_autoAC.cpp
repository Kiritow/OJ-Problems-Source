#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int inf=1e9;
string st;
int dp[110][15][15];
int DP(int len,int x,int y){
    if(len==0) return 0;
    if(dp[len][x][y]!=-1) return dp[len][x][y];
    int ans=inf,pos=st[st.length()-len]-'0';
    if(pos==0) pos=10;
    for(int i=0;i<pos;i++){
        int tmp=DP(len-1,i,pos)+max(abs(i-x),abs(y-pos)+1 );
        if(tmp<ans) ans=tmp;
    }
    for(int i=pos+1;i<=10;i++){
        int tmp=DP(len-1,pos,i)+ max(abs(i-y),abs(x-pos)+1 );
        if(tmp<ans) ans=tmp;
    }
    return dp[len][x][y]=ans;
}
int main(){
    while(cin>>st){
        memset(dp,-1,sizeof(dp));
        cout<<DP(st.length(),5,6)<<endl;
    }
    return 0;
}
