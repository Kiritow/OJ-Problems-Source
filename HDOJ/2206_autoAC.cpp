#include <stdio.h>
char str[102];
int ok;
int check(char ch){ 
    if(ch >= '0' && ch <= '9') return 1;
    if(ch == '.') return 2;
    return 0;
}
int main(){
    int dot, dignum, a, dotsum;
    while(gets(str)){
        dotsum = a = dot = dignum = 0;
        for(int i = 0; str[i]; ++i){
            ok = check(str[i]);
            if(!ok) break;
            if(ok == 1){
                dot = 0;
                ++dignum;
                a = a * 10 + str[i] - '0';
                if(dignum > 3 || a > 255){
                    ok = 0; break;
                }
            }else{
                dignum = a = 0;
                ++dot; ++dotsum;
                if(dot > 1 || dotsum > 3){
                    ok = 0; break;
                }
            }
        }
        if(dot || dotsum != 3) ok = 0; 
        printf(ok ? "YES\n" : "NO\n");
    }
    return 0;
}
