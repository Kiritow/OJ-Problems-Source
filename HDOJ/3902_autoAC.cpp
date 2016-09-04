#include<iostream>
using namespace std;
#define N 40005
struct node{
    double x,y;
}p[N];
int n;
double cal_dis(int x,int y){
    double x1=p[x].x,y1=p[x].y;
    double x2=p[y].x,y2=p[y].y;
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(void){
    while(~scanf("%d",&n)){
        int k=1;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&p[k].x,&p[k].y);
            if(k!=1&&k%2){
                p[k-1].x=(p[k-2].x+p[k].x)/2.0;
                p[k-1].y=(p[k-2].y+p[k].y)/2.0;
            }
            k+=2;
        }
        p[k-1].x=(p[1].x+p[k-2].x)/2.0;
        p[k-1].y=(p[1].y+p[k-2].y)/2.0;
        bool flag=0;
        for(int i=1;i<=n;i++){
            double x1=p[i].x-p[i+n].x;
            double y1=p[i].y-p[i+n].y;
            int j,k;
            k=i-1;
            j=i+1;
            for(;j<=i+n;j++,k--){
                if(k<=0) k=2*n;
                double x2=p[j].x-p[k].x;
                double y2=p[j].y-p[k].y;
                if(x1*x2+y1*y2!=0)
                    break;
                if(cal_dis(i,j)!=cal_dis(i,k))
                    break;
            }
            if(j>i+n){
                flag=1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
