#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n; 
    double d; 
    char* time = new char[8];
    scanf("%d%lf", &n, &d);
    int num; 
    while(scanf("%d", &num) != EOF)
    {
        int sec = 0; 
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", time);
            if(time[0] == '-')
            {
                flag = 1;
            }
            else
            {
                sec += (time[0] - '0') * 3600 + ((time[2] - '0') * 10 + time[3] - '0') * 60 + (time[5] - '0') * 10 + time[6] - '0';
            }
        }
        if(flag == 0)
        {
            sec = int(sec * 1.0 / d + 0.5);
            int minute = sec / 60; 
            int second = sec % 60; 
            printf("%3d: %d:", num, minute);
            if(second < 10)
                printf("0");
            printf("%d min/km\n", second);
        }
        else
        {
            printf("%3d: -\n", num);
        }
    }
    return 0;
}
