#include <stdio.h>

int tot;

int main(int argc, char* argv[]){
    scanf("%i", &tot);
    if(tot < 0) {
        printf("120");
        return 0;
    }
    tot %= 5;
    switch( tot ){
        case 1:
        case 4:
            printf("0");
            break;
        case 3:
            printf("1");
            break;
        default:
            printf("-1");
            break;
    }
    return 0;
}
