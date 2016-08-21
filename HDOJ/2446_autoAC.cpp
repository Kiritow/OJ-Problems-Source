#include<iostream>
using namespace std;
#define N 1000001
long long num[N];
int findLayer(long long n)
{
    int head = 0, tail = N - 1;
    int middle= (int)((head + tail) / 2);
    while (head != tail)
    {
        if (num[middle] < n)
            head = middle + 1;
        else if (num[middle - 1] > n)
            tail = middle - 1;
        else
            break;
        middle = (int)((head + tail) / 2);
    }
    return middle+1;
}
long long getNum(long long i)
{
    return (1 + i)*i / 2;
}
int findRow(long long n,int layer)
{
    long long index = n - num[layer - 2];
    long long head = 1;
    long long tail = layer;
    long long middle = (int)((head + tail) / 2);
    while (head != tail)
    {
        if (getNum(middle) < index)
            head = middle + 1;
        else if (getNum(middle - 1) >= index)
            tail = middle - 1;
        else
            break;
        middle = (int)((head + tail) / 2);
    }
    return middle;
}
int findColumn(long long n,int row,int layer)
{
    long long index = n - num[layer - 2]-getNum(row-1);
    return index;
}
int main()
{
    num[0] = 1;
    num[1] = 4;
    for (int i = 2; i < N; i++)
        num[i] = 2 * num[i - 1] - num[i - 2] + i+1;
    int T;
    cin >> T;
    long long n;
    int layer, row, column;
    while (T--)
    {
        cin >> n;
        layer = findLayer(n);
        row = findRow(n, layer);
        column = findColumn(n, row,layer);
        cout << layer << " " << row << " " << column << endl;
    }
    return 0;
}
