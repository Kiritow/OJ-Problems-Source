#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10000000+10;
char s[MAX];
int pos[500];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",s);
        memset(pos,-1,sizeof pos);
        int st=0,ed=0,len=0,temp=0;
        for(int i=0;i<n;++i){
            if(pos[s[i]]>=temp){
                if(i-temp>len){len=i-temp,st=temp,ed=i-1;}
                temp=pos[s[i]]+1;
            }
            pos[s[i]]=i;
        }
        if(n-temp>len){len=n-temp,st=temp,ed=n-1;}
        printf("%d %d %d\n",len,st,ed); 
    }
    return 0;
}
