#include <stdio.h>
#include <math.h>
int main(){
    int i, n, m, c = 1, flag;
    while(scanf("%d", &n), n > 0){
        m = sqrt(n);
        for(i = 2; i <= m + 1; i++){
            if(n % i == 0){flag = 0; break;}
            else flag = 1;
        }
        if(n == 1) flag = 0;
        if(flag) printf("%d: yes\n", c++);
        else printf("%d: no\n", c++);
    }
    return 0;
}
