#include<stdio.h>
int a[1000],b[1000],c[1000];
int main(){
    int t,n,i,j,k,a0,b0,c0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<5){
            if(n==3) printf("6\n1 2\n5 3 4\n");
            else printf("9\n5 4\n1 3\n8 2 6 7\n");
            continue;
        }
        if(n&1){
            i=3*(n-2);
            a0=b0=c0=0;
            while(i>0){
                c[c0++]=i--;
                b[b0++]=i--;
                a[a0++]=i--;
                if(i<=0) break;
                a[a0++]=i--;
                b[b0++]=i--;
                c[c0++]=i--;
            }
        }
        else{
            i=3*(n-2);
            c[0]=2;c[1]=6;
            b[0]=3;b[1]=4;
            a[0]=1;a[1]=5;
            a0=b0=c0=2;
            while(i>6){
                c[c0++]=i--;
                b[b0++]=i--;
                a[a0++]=i--;
                a[a0++]=i--;
                b[b0++]=i--;
                c[c0++]=i--;
            }
        }
        printf("%d\n",3*(n-1));
        for(i=0;i<a0;i++) printf("%d %d\n",a[i],b[i]);
        printf("%d",3*(n-1)-1);
        for(i=0;i<c0;++i) printf(" %d",c[i]);
        printf(" %d\n",3*(n-1)-2);
    }
    return 0;
}
