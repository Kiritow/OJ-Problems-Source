#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#define M 502
using namespace std;
double p[M][M][2];
int d[]={5,20,1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5,20};
int cal(int a,int b){ return a>=b?a-b:a;}
int main()
{
    int n,m;
    for(n=0;n<M;n++){
        p[0][n][0]=1;
        p[n][0][1]=1;
    }
    for(n=1;n<M;n++)
    for(m=1;m<M;m++){
        if(n<=20) p[n][m][0]=n/20.0;
        if(m<=20) p[n][m][1]=m/3.0;
        for(int k=0;k<90;k++){
            double a=0;
            for(int i=1;i<=20;i++)
                a+=p[cal(n,d[i])][m][1];
            p[n][m][0]=1-a/20.0;
            double b=1e300;
            for(int i=1;i<=20;i++){
                double c=0;
                for(int j=-1;j<=1;j++)
                    c+=p[n][cal(m,d[i+j])][0];
                c/=3.0;
                if(b>c) b=c;
            }
            p[n][m][1]=1-b;
            if(n>20) break;
        }
    }
    while(scanf("%d",&n)&&n){
        printf("%.12lf %.12lf\n",p[n][n][0],p[n][n][1]);
    }
    return 0;
}
