#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<cctype>
#include<assert.h>
#include<stack>
#include<queue>
#include<vector>
#include<list>
using namespace std;
double pi=acos(-1);
double w,r,sita;
int main() {
    while(~scanf("%lf%lf%lf",&r,&w,&sita))
    {
        sita/=180.;
        sita*=pi;
        double umc=cos(sita/2.)-1.;
        r-=w/umc;
        printf("%.3f\n",r);
    }
    return 0;
}
