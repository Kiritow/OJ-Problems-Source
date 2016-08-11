#include<stdio.h>

int main(int argc, char* argv[]){
    long min = 999999999,max = -min;
    long cnt;
    scanf("%li", &cnt);
    while(cnt--){
        auto long i;
        scanf("%li", &i);
        min = i >= min ? min : i;
        max = i <= max ? max : i;
    }
    printf("%li %li", min, max);
    // while(1);
    return 0;
}
