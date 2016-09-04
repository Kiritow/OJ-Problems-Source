#include<stdio.h>
#include<string.h>
char map[33] = {'P' , 'Q' , 'W' , 'E' , 'R' , 'T' , 'Y' , 'U' , 'I' , 'O' , 'J' , '#' , 'S' , 'Z' , 'K' , '*' , '?' , 'F' , '@' , 'D' , '!' , 'H' , 'N' , 'M' , '&' , 'L' , 'X' , 'G' , 'A','B','C','V'};
char a[3] , b[3];
int n , num;
double ans;
char tans[10000];
char str[30];
void f(char t){
    int d = 4;
    for(int i = 0 ; i < 32 ; i ++){
        if(t == map[i]){
            while(i != 0){
                str[d --] = i % 2 + '0';
                i /= 2;
            }
            break;
        }
    }
    while(d >= 0){
        str[d --] = '0';
    }
    return ;
}
void ff(int t){
    int d = 15;
    while(t != 0){
        str[d --] = t % 2 + '0';
        t /= 2;
    }
    while(d >= 5){
        str[d --] = '0';
    }
    return ;
}
void fff(char t){
    if(t == 'F') str[16] = '0';
    if(t == 'D') str[16] = '1';
}
int main(){
    scanf("%d" , &n);
        for(int i = 1 ; i <= n ; i ++){
            ans = 0;
            double c = 0.5;
            scanf("%*d%s%d%s" , a , &num , b);
            f(a[0]);
            ff(num);
            fff(b[0]);
            str[17] = '\0';
            printf("%d " , i);
            if(str[0] == '0'){
                for(int i = 1 ; i < 17 ; i ++){
                    ans += (str[i] - '0') * c;
                    c /= 2;
                }
                sprintf(tans , "%.16lf" , ans);
            }
            else{
                for(int i = 1 ; i < 17 ; i ++){
                    ans += (str[i] - '0') * c;
                    c /= 2;
                }
                ans += -1.0;
                sprintf(tans , "%.16lf" , ans);
            }
            if(ans == 0.0){
                printf("0.0\n");
            }
            else if(ans == -1.0){
                printf("-1.0\n");
            }
            else{
                int di;
                for(di = strlen(tans) - 1 ; di >= 0 ; di --){
                    if(tans[di] != '0') break;
                }
                tans[di + 1] = '\0';
                printf("%s" , tans);
                printf("\n");
            }
        }
    return 0;
}
