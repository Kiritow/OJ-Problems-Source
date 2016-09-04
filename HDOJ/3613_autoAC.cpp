#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=500000+10;
char s[MAX*2];
int p[MAX*2],sum[MAX],val[27];
int per[MAX],pos[MAX];
int main(){
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<26;++i)scanf("%d",&val[i]);
        scanf("%s",s);
        int len=strlen(s),id=0,ans=-INF,temp=0;
        for(int i=1;i<=len;++i)sum[i]=sum[i-1]+val[s[i-1]-'a'];
        for(int i=len;i>=0;--i){
            s[i+i+2]=s[i];
            s[i+i+1]='#';
        }
        s[0]='*';
        for(int i=2;i<len+len+1;++i){
            if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
            else p[i]=1;
            while(s[i-p[i]] == s[i+p[i]])++p[i];
            if(id+p[id]<i+p[i])id=i;
            if(i-p[i] == 0)per[p[i]-1]=n+1;
            if(i+p[i] == len+len+2)pos[p[i]-1]=n+1;
        }
        for(int i=1;i<len;++i){
            if(per[i] == n+1)temp+=sum[i];
            if(pos[len-i] == n+1)temp+=sum[len]-sum[i];
            if(temp>ans)ans=temp;
            temp=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
