#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10+10;
bool mark[MAX];
int s[MAX],p[MAX],pos[MAX],num;
bool panduan(int Pos,int x){
    if(Pos == 0)if(abs(p[1]-x) == 1 || abs(p[2]-x) == 1 || abs(p[3]-x) == 1)return false;
    if(Pos == 1)if(abs(p[0]-x) == 1 || abs(p[2]-x) == 1 || abs(p[4]-x) == 1 || abs(p[5]-x) == 1)return false;
    if(Pos == 2)if(abs(p[0]-x) == 1 || abs(p[1]-x) == 1 || abs(p[3]-x) == 1 || abs(p[4]-x) == 1 || abs(p[5]-x) == 1 || abs(p[6]-x) == 1)return false;
    if(Pos == 3)if(abs(p[0]-x) == 1 || abs(p[2]-x) == 1 || abs(p[5]-x) == 1 || abs(p[6]-x) == 1)return false;
    if(Pos == 4)if(abs(p[1]-x) == 1 || abs(p[2]-x) == 1 || abs(p[5]-x) == 1 || abs(p[7]-x) == 1)return false;
    if(Pos == 5)if(abs(p[1]-x) == 1 || abs(p[2]-x) == 1 || abs(p[3]-x) == 1 || abs(p[4]-x) == 1 || abs(p[6]-x) == 1 || abs(p[7]-x) == 1)return false;
    if(Pos == 6)if(abs(p[2]-x) == 1 || abs(p[3]-x) == 1 || abs(p[5]-x) == 1 || abs(p[7]-x) == 1)return false;
    if(Pos == 7)if(abs(p[4]-x) == 1 || abs(p[5]-x) == 1 || abs(p[6]-x) == 1)return false;
    return true;
}
void dfs(int Pos){
    if(Pos>pos[0]){
        ++num;
        if(num == 1){
            for(int i=0;i<8;++i)pos[pos[0]+1+i]=p[i]; 
        }
        return;
    }
    for(int i=1;i<=s[0];++i){
        if(mark[s[i]])continue;
        if(panduan(pos[Pos],s[i])){
            p[pos[Pos]]=s[i];
            mark[s[i]]=true;
            dfs(Pos+1);
            p[pos[Pos]]=10;
            mark[s[i]]=false;
            if(num>1)return;
        }
    }
}
int main(){
    int t,Case=0;
    cin>>t;
    while(t--){
        memset(mark,false,sizeof mark);
        num=pos[0]=s[0]=0;
        for(int i=0;i<8;++i){
            cin>>p[i];
            if(p[i] == 0)pos[++pos[0]]=i,p[i]=10;
            mark[p[i]]=true;
        }
        for(int i=1;i<=8;++i)if(!mark[i])s[++s[0]]=i;
        if(pos[0]>0)dfs(1);
        cout<<"Case "<<++Case<<':';
        if(!num)cout<<" No answer"<<endl;
        if(num>1)cout<<" Not unique"<<endl;
        if(num == 1){
            for(int i=0;i<8;++i)cout<<' '<<pos[pos[0]+1+i];
            cout<<endl;
        }
    }
    return 0;
}
