#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define NUM 500
#define MAX_LEN 110
class BigInteger{
    int d[MAX_LEN];
    int len;
public:
    BigInteger(){
        memset( d, 0, sizeof(d));
        len = 0; 
    }
    void set(char *str){
        len = strlen(str);
        for(int i = 0, j = len - 1; i < len; i++, j-- ){
            d[i] = str[j] - '0';
        }
    }
    BigInteger operator+(const BigInteger &other)const{
        BigInteger ret;
        ret.len = max( len, other.len );
        for(int i = 0; i < ret.len; i++ ){
            ret.d[i] = d[i] + other.d[i];
        }
        for(int i = 0; i < ret.len; i++ ){
            if(ret.d[i] > 9){
                ret.d[i] -= 10;
                ret.d[i + 1]++;
            }
        }
        if(ret.d[ret.len] > 0)
            ret.len ++;
        return ret;
    }
    bool operator<=(const BigInteger &other)const{
        if(len < other.len)
            return true;
        if(len == other.len){
            int i = len - 1;
            while(i >= 0 && d[i] == other.d[i])
                i--;
            if(i == -1 || d[i] <= other.d[i])
                return true;
        }
        return false;
    }
};
BigInteger fibo[NUM], a, b;
char stra[MAX_LEN], strb[MAX_LEN];
void init(){
    fibo[0].set("1"); fibo[1].set("2");
    for(int i = 2; i < NUM; i++ )
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}
bool input(){
    scanf("%s%s", stra, strb );
    if(stra[0] == '0' && strb[0] == '0')
        return false;
    a.set(stra); b.set(strb);
    return true;
}
void output(){
    int l, r;
    for( l = 0; l < NUM; l++ ){
        if(a <= fibo[l])
            break;
    }
    for( r = NUM - 1; r > 0; r-- ){
        if(fibo[r] <= b)
            break;
    }
    printf("%d\n", r - l + 1 );
}
int main(){
    init();
    while(input()){
        output();
    }
    return 0;
}
