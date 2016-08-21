#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAX 100+5
typedef long long LL;
const double pi=3.141592653589793;
const int INF=1e9;
const double inf=1e20;
const double eps=1e-6;
const int mod=1000000007;
struct point{
    int x,y;
}p[35][105];
double circulation(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool cross(point a,point b,point c,point d){
    if(max(a.x,b.x)>=min(c.x,d.x)&&
       max(c.x,d.x)>=min(a.x,b.x)&&
       max(a.y,b.y)>=min(c.y,d.y)&&
       max(c.y,d.y)>=min(a.y,b.y)&&
       circulation(a,b,c)*circulation(a,d,b)>=0&&
       circulation(a,c,d)*circulation(b,d,c)>=0) return true;
    return false;
}
int main(){
    int n,k[35];
    while(cin>>n){
        memset(k,0,sizeof(k));
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++){
            cin>>k[i];
            for(int j=0;j<k[i];j++) scanf("%d%d",&p[i][j].x,&p[i][j].y);
        }
        if(n==1){
            printf("No\n");
            continue;
        }
        int flag=0;
        for(int i=0;i<n-1;i++){
            for(int j=1;j<k[i];j++){
                for(int t=i+1;t<n;t++){
                    for(int h=1;h<k[t];h++){
                        if(cross(p[i][j-1],p[i][j],p[t][h-1],p[t][h])){
                            flag=1;
                            break;
                        }
                    }
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
