#include <stdio.h>
struct point{
    int x,y;  
}p[3],m[3];
int gcd(int a,int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int abs(int x){
    return x>0?x:-x;  
}
int S(point p1,point p2,point p0){
    return abs((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x));  
}
int main(){
    int sum,s,ans;
    while(~scanf("%d%d%d%d%d%d",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)){
        if(!p[0].x&&!p[0].y&&!p[1].x&&!p[1].y&&!p[2].x&&!p[2].y)break;
        m[0].x=abs(p[0].x-p[1].x);m[0].y=abs(p[0].y-p[1].y);
        m[1].x=abs(p[1].x-p[2].x);m[1].y=abs(p[1].y-p[2].y);
        m[2].x=abs(p[0].x-p[2].x);m[2].y=abs(p[0].y-p[2].y);
        sum=gcd(m[0].x,m[0].y)+gcd(m[1].x,m[1].y)+gcd(m[2].x,m[2].y);
        s=S(p[1],p[2],p[0]);
        ans=(s-sum+2)/2;
        printf("%d\n",ans);
    }
    return 0;
}
