/*
作者:千里冰封
题目:p1475 m进制转十进制
*/

#include <stdio.h>
#include <string.h>

int get(int a){
    return a >= 'A' && a <= 'Z' ? a - 'A' + 10 : a - '0';
}

int main(int argc, char* argv[]) {
    int b, i, j, out = 0;
    char a[100];
    scanf("%s%i", a, &b);
    for(i = 1, j = strlen(a) - 1; j >= 0; i *= b, j--)
        out += get(a[j]) * i;
    printf("%i",out);
    if(argc > 1) for(;;);
    return 0;
}
