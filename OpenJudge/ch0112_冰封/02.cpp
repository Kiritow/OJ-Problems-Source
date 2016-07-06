#include<stdio.h>
#include<iostream>
using namespace std;

    int a[10000];
    int fuck,shit = 0;

void fuckYou(int fa){
     if(fa<=0) return;

     shit += 1;

     fa -= 70;

     fuckYou(fa);
}
int main(void){
    scanf("%d",&fuck);

    for(int i = 0; i < fuck; i++){
        scanf("%d",&a[i]);
        fuckYou(a[i]);
    }
    printf("%.1f",shit/10.0);
    return 0;
}