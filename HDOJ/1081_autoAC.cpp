#include<iostream>
using namespace std;
int MaxSum1D(int *a, int n)
{
    int sum = -128, b = 0;
    int i;
    for (i=0; i<n; ++i)
    {
        if(b > 0) b += a[i];
        else      b = a[i];
        if(b > sum) sum = b;
    }
    return sum;
}
int MaxSum2D(int a[][101], int m, int n)
{
    int sum = -128;
    int i, j, k;
    int *b = new int[n+1];
    for (i=0; i<m; ++i)
    {
        for (k=0; k<n; ++k) b[k] = 0;
        for (j=i; j<m; ++j)
        {
            for (k=0; k<n; ++k) b[k] += a[j][k];
            int Max = MaxSum1D(b, n);
            if(Max > sum)
                sum = Max;
        }
    }
    return sum;
}
int main()
{
    int n, i, j;
    int a[101][101];
    while (cin >> n)
    {
        for (i=0; i<n; ++i)
        {
            for (j=0; j<n; ++j)
            {
                cin >> a[i][j];
            }
        }
        cout << MaxSum2D(a, n, n) << endl;
    }
    return 0;
}
