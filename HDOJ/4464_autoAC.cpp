#include <stdio.h>
#include <string.h>
int main() {
    int n, t = 0;
    while(scanf("%d", &n)!=EOF) {
        int maxx = 0;
        while(n--) {
            int i, tmp = 0;
            char s[105];
            scanf("%s", s);
            for(i = 0; s[i]; i++) 
                tmp += s[i];
            if(tmp > maxx)
                maxx = tmp;
        }
        printf("Case %d: %d\n", ++t, maxx);
    }
    return 0;
}
