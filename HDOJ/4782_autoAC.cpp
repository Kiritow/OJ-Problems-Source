#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10005;
char buf[maxn];
int len;
char ch;
void skip(){
    while(ch == ' ' || ch == '\t' || ch == '\n') ch = getchar();
}
void readTag(){
    len = 0;
    ch = getchar();
    while(ch!='>'){
        buf[len++] = ch;
        ch = getchar();
    }        
    buf[len] = 0;
}
void readString(){
    len = 0;
    while(ch != ' ' && ch != '\t' && ch != '\n'  && ch != '<'){
        buf[len++] = ch;
        ch = getchar();
    }
    buf[len] = 0;
}
void solve(){
    ch = ' ';
    int dep = 0;
    while(1){
        skip();
        if(ch == '<'){
            readTag();
            if(buf[len-1] == '/'){ 
                for(int i = 0; i < dep; i++) putchar(' ');
            }
            else if(buf[0] == '/') { 
                dep--;
                for(int i = 0; i < dep; i++) putchar(' ');
            }
            else{ 
                for(int i = 0; i < dep; i++) putchar(' ');
                 dep++;
            }
            printf("<%s>\n", buf);
            if(strcmp(buf, "/html") == 0)
                break;
            ch = getchar();
        }else{
            readString();
            for(int i = 0; i < dep; i++) putchar(' ');
            printf("%s", buf);
            skip();
            while( ch != '<' ){
                readString();
                printf(" %s", buf);
                skip();
            }
            puts("");
        }
    }
}
int main(){
    int t, cas = 1;
    scanf("%d", &t);
    while(t--) {
        printf("Case #%d:\n", cas++);
        solve();
    }
    return 0;
}
