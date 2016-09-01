#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
double eps = 1e-8;
bool cal(double n){
    if(1-n < eps)
        return true;
    int inter;
    double now, org = n;
    while(1){
        inter = n * 3;
        if(inter == 1)
            return false;
        n = n * 3 - inter;
        if(fabs(org - n) < eps)
            break; 
    }
    return true;
}
int main()
{
    double n;
    char temp[10];
    while(scanf("%s", temp) != EOF && temp[0] != 'E'){
        sscanf(temp, "%lf", &n);
        if(cal(n))
            puts("MEMBER");
        else
            puts("NON-MEMBER");
    }
    return 0;
}
