#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int a[500];
int main(void){
    bool fuck = false;
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+N);
    for(int i = 0; i < N; i++){
        if(a[i]%2 == 1){
            if(fuck){
                printf(",%d",a[i]);
            }else{
                printf("%d",a[i]);
                fuck = true;
            }
        }
    }
   // system("PAUSE");
    return 0;
}