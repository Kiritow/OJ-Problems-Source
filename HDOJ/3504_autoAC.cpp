#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll __int64
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle (l+r)>>1
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*(n+1))
#define eps (1e-8)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define PI (acos(-1.0))
#pragma comment(linker, "/STACK:102400000,102400000")
template <class T> T _max(T x,T y){return x>y? x:y;}
template <class T> T _min(T x,T y){return x<y? x:y;}
template <class T> T _abs(T x){return (x < 0)? -x:x;}
template <class T> T _mod(T x,T y){return (x > 0)? x%y:((x%y)+y)%y;}
template <class T> void _swap(T &x,T &y){T t=x;x=y;y=t;}
template <class T> void getmax(T& x,T y){x=(y > x)? y:x;}
template <class T> void getmin(T& x,T y){x=(x<0 || y<x)? y:x;}
int TS,cas=1;
const int M=500+5;
int n;
string str,ret;
bool cmp(char a,char b){
    return a > b;
}
bool vis[M];
bool check(char c,int i){
    return ret[i-1]!=c && (i+1==ret.length()||ret[i+1]!=c);
}
void run(){
    int i,j;
    cin>>str;
    sort(str.begin(),str.end(),cmp);
    clr_all(vis,0);
    ret.clear();
    ret+=str[0],vis[0]=1;
    for(i=1,j=1;i<str.length();i++) if(!vis[i]){
        if(str[i]!=ret[ret.length()-1]) ret+=str[i],vis[i]=1;
        else{
            for(j=i+1;j<str.length();j++) if(!vis[j]){
                if(str[j]!=ret[ret.length()-1]){
                    ret+=str[j],ret+=str[i];
                    vis[i]=vis[j]=1;
                    break;
                }
            }
            if(j==str.length()){
                for(;i<str.length();i++) if(!vis[i]){
                    for(j=ret.length()-1;j>=0;j--){
                        if(str[i]!=ret[j] && (j==0 || str[i]!=ret[j-1])){
                            ret.insert(j,1,str[i]);
                            break;
                        }
                    }
                    if(j<0) break;
                }
                for(i=0;i<ret.length();i++){
                    for(j=i+1;j<ret.length();j++){
                        if(ret[i]<ret[j] && check(ret[i],j) && check(ret[j],i)){
                            _swap(ret[i],ret[j]);
                        }
                    }
                }
                break;
            }
        }
        //cout<<ret<<endl;
    }
    cout<<ret<<endl;
}
void preSof(){
}
int main(){
 preSof();
 for(scanf("%d",&TS);cas<=TS;cas++) run();
 return 0;
}
