#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 100010;
struct Point
{
    __int64 x, y;
}point[MAXN], high[2][MAXN], low[2][MAXN], merge[MAXN * 2];
int pointNumber, highNumber[2], lowNumber[2], mergeNumber;
int n, stack[MAXN], top;
__int64 a[MAXN];
Point operator + (const Point &a, const Point &b)
{
    Point r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}
Point operator - (const Point &a, const Point &b)
{
    Point r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}
inline __int64 operator * (const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}
inline __int64 absolute(int x)
{
    return x >= 0 ? x : -x;
}
inline double max(const double &x, const double &y)
{
    return x > y ? x : y;
}
inline __int64 cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) * (b - o);
}
void getBound(Point result[], int &resultNumber, bool isHigh)
{
    if(pointNumber == 1)
    {
        result[0] = point[0];
        resultNumber = 1;
        return;
    }
    stack[0] = 0;
    stack[1] = 1;
    top = 2;
    if(isHigh)
    {
        for(int i=2;i<pointNumber;++i)
        {
            while(top >= 2 && cross(point[stack[top-2]], point[i], point[stack[top-1]]) < 0)
            {
                -- top;
            }
            stack[top++] = i;
        }
    }
    else
    {
        for(int i=2;i<pointNumber;++i)
        {
            while(top >= 2 && cross(point[stack[top-2]], point[i], point[stack[top-1]]) > 0)
            {
                -- top;
            }
            stack[top++] = i;
        }
    }
    resultNumber = top;
    for(int i=0;i<top;++i)
    {
        result[i].x = point[stack[i]].x;
        result[i].y = point[stack[i]].y;
    }
}
void mergeBound(Point p1[], int len1, Point p2[], int len2, bool isHigh)
{
    merge[mergeNumber++] = p1[0] + p2[0];
    int pNum1 = 1, pNum2 = 1;
    while(pNum1 < len1 || pNum2 < len2)
    {
        if(pNum1 == len1)
        {
            merge[mergeNumber++] = p1[pNum1 - 1] + p2[pNum2 ++];
        }
        else if(pNum2 == len2)
        {
            merge[mergeNumber++] = p1[pNum1 ++] + p2[pNum2 - 1];
        }
        else
        {
            Point temp0 = p1[pNum1 - 1] + p2[pNum2 - 1];
            Point temp1 = p1[pNum1] + p2[pNum2 - 1];
            Point temp2 = p1[pNum1 - 1] + p2[pNum2];
            if(isHigh)
            {
                if(cross(temp1, temp2, temp0) < 0)
                {
                    merge[mergeNumber++] = temp1;
                    ++ pNum1;
                }
                else
                {
                    merge[mergeNumber++] = temp2;
                    ++ pNum2;
                }
            }
            else
            {
                if(cross(temp1, temp2, temp0) > 0)
                {
                    merge[mergeNumber++] = temp1;
                    ++ pNum1;
                }
                else
                {
                    merge[mergeNumber++] = temp2;
                    ++ pNum2;
                }
            }
        }
    }
}
double solve(int l, int r)
{
    if(l == r)
    {
        return absolute(a[l]);
    }
    int mid = (l + r) >> 1;
    double ansL = solve(l, mid);
    double ansR = solve(mid + 1, r);
    double ans = max(ansL, ansR);
    __int64 sum = 0;
    pointNumber = 0;
    for(int i=mid;i>=l;--i)
    {
        sum += a[i];
        point[pointNumber].x = mid - i + 1;
        point[pointNumber].y = sum;
        ++ pointNumber;
    }
    getBound(high[0], highNumber[0], true);
    getBound(low[0], lowNumber[0], false);
    sum = 0;
    pointNumber = 0;
    for(int i=mid+1;i<=r;++i)
    {
        sum += a[i];
        point[pointNumber].x = i - mid;
        point[pointNumber].y = sum;
        ++ pointNumber;
    }
    getBound(high[1], highNumber[1], true);
    getBound(low[1], lowNumber[1], false);
    mergeNumber = 0;
    mergeBound(high[0], highNumber[0], high[1], highNumber[1], true);
    mergeBound(low[0], lowNumber[0], low[1], lowNumber[1], false);
    for(int i=0;i<mergeNumber;++i)
    {
        ans = max(ans, fabs((double)merge[i].y) / sqrt((double)merge[i].x));
    }
    return ans;
}
int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%I64d", &a[i]);
        }
        double ans = solve(0, n - 1);
        printf("%.6lf\n", ans * ans);
    }
    return 0;
}
