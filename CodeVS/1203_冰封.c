/*
作者:千里冰封
题目:p1203 判断浮点数是否相等
*/
#include <stdio.h>

int main(int argc, char* argv[]) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    double s = a > b ? a - b : b - a;
    printf("%s", s <= 0.00001 ? "yes" : "no");
    return 0;
}
