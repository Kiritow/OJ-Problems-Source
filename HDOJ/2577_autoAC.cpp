#include<iostream>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while(T--){
        char s[2000];
        gets(s);
        int result = strlen(s), i, len;
        len = result;
        int lian_xu = 0;
        for(i = 0; i < len; ++i){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                if(lian_xu < 2){
                    result++;
                }
                lian_xu++;
            }
            else{
                if(i+1 < len && lian_xu >= 2 ){
                    if(s[i+1] >= 'a' && s[i+1] <= 'z'){
                        lian_xu = 0;
                    }
                    else{
                        result++;
                    }
                }
                else lian_xu = 0;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
