#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ull unsigned __int64
#define ll __int64
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle (l+r)>>1
#define MOD 1000000007
#define esp (1e-4)
const int INF=0x3F3F3F3F;
const double DINF=10001.00;
const int N=1010;
int n,m;
int mtx[N<<1][N<<1],X[N<<1],Y[N<<1],xc,yc,cnt,vis[N];
struct node{
    int x1,y1,x2,y2;
    void write(){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
    }
}a[N];
int bs(int key,int size,int A[]){
    int l=0,r=size-1,mid;
    while(l<=r){
        mid=middle;
        if(key>A[mid]) l=mid+1;
        else if(key<A[mid]) r=mid-1;
        else return mid;
    }return -1;
}
int main(){
    int i,j,k,r,c,x1,y1,x2,y2;
    while(~scanf("%d%d%d",&r,&c,&n)){
        for(i=m=0;i<n;i++){
            a[i].write();
            X[m]=a[i].x1,Y[m]=a[i].y1,m++;
            X[m]=a[i].x2,Y[m]=a[i].y2,m++;
        }
        sort(X,X+m);sort(Y,Y+m);
        for(i=xc=1;i<m;i++) if(X[i]!=X[i-1]) X[xc++]=X[i];
        for(i=yc=1;i<m;i++) if(Y[i]!=Y[i-1]) Y[yc++]=Y[i];
        memset(mtx,0,sizeof(mtx));
        for(i=0;i<n;i++){
            x1=bs(a[i].x1,xc,X),x2=bs(a[i].x2,xc,X);
            y1=bs(a[i].y1,yc,Y),y2=bs(a[i].y2,yc,Y);
            for(j=x1;j<=x2;j++)
                for(k=y1;k<=y2;k++)
                    mtx[j][k]=i;
        }
        memset(vis,0,sizeof(vis));
        for(i=cnt=0;i<xc;i++){
            for(j=0;j<yc;j++) if(mtx[i][j]){
                if(!vis[mtx[i][j]]) cnt++,vis[mtx[i][j]]=1;
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}
