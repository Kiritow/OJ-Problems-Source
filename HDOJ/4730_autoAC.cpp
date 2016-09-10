#include <stdio.h>
#include <string.h>
int main() {
    char a[120];
    int t, tt = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", a);
        printf("Case #%d: ", ++tt);
        int len = strlen(a);
        if(a[len-1] == 'u' && a[len-2] == 's' && a[len-3] == 'e' && a[len-4] == 'd' &&
           a[len-5] == 'o' && a[len-6] == 'n' && a[len-7] == 'a' && a[len-8] == 'n') {
            printf("%s", a);
        }
        else if(a[len-1] == 'u' && a[len-2] == 's' && a[len-3] == 'e' && a[len-4] == 'd') {
            for(int i=0; i<len-4; i++) {
                printf("%c", a[i]);
            }
            printf("nanodesu\n");
        }
        else {
            printf("%s", a);
            printf("nanodesu\n");
        }
    }
    return 0;
}
