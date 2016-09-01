#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int main()
{
    int t;
    double s, ax, bx, ay, by;
    double a, b, c, p, ans1, ans2;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%lf%lf%lf%lf%lf", &s, &ax, &bx, &ay, &by);
        a = (ax - ay) / 2;
        b = bx - by;
        c = s;
        if(fabs(a) < eps)    
        {
            if(b > eps)               
            {
                printf("Good driver,Jiaoshou!\n");
            }
            else if(fabs(b) < eps)    
            {
                printf("Good driver,Jiaoshou!\n");
            }
            else                    
            {
                printf("Oh,God!Jiaoshou will be catched after %.3f minutes.\n", -s / b);
            }
        }
        else{                 
            p = b * b - 4 * a * c;
            if(p < -eps)            
            {
                printf("Good driver,Jiaoshou!\n");
            }
            else                    
            {
                ans1 = (-b - sqrt(p)) / (2 * a);
                ans2 = (-b + sqrt(p)) / (2 * a);
                if(ans1 < 0 && ans2 < 0)
                {
                    printf("Good driver,Jiaoshou!\n");
                }
                else if(ans1 > 0)
                {
                    printf("Oh,God!Jiaoshou will be catched after %.3f minutes.\n", ans1);
                }
                else
                {
                    printf("Oh,God!Jiaoshou will be catched after %.3f minutes.\n", ans2);
                }
            }
        }
    }
    return 0;
}
