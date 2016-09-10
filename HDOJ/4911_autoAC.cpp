#include<stdio.h>
#include<string.h>
#define N 100005
__int64 cnt, k;
int a[N],c[N];
void merge(int a[], int first, int mid, int last, int c[])
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;
    while(i <= m || j <= n)
    {
        if(j > n || (i <= m && a[i] <= a[j]))
            c[k++] = a[i++];
        else
        {
            c[k++] = a[j++];
            cnt += (m - i + 1);
        }
    }
    for(i = 0; i < k; i++)
        a[first + i] = c[i];
}
void merge_sort(int a[], int first, int last, int c[])
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        merge_sort(a, first, mid, c);
        merge_sort(a, mid+1, last, c);
        merge(a, first, mid, last, c);
    }
}
int main()
{
    int n;
    while(~scanf("%d%I64d",&n,&k))
    {
        memset(c, 0, sizeof(c));
        cnt = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        merge_sort(a, 0, n-1, c);
        if(k >= cnt) cnt = 0;
        else cnt -= k;
        printf("%I64d\n",cnt);
    }
}
