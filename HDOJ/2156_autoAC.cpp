#include<stdio.h>
int main(){
    double m,j,i;
    while(scanf("%lf",&m)!=EOF&&m!=0){
        j=0;int k=1;
        for(i=m;i>=1;i--)
            j=j+1.00/i*k++;
        printf("%.2f\n",2*j-m);}
    return 0;
}
