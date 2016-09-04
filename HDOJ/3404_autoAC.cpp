#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2000000
using namespace std;
int m[2][2]={0,0,0,1};
int Nim_Mult_Power(int x,int y){
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int m=1<<(1<<a);
    int p=x/m,s=y/m,t=y%m;
    int d1=Nim_Mult_Power(p,s);
    int d2=Nim_Mult_Power(p,t);
    return (m*(d1^d2))^Nim_Mult_Power(m/2,d1);
}
int Nim_Mult(int x,int y){
    if(x<y)
        return Nim_Mult(y,x);
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int m=1<<(1<<a);
    int p=x/m,q=x%m,s=y/m,t=y%m;
    int c1=Nim_Mult(p,s),c2=Nim_Mult(p,t)^Nim_Mult(q,s),c3=Nim_Mult(q,t);
    return (m*(c1^c2))^c3^Nim_Mult_Power(m/2,c1);
}
int main(){
    int t,n,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ret=0;
        while(n--){
            scanf("%d%d",&x,&y);
            ret^=Nim_Mult(x,y);
        }
        if(ret)
            puts("Have a try, lxhgww.");
        else
            puts("Don't waste your time.");
    }
    return 0;
}
