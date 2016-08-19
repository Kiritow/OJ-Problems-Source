#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char s[10005];
int cur, len;
double solve(){
    double c = 1;
    while(!(s[cur] == '(' || s[cur] >= '0' && s[cur] <= '9' || s[cur] == '-') && cur < len)
        cur++;
    if(s[cur] == '-')
        c = -1, cur++;
    if(s[cur] == '('){
        double w = 0.1, p = 0;
        if(s[++cur] == '.' || s[cur+1] == '.'){
            if(s[cur+1] == '.')
                cur++;
            for(int i = cur + 1; s[i] >= '0' && s[i] <= '9' && s[i]; i++, cur = i)
                p = p + (s[i] - '0') * w, w *= 0.1;
        }
        else
            p = s[cur++] - '0';
        double a, b;
        a = solve();
        b = solve();
        return (a+b)*p + (a-b) * (1-p);
    }
    else{
        double p = 0;
        for(int i = cur; s[i] >= '0' && s[i] <= '9'; i++, cur=i)
            p = p * 10 + (s[i]-'0');
        return c * p;
    }
} 
int main()
{
    double p, a, b;
    while(gets(s)&& strcmp(s, "()"))
    {
        len = strlen(s);
        cur = 0; 
        printf("%.2lf\n", solve());
    }
    return 0;
}
