#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct BigNum{
    int a[10100];
    int n;
    void input(char str[]){
        n = strlen(str);
        for(int i = 0;i < n;i++)
            a[i] = str[n-1-i]-'0';
    }
    bool operator <(const BigNum &b)const{
        if(n < b.n)return true;
        if(n > b.n)return false;
        for(int i = n-1;i >= 0;i--){
            if(a[i] < b.a[i])return true;
            if(a[i] > b.a[i])return false;
        }
        return true;
    }
    BigNum operator -(const BigNum &b)const{
        BigNum ret;
        ret.n = n;
        int mu = 0;
        for(int i = 0;i < n;i++){
            int tmp;
            if(i < b.n)tmp = a[i] - b.a[i] - mu;
            else tmp = a[i] - mu;
            if(tmp >= 0){
                mu = 0;
                ret.a[i] = tmp;
            }
            else {
                mu = 1;
                ret.a[i] = tmp+2;
            }
        }
        while(ret.n > 0 && ret.a[ret.n-1] == 0)ret.n--;
        return ret;
    }
    BigNum div2(){
        BigNum ret;
        ret.n = n-1;
        for(int i = 0;i < n-1;i++)
            ret.a[i] = a[i+1];
        return ret;
    }
    void output(){
        for(int i = n-1;i >= 0;i--)
            printf("%d",a[i]);
    }
};
void gcd(BigNum a,BigNum b){
    int c2 = 0;
    while(a.n && b.n){
        if(a.a[0]){
            if(b.a[0]){
                if(b < a)a = a-b;
                else b = b-a;
            }
            else b = b.div2();
        }
        else {
            if(b.a[0])a = a.div2();
            else{
                a = a.div2();
                b = b.div2();
                c2++;
            }
        }
    }
    if(a.n)a.output();
    else b.output();
    while(c2--){
        printf("0");
    }
    printf("\n");
}
char str[10010];
BigNum a,b,c;
int main()
{
    int T;
    scanf("%d",&T);
    int iCase = 0;
    while(T--){
        iCase++;
        scanf("%s",str);
        a.input(str);
        scanf("%s",str);
        b.input(str);
        printf("Case #%d: ",iCase);
        gcd(a,b);
    }
    return 0;
}
