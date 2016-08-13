#include<stdio.h>  
#include<math.h>  
struct p{  
    double x,y;  
};  
double cross(p a,p b,p c){  
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);  
}  
int main(){  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        int n;  
        p p1,p2,tp;  
        double res=0,s,tx=0,ty=0;  
        scanf("%d",&n);  
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);  
        for(int i=3;i<=n;++i){  
            scanf("%lf%lf",&tp.x,&tp.y);  
            s=cross(p1,p2,tp);  
            res+=s;  
            tx+=(p1.x+p2.x+tp.x)*s;  
            ty+=(p1.y+p2.y+tp.y)*s;   
            p2.x=tp.x;p2.y=tp.y;  
        }  
        printf("%.2lf %.2lf\n",tx/(3*res),ty/(3*res));  
    }  
    return 0;  
}
