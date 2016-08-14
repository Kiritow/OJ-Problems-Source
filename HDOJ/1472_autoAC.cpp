#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
const double t = sqrt(2.0);
int main()
{
    string s;
    int icase = 1;
    while(cin >> s) {
        if(s == "END") {
            break;
        }
        int num = 0;
        double x = 0, y = 0;
        for(int i = 0; i < (int)s.length()-1; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num*10+(s[i]-'0');
            }
            else if(s[i] == ','){
                num = 0;
                continue;
            }
            else if(s[i] == 'N' && s[i+1] == 'E') {
                x+=num/t, y+=num/t, i++;
            }
            else if(s[i] == 'N' && s[i+1] == 'W') {
                x-=num/t, y+=num/t, i++;
            }
            else if(s[i] == 'S' && s[i+1] == 'E') {
                x+=num/t, y-=num/t, i++;
            }
            else if(s[i] == 'S' && s[i+1] == 'W') {
                x-=num/t, y-=num/t, i++;
            }
            else if(s[i] == 'N') {
                y+=num;
            }
            else if(s[i] == 'S') {
                y-=num;
            }
            else if(s[i] == 'E') {
                x+=num;
            }
            else if(s[i] == 'W') {
                x-=num;
            }
        }
        printf("Map #%d\n", icase++);
        printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
        printf("The distance to the treasure is %.3lf.\n\n", sqrt(x*x+y*y));
    }
    return 0;
}
