#include<stdio.h>
#include<stdlib.h>
int main(void){
    int a,b,c;
    int i,j;
    char d;
    scanf("%d %d %c %d",&a,&b,&d,&c);
    for(i = 0;i < a;i++){
        for(j = 0;j < b;j++){
            if((c == 1)||(i == 0)||(i == a-1)||(j == 0)||(j == b-1)){
                putchar(d);
            }
            else{
                putchar(' ');
            }
        }
    putchar('\n');
    }
//    system("pause");
    return 0;
}
