#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int rr, c[1111111];
int lowbit(int x)
{
    return x & (-x);
}
void add(int i, int val)
{
    while(i <= rr){
        c[i] += val;
        i += lowbit(i);
    }
}
int sum(int i)
{
    int s = 0;
    while(i > 0){
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}
int mat[555][555];
int ans[555][555];
int mm;
int Bin()
{
    int l = 1, r = rr;
    while(l < r){
        int m = (l + r) >> 1;
        if(sum(m) >= mm) r = m;
        else l = m + 1;
    }
    return l - 1;
}
int main()
{
    int n, r;
    while(scanf("%d %d", &n, &r) == 2){
        if(!n && !r) {
            break;
        }
        r = (r << 1) + 1;
        mm = (r * r + 1) >> 1;
        rr = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                scanf("%d", &mat[i][j]);
                rr = max(rr, mat[i][j] + 1);
            }
        memset(c, 0, sizeof(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < r - 1; j++){
                add(mat[i][j] + 1, 1);
            }
        }
        for(int i = 0; ; ){
            for(int j = r - 1; j < n; j++){
                for(int k = 0; k < r; k++)
                    add(mat[i + k][j] + 1, 1);
                ans[i][j - (r - 1)] = Bin();
                for(int k = 0; k < r; k++)
                    add(mat[i + k][j - (r - 1)] + 1, -1);
            }
            for(int j = n - 1; j >= n - (r - 1); j--)
                add(mat[i][j] + 1, -1);
            i++;
            if(i + (r - 1) >= n) break;
            for(int j = n - 1; j >= n - (r - 1); j--)
                add(mat[i + (r - 1)][j] + 1, 1);
            for(int j = n - r; j >= 0; j--){
                for(int k = 0; k < r; k++)
                    add(mat[i + k][j] + 1, 1);
                ans[i][j] = Bin();
                for(int k = 0; k < r; k++)
                    add(mat[i + k][j + (r - 1)] + 1, -1);
            }
            for(int j = 0; j < (r - 1); j++)
                add(mat[i][j] + 1, -1);
            i++;
            if(i + (r - 1) >= n) break;
            for(int j = 0; j < (r - 1); j++)
                add(mat[i + (r - 1)][j] + 1, 1);
        }
        for(int i = 0; i <= n - r; i++){
            for(int j = 0; j <= n - r; j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
