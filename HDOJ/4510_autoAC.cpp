#include<stdio.h>
int main(){
    int h,m,s,a,b,c,T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%*c%d%*c%d",&h,&m,&s);
        scanf("%d%*c%d%*c%d",&a,&b,&c);
        a=a%12;
        s=s-c;
        if(s<0) {
            s+=60;
            m--;
            if(m<0){
                m+=60;
                h--;
                if(h<0) h+=12;
            }
        }
        m-=b;
        if(m<0){
                m+=60;
                h--;
                if(h<0) h+=12;
        }
        h=(h-a+12)%12;
        if(h<10) printf("0%d:",h);
        else printf("%d:",h);
        if(m<10) printf("0%d:",m);
        else printf("%d:",m);
        if(s<10) printf("0%d\n",s);
        else printf("%d\n",s);
    }
    return 0; 
}
