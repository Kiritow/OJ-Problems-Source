#include<cstdio>
int main(){
    int a,e,f,c,b;
    while(~scanf("%d%d%d",&e,&f,&c)){
        for(a=e+f,b=0;a>=c;a=a%c+a/c)
            b+=a/c;
        printf("%d\n",b);
    }
}
