//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

const int maxn = 3005;
bool a[maxn][maxn];

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i<n; i++)
        {
            for (int j = i + 1; j<n; j++)
            {
                int temp;
                scanf("%d", &temp);
                a[i][j] = a[j][i] = temp;
            }
        }
        int flag = 1;
        for (int i = 0; i<n; i++)
        {
            if (flag == 0)
                break;
            for (int j = i + 1; j<n; j++)
            {
                if (flag == 0)
                    break;
                for (int k = i + 1; k<j; k++)
                {
                    if (a[i][j] == a[i][k] && a[i][j] == a[k][j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
            puts("Great Team!");
        else
            puts("Bad Team!");
    }
    return 0;
}