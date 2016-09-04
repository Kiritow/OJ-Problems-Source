#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
using namespace std;
#define maxn 15000
struct point{
    double x,y;
    bool operator == (const point &a) const{
        return a.x==x && a.y==y;
    }
}temp;
struct line{
    point a,b;
}po[maxn];
int n;
bool cmp(const line &a,const line &b){
    return a.a.x < b.a.x;
}
int function6(int l,int r){
    int i,k,j;
    for(i=l;i<=r;i++){
        for(j=l;j<=r;j++){
            if(i==j) continue;
            if(po[i].a==po[j].a || po[i].a==po[j].b) break;
        }
        if(j==r+1){ printf("6");return 0;}
        for(j=l;j<=r;j++){
            if(i==j) continue;
            if(po[i].b==po[j].a || po[i].b==po[j].b) break;
        }
        if(j==r+1){ printf("6");return 0;}
    }
    printf("0");
    return 0;
}
int function5(int l,int r){
    int i,j,k,count,t;
    line rec[10],tem;
    bool flag[10];
    memset(flag,false,sizeof(flag));
    t=0;
    for(i=l;i<=r;i++){
        count=0;
        for(j=l;j<=r;j++){
            if(i==j)continue;
            if(po[i].a==po[j].a || po[i].a==po[j].b)
            count++;
        }
        if(count==0){ rec[t]=po[i];flag[t++]=false;}
        if(count>=2){ printf("3"); return 0;}
        count=0;
        for(j=l;j<=r;j++){
            if(i==j)continue;
            if(po[i].b==po[j].a || po[i].b==po[j].b)
            count++;
        }
        if(count>=2){ printf("3"); return 0;}
        if(count==0){ rec[t]=po[i];flag[t++]=true;}
    }
    if(MIN(rec[0].a.y,rec[0].b.y) < MIN(rec[1].a.y,rec[1].b.y)){
        if(flag[0]){printf("2");return 0;}
        else {printf("5");return 0;}
    }
    else if(MIN(rec[0].a.y,rec[0].b.y) == MIN(rec[1].a.y,rec[1].b.y)){
            if(rec[0].a.x > rec[1].b.x){
            if(flag[0]){printf("2");return 0;}
            else {printf("5");return 0;}
            }
            else {
                if(flag[1]){printf("2");return 0;}
                else {printf("5");return 0;}
            }
    }
    else{
        if(flag[1]){printf("2");return 0;}
        else {printf("5");return 0;}
    }
    return 0;
}
int main(){
    int i,j,k,l,r;
    double Max;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&po[i].a.x,&po[i].a.y,&po[i].b.x,&po[i].b.y);
            if(po[i].a.x > po[i].b.x)
            temp=po[i].a,po[i].a=po[i].b,po[i].b=temp;
            else if(po[i].a.x == po[i].b.x && po[i].a.y > po[i].b.y)
            temp=po[i].a,po[i].a=po[i].b,po[i].b=temp;
        }
        sort(po,po+n,cmp);
        l=0,r=0;
        Max=po[0].b.x;
        for(i=1;i<n;i++){
            if(po[i].a.x-Max > 5.0 || i==n-1){
                if(i!=n-1)
                r=i-1;
                else
                r=i;
                switch(r-l+1){
                    case 2:printf("1");break;
                    case 4:printf("4");break;
                    case 3:printf("7");break;
                    case 7:printf("8");break;
                    case 6:function6(l,r);break;
                    case 5:function5(l,r);break;
                    default:while(1);
                }
                l=i;
                Max=po[i].b.x;
            }
            Max=MAX(Max,po[i].b.x);
        }
        printf("\n");
    }
    return 0;
}
