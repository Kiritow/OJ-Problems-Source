#include<stdio.h>
int stack[1001];
int snum;
int add(int x, int y, int z, int pre)
{
    int i, array[11];
    array[pre] = y;              
    for(i = 1; i < pre; i ++)    
    {
        array[i] = z % 10;
        z /= 10;
    }
    for(i = pre + 1; i <= 10; i ++)
    {
        array[i] = x % 10;
        x /= 10;
    }
    stack[++ snum] = 0;         
    for(i = 10; i >= 1; i --)
    {
        stack[snum] *= 10;
        stack[snum] += array[i];
    }
    return 0;
}
int Max(int a, int b)
{
    return a > b ? a : b;
}
int find(int pre, int n)
{
    int i;
    int flag = 1;
    int max;
    if(pre == 0)
        return 0;
    for(i = 1; i < pre; i ++)     
        flag *= 10;
    if(pre != 1 && n % 2 == 0 || pre == 1)
    {
        max = Max(flag / 2, 1);
        for(i = (n - n / flag * flag) / 2; i < flag; i += max)
        {
            if(i * 2 >= n)
                break;
            if((n - i * 2) < flag)
                break;
            if((n - i * 2) / flag % 11 != 10)
            {
                add((n - i * 2) / flag / 11, (n - i * 2) / flag % 11, i, pre);
            }
        }
    }
    return find(pre - 1, n);
}
int swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    return 0;
}
int sort()
{
    int i, j;
    for(i = 1; i < snum; i ++)
        for(j = i + 1; j <= snum; j ++)
        {
            if(stack[i] == stack[j])
            {
                stack[j] = stack[snum];
                snum --;
                j --;
            }
        }
    for(i = 1; i <= snum; i ++)      
    {
        for(j = i + 1; j <= snum; j ++)
        {
            if(stack[i] > stack[j])
            {
                swap(stack[i], stack[j]);
            }
        }
    }
    return 0;
}
int prin(int x, int n)
{
    int y = n - x, i;       
    int array[11], tail = 0;
    printf("%d + ", x);
    while(x >= 10)
    {
        array[++ tail] = y % 10;
        y /= 10;
        x /= 10;
    }
    for(i = tail; i >= 1; i --)
        printf("%d", array[i]);
    printf(" = %d\n", n);
    return 0;
}
int main()
{
    int n;
    int i;
    while(scanf("%d", &n) != EOF)
    {
        snum = 0;
        find(10, n);   
        sort();
        printf("%d\n", snum);    
        for(i = 1; i <= snum; i ++)
        {
            prin(stack[i], n);
        }
    }
    return 0;
}
