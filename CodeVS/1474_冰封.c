/*
作者:千里冰封
题目:p1474 十进制转m进制
*/

#include <stdio.h>

char get(int a){
    return a < 10 ? a + '0' : a - 10 + 'A';
}

int main(int argc, char* argv[]) {
    int a, b, i;
    char out[10000];
    scanf("%i%i", &a, &b);
    for(i = 0; a > 0; i++){
        out[i] = get(a % b);
        a /= b;
    }
    for(i--; i >= 0; i--)
        printf("%c", out[i]);
    if(argc > 1) for(;;);
    return 0;
}
