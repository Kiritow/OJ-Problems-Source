#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2005;
char str[maxn];
int main(){
    int cas=1;
    while(scanf("%s", str)&&str[0]!='-'){
        int i, ans=0, lef=0;
        for(i=0; str[i]!='\0'; i++){
            if(str[i]=='{'){
                lef++;
            }
            else if(lef>0){
                lef--;
            }
            else {
                ans++;lef++;
            }
        }
        printf("%d. %d\n", cas++, ans+lef/2);
    }
    return 0;
}
