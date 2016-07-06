/*
作者:千里冰封
题目:p1023 GPA计算
*/

#include <stdio.h>

int main(int argc, char* argv[]){
    int a, i,c = 0, m = 0;
    float n = 0.0, tol = 0.0;
    scanf("%i", &a);
    for(i = 0; i < a; i++){
        scanf("%i%f", &m, &n);
        tol += m * n;
        c += m;
    }
    printf("%.2f", tol / c);
    return 0;
}
