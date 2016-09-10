#include <cstdio>  
#include <cstring>  
#include <map>  
using namespace std;  
typedef int ll;  
const int N = 20005;  
int t, n, v, x;  
char str[N];  
map<int, int> has;  
int main() {  
    scanf("%d", &t);  
    while (t--) {  
    scanf("%s", str);  
    v = -1;  
    n = strlen(str);  
    for (int i = 0; i < n; i++) {  
        if (str[i] == '?') {  
        v = i;  
        break;  
        }  
    }  
    int ans = 0;  
    if (v == -1) {  
        x = 0;  
        has.clear();  
        has[0]++;  
        for (int i = 0; i < n; i++) {  
        x ^= (1<<(str[i] - 'a'));  
        ans += has[x];  
        has[x]++;  
        }  
        printf("%d\n", ans);  
        continue;  
    }  
    else {  
        has.clear();  
        ans = 0;  
        x = 0;  
        has[0]++;  
        for (int i = 0; i < v; i++) {  
        x ^= (1<<(str[i] - 'a'));  
        ans += has[x];  
        has[x]++;  
        }  
        has.clear();  
        x = 0;  
        has[0]++;  
        for (int i = v + 1; i < n; i++) {  
        x ^= (1<<(str[i] - 'a'));  
        ans += has[x];  
        has[x]++;  
        }  
        has.clear();  
        x = 0;  
        has[0]++;  
        for (int i = v + 1; i < n; i++) {  
        x ^= (1<<(str[i] - 'a'));  
        has[x]++;  
        }  
        x = 0;  
        if (has.count(x))  
        ans += has[x];  
        for (int j = 0; j < 26; j++) {  
        if (has.count(x^(1<<j)))  
            ans += has[x^(1<<j)];  
        }  
        for (int i = v - 1; i >= 0; i--) {  
        x ^= (1<<(str[i] - 'a'));  
        if (has.count(x))  
            ans += has[x];  
        for (int j = 0; j < 26; j++) {  
            if (has.count(x^(1<<j))) {  
            ans += has[x^(1<<j)];  
            }  
        }  
        }  
    }  
    printf("%d\n", ans);  
    }  
    return 0;  
}
