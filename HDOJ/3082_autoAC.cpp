#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char buf[120];
        int n; 
        cin >> n;
        int dz[22];
        for(int j = 0; j < n; j++)
        {
            int cnt = 0;
            int a=0, sum = 0;
            getchar();
            gets(buf);
            int len = strlen(buf);
            for(int i = 0; i < len; i++)
            {
                if(isdigit(buf[i]))
                {
                    a  = a * 10 + buf[i] - '0';
                }
                else
                {
                    sum += a;
                    a  = 0;
                }
            }
            dz[j] = sum;
        }
        double result = 0;
        for(int i = 0 ; i < n; i++)
        {
            result += 1.0 / dz[i];
        }
        result = 1.0 / result;
        printf("%.2lf\n", result);
    }
    return 0;
}
