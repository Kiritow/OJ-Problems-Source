#include<stdio.h>

int main(int argc, char* argv[]){
    auto int last = 1;
    auto int next = 1;
    auto int cnt;
    scanf("%i", &cnt);
    if(cnt == 1 || cnt == 2){
        printf("1");
        return 0;
    }
    cnt--;
    cnt--;
    while(cnt--){
        auto int i = next;
        next += last;
        last = i; 
    }
    printf("%i", next);
    // while(1);
    return 0;
}
