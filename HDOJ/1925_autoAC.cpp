#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<cmath>  
#include<vector>  
using namespace std;  
#define nMax  40  
char s[nMax];  
int m;  
class P {  
public:  
    int x,y;  
    P() {};  
    P(int x,int y):x(x),y(y) {};  
    void out() { printf("(%d,%d)\n",x,y); }  
};  
P rotate(P p,int k) {  
    if(k==1) return P(p.y,-p.x);  // turn right  
    else     return P(-p.y,p.x);  // turn left  
}  
P rotate(P T,P p,int k) {  
    P tmp(p.x-T.x,p.y-T.y);  
    P ret = rotate(tmp,k);  
    return P(ret.x+T.x,ret.y+T.y);  
}  
P p[40];  
int r[40];  
P dfs(int m) {  
    if(m==0) return p[0];  
    long long  i=1LL;  
    int j=1;  
    while(m>=i) {  
        i <<= 1;  
        j += 1;  
    }  
    i >>= 1;j--;  
    if(m==i) return p[j];  
    m -= i;  
    return rotate(p[j],dfs(i-m),r[j]);  
}  
int main() {  
    int t;  
    scanf("%d",&t);  
    while(t--) {  
        scanf("%s%d",s,&m);  
        int l = strlen(s);  
        p[0]=P(0,0);  
        p[1]=P(1,0);  
        for(int j=1,i=l-1;i>=0;i--,j++) r[j] = (s[i]=='U'?1:0);  
        for(int i=2;i<=l+1;i++)  p[i] = rotate(p[i-1],p[0],r[i-1]);  
        P ret = dfs(m);  
        ret.out();  
    }  
    return 0;  
}
