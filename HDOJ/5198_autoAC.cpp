#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int nn,num;
int main(){
    char str[100];
    int i;
    while(~scanf("%s",str)){
        nn = 0;
        bool flag = true;
        int len = strlen(str);
        char tmp,a = 0,b = 0,c = 0;
        tmp = str[0];
        a = tmp;
        for(i =0;i < len;i++){
            if(tmp==str[i]){
                nn++;
            }
            else {
            tmp = str[i];
            b = tmp;
            break;
            }
        }
        if(nn*3!=len) flag = false;
        for(int k = i;i<k+nn;i++){
            if(str[i]!=tmp){
                flag = false;
                break;
            }
        }
        tmp = str[i];
        if(tmp == a||tmp == b) flag = false;
        for(int k = i;i<k+nn;i++){
            if(str[i]!=tmp){
                flag = false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
