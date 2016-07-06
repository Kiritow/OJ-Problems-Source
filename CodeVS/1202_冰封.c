/*
作者:千里冰封
题目:p1202 求和
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    int a, b = 0;
    scanf("%i", &a);
    while(a--){
		int l;
		scanf("%i", &l);
		b += l;
    }
    printf("%i", b);
    return 0;
}
