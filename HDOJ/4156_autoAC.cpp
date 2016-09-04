#include <cstdio>
int main(){
    for(int a,b,c,t;scanf("%d%d%d",&a,&b,&c)&&(a||b||c);){
        if(a<b)t=a,a=b,b=t;
        if(a<c)t=a,a=c,c=t;
        printf("%s\n",(a+b>c)&&(a+c>b)&&(b+c>a)&&a*a==b*b+c*c?"right":"wrong");
    }
}
