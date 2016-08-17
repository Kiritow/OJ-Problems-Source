#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double a,b;
    double x,y;
    int n;
    cin >> n;
    while(n--&&cin >> a >> b >> x >> y)
    {
        y = y>0?y:-y;
        double f = y/x;
        double newx = sqrt(a*a*b*b/(b*b + f*f*a*a));
        double newy = f*newx;
        newx = newx/a*b;
        newy /= b;
        newx /= b;
        double t = acos(newx);
        double area = t * b * a / 2;
        cout << fixed << setprecision(2) << area << endl;
    }
}
