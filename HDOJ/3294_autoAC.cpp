#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=200000+10;
char s[MAX*2],temp[2];
int p[MAX*2];
int main(){
    while(scanf("%s%s",temp,s)!=EOF){
        int len=strlen(s),id=0,maxid=0;
        for(int i=len;i>=0;--i){
            s[i+i+2]=s[i];
            s[i+i+1]='#';
        }
        s[0]='*';
        for(int i=2;i<2*len+1;++i){
            if(p[id]+id>i)p[i]=min(p[2*id-i],p[id]+id-i);
            else p[i]=1;
            while(s[i+p[i]] == s[i-p[i]])++p[i];
            if(id+p[id]<i+p[i])id=i;
            if(p[maxid]<p[i])maxid=i;
        }
        if(p[maxid]-1<2)cout<<"No solution!"<<endl;
        else{
            cout<<(maxid-p[maxid]+2)/2-1<<' '<<(maxid+p[maxid]-2)/2-1<<endl;
            int k=temp[0]-'a';
            for(int i=maxid-p[maxid]+2;i<=maxid+p[maxid]-2;i+=2)printf("%c",(s[i]-'a'-k+26)%26+'a');
            cout<<endl;
        }
    }
    return 0;
}
