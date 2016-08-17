# include<stdio.h>
# define inf 1000000007
const double eps=1e-8;
__int64 a[100005];
void init(){
    int i;
    for(i=0;i<=313;i++)
        a[i] = 1;
    for(i=314;i<=100000;i++){
        a[i]= a[i-100] + a[i-314];
        a[i]=a[i]%inf;
    }
}
int main(){
    int T,y,i;
    double x;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%lf",&x);
        if(x<0)
            printf("0\n");
        else if(x<1)
            printf("1\n");
        else
        {
            x=x*100;
            y=(int)(x+eps);
                printf("%I64d\n",a[y]);
        }
    }
    return 0;
}
