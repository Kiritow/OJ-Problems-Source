#include <stdio.h>  
#include <string.h>  
char c;  
char a[5];  
int main() {  
    a[5] = '\0';  
    int ans = 0;  
    while ((c = getchar()) != EOF) {  
    if (c >= 'a' && c <= 'z') c -= 32;  
    a[3] = c;  
    if (strcmp(a, "DOGE") == 0) ans++;  
    for (int i = 0; i < 3; i++)  
        a[i] = a[i + 1];  
    }  
    printf("%d\n", ans);  
    return 0;  
}
