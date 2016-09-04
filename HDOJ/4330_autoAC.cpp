#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
int getNumberOnce(char stage[10][10])
{
    bool remove[10][10];
    memset(remove, false, sizeof(remove));
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(i<6)
            {
                if(stage[i][j])
                {
                    if(stage[i][j] == stage[i+1][j])
                    {
                        if(stage[i][j] == stage[i+2][j])
                        {
                            remove[i][j] = true;
                            remove[i+1][j] = true;
                            remove[i+2][j] = true;
                        }
                    }
                }
            }
            if(j<6)
            {
                if(stage[i][j])
                {
                    if(stage[i][j] == stage[i][j+1])
                    {
                        if(stage[i][j] == stage[i][j+2])
                        {
                            remove[i][j] = true;
                            remove[i][j+1] = true;
                            remove[i][j+2] = true;
                        }
                    }
                }
            }
        }
    }
    int num = 0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(remove[i][j])
            {
                stage[i][j] = 0;
                ++ num;
            }
        }
    }
    return num;
}
void fallDown(char stage[10][10])
{
    for(int j=0;j<8;++j)
    {
        int k = 7;
        for(int i=7;i>=0;--i)
        {
            if(stage[i][j])
            {
                stage[k--][j] = stage[i][j];
            }
        }
        for(int i=k;i>=0;--i)
        {
            stage[i][j] = 0;
        }
    }
}
int getNumber(char stage[10][10])
{
    int num = 0;
    while(true)
    {
        int temp = getNumberOnce(stage);
        if(temp == 0)
        {
            break;
        }
        num += temp;
        fallDown(stage);
    }
    return num;
}
char stage[10][10];
bool simpleJudge()
{
    char temp[10][10];
    memcpy(temp, stage, sizeof(temp));
    return getNumber(temp) >= 8;
}
struct Point
{
    int x, y;
};
int getPow5(int x)
{
    int res = 1;
    while(x--)
    {
        res *= 5;
    }
    return res;
}
double completeJudge(char stage[10][10], int remain)
{
    char temp[10][10];
    memcpy(temp, stage, sizeof(temp));
    int num = getNumberOnce(temp);
    if(num >= remain)
    {
        return 1.0;
    }
    if(num == 0)
    {
        return 0.0;
    }
    remain -= num;
    fallDown(temp);
    Point stack[8];
    int top = 0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(!temp[i][j])
            {
                stack[top].x = i;
                stack[top].y = j;
                ++ top;
            }
        }
    }
    int total = getPow5(top);
    double ret = 0.0;
    for(int i=0;i<total;++i)
    {
        int bit = i;
        for(int j=0;j<top;++j)
        {
            temp[stack[j].x][stack[j].y] = '0' + (bit % 5);
            bit /= 5;
        }
        ret += completeJudge(temp, remain);
    }
    return ret / total;
}
int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        for(int i=0;i<8;++i)
        {
            scanf("%s", stage[i]);
        }
        double ans = 0.0;
        bool end = false;
        for(int i=0;i<8 && !end;++i)
        {
            for(int j=0;j<8 && !end;++j)
            {
                if(i!=7)
                {
                    swap(stage[i][j], stage[i+1][j]);
                    if(simpleJudge())
                    {
                        ans = 1.0;
                        end = true;
                    }
                    swap(stage[i][j], stage[i+1][j]);
                }
                if(j!=7)
                {
                    swap(stage[i][j], stage[i][j+1]);
                    if(simpleJudge())
                    {
                        ans = 1.0;
                        end = true;
                    }
                    swap(stage[i][j], stage[i][j+1]);
                }
            }
        }
        if(!end)
        {
            double temp;
            for(int i=0;i<8 && !end;++i)
            {
                for(int j=0;j<8 && !end;++j)
                {
                    if(i!=7)
                    {
                        swap(stage[i][j], stage[i+1][j]);
                        temp = completeJudge(stage, 8);
                        ans = max(ans, temp);
                        swap(stage[i][j], stage[i+1][j]);
                    }
                    if(ans > 1.0 - eps)
                    {
                        ans = 1.0;
                        end = true;
                    }
                    if(j!=7)
                    {
                        swap(stage[i][j], stage[i][j+1]);
                        temp = completeJudge(stage, 8);
                        ans = max(ans, temp);
                        swap(stage[i][j], stage[i][j+1]);
                    }
                    if(ans > 1.0 - eps)
                    {
                        ans = 1.0;
                        end = true;
                    }
                }
            }
        }
        printf("Case #%d: %.3lf\n", cas, ans);
    }
    return 0;
}
