#include <iostream>
#include <cstring>
using namespace std;
struct node 
{
    int x, y;
};
int cmp (const void *a, const void *b)
{
    node *c = (node *)a;
    node *d = (node *)b;
    if (c -> x != d -> x)
        return c -> x - d -> x;
    else
        return d -> y - c -> y;
}
int main ()
{
    node stu[21000];
    int t, n, i, j, k, a[21000];
    cin >> t;
    while (t--)
    {
        memset (a, 0, sizeof(a));
        cin >> n;
        for (i=0; i<n; i++)
            cin >> stu[i].x >> stu[i].y;
        qsort (stu, n, sizeof (stu[0]), cmp);
        a[0] = stu[0].y, k = 1;
        for (i=1; i<n; i++)
        {
            for (j=0; j<k; j++)
            {
                if (a[j] < stu[i].y)
                {
                    a[j] = stu[i].y;
                    break;
                }
            }
            if (j == k)
                a[k++] = stu[i].y;
        }
        cout << k << endl;
    }
    return 0;
}
