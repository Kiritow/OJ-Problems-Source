#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int number[4];
char str[501];
int map[1001][1001];
int main()
{
    int i,j,k,sum,min_x,min_y,max_x,max_y;
    int length,mark,x,y,ans;
    while(gets(str))
    {
        memset(map,0,sizeof(map));
        length = strlen(str);
        ans = 0;
        for(i=0;i<length;i++)
        {
            if(str[i] == '(')
            {
                sum = 0;
                mark = 0;
                for(k=0,j=i+1;k<4;j++)
                {
                    if(str[j] >= '0' && str[j] <='9')
                    {
                        sum = sum*10 + str[j] - '0';
                        mark = 1;
                    }
                    else if(mark == 1 && str[j-1] >= '0' && str[j-1] <='9')
                    {
                        number[k++] = sum;
                        sum = 0;
                        mark = 0;
                    }
                }
                i = j;
                min_x = min(number[0],number[2]);
                max_x = max(number[0],number[2]);
                min_y = min(number[1],number[3]);
                max_y = max(number[1],number[3]);
                for(x = min_ ;x<max_x;x++)
                for(y = min_ ;y<max_y;y++)
                {
                    if(map[x][y] == 0)
                    {
                        map[x][y] = 1;
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
