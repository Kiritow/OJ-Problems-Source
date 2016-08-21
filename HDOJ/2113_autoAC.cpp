#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    __int64 num;
    int k = 0;
    int sum;
    int yu;
    while(scanf("%I64d", &num) != EOF)
    {
        if(k)
            cout << endl;
        else
            k = 1;
        sum = 0;
        while(num)
        {
            yu = num % 10;
            if(!(yu % 2))
            {
                sum += yu;
            }
            num /= 10;
        }
        cout << sum << endl;
    }
    return 0;
}
