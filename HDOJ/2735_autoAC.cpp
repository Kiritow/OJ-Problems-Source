#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    char str[100];
    while(scanf("%s", str)&&str[0]!='#'){
        int flag=1, ans=0, len=strlen(str), t=0, i;
        for(i=0; i<len; i++){
            switch(str[i]){
                case '/':if(flag)ans+=100;flag=0;break;
                case '\\':t=100;break;
                case '.':ans+=t+100;t=0;flag=1;break;
                case '_':break;
                case '|':if(flag)ans+=50;flag=0;t=50;break;
            }
        }
        printf("%d\n", (ans+t)/len);
    }
    return 0;
}
