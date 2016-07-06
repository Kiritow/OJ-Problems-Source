#include<stdio.h>

int a,i,m,n;
int b[20],cmin,cmax;

int main(void){
    int cc = 0; 
    scanf("%d",&a);
    scanf("%d %d",&m,&n);
    cc = (n*1000)/m;
    cmax = cc + 50;
    cmin = cc - 50;
    for(i = 0; i < a-1; i++){
        scanf("%d %d",&m,&n);
        b[i] = (n*1000)/m; 
    }
    
    for(i = 0; i < a-1; i++){
        if(b[i] > cmax) printf("better\n");
        else if(b[i] < cmin) printf("worse\n");
        else printf("same\n"); 
    }
    
//    getchar();getchar();getchar();getchar();getchar();getchar();getchar(); 
    return 0;
}
