/*
    时间:2016.2.2
    题号:VJ P1010
    方法：重载运算符，注意小数点的操作
*/
#include<iostream>
#include<cstring> 
using namespace std;
const int N = 250 * 6;
char ans[11][N];
class A
{    public:
        A operator*(A &b);        //重载运算符
        int get();                //将字符串转化为整数数组。
        void print(int n);        //将结果保存到字符串ans
    private:
        int num[N] = {0}, len, point;
};
int A::get()
{    char c[7]; int i; bool flag = false;
    if(!(cin >> c)) return 0;
    len = strlen(c) - 1;
    for(i = 0;i < len;i++) {
         if(c[i] != '.' && !flag) num[len-i-1] = c[i] - '0';
         if(c[i] == '.'){ flag = true;point = len - i; }
         if(flag) num[len-i-1] = c[i+1] - '0'; }
    return 1;
}
A A::operator*(A &b)
{    int i, j, k = 0;
    A res;
    for(i = 0;i < len;i++) {
      for(j = 0;j < b.len;j++) {
        res.num[i+j] = res.num[i+j] + num[i] * b.num[j] + k;
        k = res.num[i+j] / 10;res.num[i+j] %= 10; }
      if(k != 0) res.num[i+j] = k;k = 0; 
    }
    res.len = len + b.len;
    while(res.num[res.len] == 0 && res.len > point+b.point) res.len--;
    res.len++;res.point = point + b.point;
    return res;
}
void A::print(int n)
{    int i = len - 1, j = 0, k = 0; bool flag = false;
    while(num[j] == 0 && j < point) j++;
    if(num[len-1] == 0 && j == i) { ans[n][k] = 0 + '0';return ; }
    if(i == point && num[i] == 0){ ans[n][k] = '.';k++;i--;flag = true; }
    for(;i >= j;i--)
        if(i == point - 1 && !flag)
            { ans[n][k] = '.';k++;ans[n][k] = num[i] + '0';k++; }
        else { ans[n][k] = num[i] + '0';k++; }
}
int main()
{    int n, j = 0; A a;
    while(a.get() && cin >> n)
     { A b = a;
       for(int i = 0;i < n-1;i++) b = a * b;
       b.print(j);j++; }
    for(int i = 0;i < j;i++) cout << ans[i] << endl;
    return 0;
}
