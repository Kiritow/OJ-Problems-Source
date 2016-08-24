#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double pin[15];
bool judge()
{
    if(fabs(pin[14] - 5)  < 1e-16 && (pin[7] >= 0 && pin[7] <= 0.8))
        return true;
    else
        return false;
}
bool gaodi(double a)
{
    int temp;
    if(a >= 0.0 && a <= 0.8)
        return 0; //low
    else
            return 1; //high
}
char cal(double a, double b)
{
    if(gaodi(a) && gaodi(b))
        return 'L';
    else
        return 'H';
}
int main()
{
    int n;
    int a;
    double dianya;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= 14; ++i)
            pin[i] = -1.0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%lf", &a, &dianya);
            pin[a] = dianya;
        }
        if(!judge())
        {
            printf("No\n");
            continue;
        }
        else
        {
            printf("Yes\n");
            if(pin[1] != -1 && pin[2] != -1)
            {
                printf("3 %c\n", cal(pin[1], pin[2]));
            }
            if(pin[4] != -1 && pin[5] != -1)
            {
                printf("6 %c\n", cal(pin[4], pin[5]));
            }
            if(pin[9] != -1 && pin[10] != -1)
            {
                printf("8 %c\n", cal(pin[9], pin[10]));
            }
            if(pin[12] != -1 && pin[13] != -1)
            {
                printf("11 %c\n", cal(pin[12], pin[13]));
            }
        }
    }
    return 0;
}
