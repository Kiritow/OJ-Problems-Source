#include <math.h>
#include<stdio.h>
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF&&x){
        float s;
        int b,n,c,i,j,d,l,a[20000],sp;
        x*=5;
        s=0;n=1;
        while (s<=x+10){
            s=s+log10((2*n+1)/(1.0*n));
            n++;
        }
        for(i=0;i<=x+5;i++) a[i]=0;
        for(c=1,j=n;j>=1;j--){
            d=2*j+1;
            for(i=0;i<=x+4;i++){
                a[i]=c/d;
                c=(c%d)*10+a[i+1];
            }
            a[x+5]=c/d;
            for(b=0,i=x+5;i>=0;i--){
                a[i]=a[i]*j+b;
                b=a[i]/10;
                a[i]=a[i]%10;
            }
            a[0]=a[0]+1;c=a[0];
        }
        for(b=0,i=x+5;i>=0;i--){
            a[i]=a[i]*2+b;
            b=a[i]/10;
            a[i]=a[i]%10;
        }
        puts("3.");
        printf(" ");
        for(i=1,sp=0;i<=x;++i){
            printf("%d",a[i]);
            if(i%5==0) {
                sp+=1;
                if(i!=x&&(!sp||sp%10!=0)) printf(" ");
            }
            if(sp&&sp%10==0){
                sp=0;
                if(i!=x)puts("");
                if(i!=x) printf(" ");
            }
        }
        puts("");
    }
}
