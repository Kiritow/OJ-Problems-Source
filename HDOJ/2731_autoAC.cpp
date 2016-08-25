#include<iostream>
using namespace std;
int main()
{
    int cases, x = 1;
    cin>>cases;
    while (cases--) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", x++, a, b, c, d);
        int i;
        a %= b;
        for (i = 0; i <= d; ++i) {
            a *= 7;
            if (i >= c) {
                printf("%d", a / b);
            }
            a %= b;
        }
        printf("\n");
    }
    return 0;
}
