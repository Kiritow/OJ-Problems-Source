/*
作者:千里冰封
题目:p2989 寻找somebody
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    int a, b, k, i, j, m;
    scanf("%i%i%i", &a, &b, &k);
    for(i = 0; i < a; i++)
        for(j = 0; j < b; j++){
            scanf("%i", &m);
            if(m == k) {
                printf("%i %i", ++i, ++j);
                return 0;
            }
        }
    printf("biantai");
    return 0;
}
