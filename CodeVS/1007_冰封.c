/*
作者:千里冰封
题目:p1007 级数求和
我特么再也不相信float了
*/

#include <stdio.h>

int main(){
    int a, i;
    double b = 0.0;
    scanf("%i", &a);
    for(i = 1; b < a; i++){
        b += 1.0 / i;
		    if(b >= a)
			      break;
    }
    printf("%i", i);
    return 0;
}
