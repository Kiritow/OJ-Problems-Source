#include<stdio.h> 
#include<string.h> 
int dir[18][2] = 
{ 
    { -1, -1,}, { -1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}, 
    { -1, -1,}, { -1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, 
    { -1, 0,}, { -1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0} 
}; 
__int64 mlen[21]; 
__int64 msle[21]; 
__int64 bl, m, l, sn; 
__int64 n; 
__int64 map[101]; 
__int64 res[101]; 
__int64 ret[101][101]; 
__int64 Mat[101][101]; 
__int64 temp[101][101]; 
void make_mlen() 
{ 
    int i, j; 
    sn = bl * 2 - 1; 
    for( i = 0 ; i < bl; i++) 
        mlen[i] = i + bl; 
    for( j = bl - 2; j >= 0 ; j--) 
        mlen[i++] = mlen[j]; 
    msle[0] = 0; 
    for( i = 1; i <= sn ; i++) 
        msle[i] = msle[i - 1] + mlen[i - 1]; 
    n = msle[sn]; 
} 
void input() 
{ 
    int i; 
    for( i = 0 ; i < n; i++) 
        scanf("%I64d", &map[i]); 
} 
void make_matrix() 
{ 
    int i, j, k, ii, jj, kk; 
    memset(Mat, 0, sizeof(Mat)); 
    for( i = 0 ; i < sn; i++) 
    { 
        for(j = 0 ; j < mlen[i] ; j++) 
        { 
            Mat[msle[i] + j][msle[i] + j] = 1; 
            for( k = 0 ; k < 6 ; k++) 
            { 
                if( i < bl - 1 )
                    kk = 0; 
                else if( i == bl - 1) 
                    kk = 6; 
                else 
                    kk = 12; 
                ii = i + dir[kk + k][0]; 
                jj = j + dir[kk + k][1]; 
                if( ii < 0 || ii >= sn || jj < 0 || jj >= mlen[ii]) 
                    continue; 
                Mat[msle[i] + j][msle[ii] + jj] = 1; 
            } 
        } 
    } 
} 
void matmul(__int64 a[][101], __int64 b[][101]) 
{ 
    int i, k, j; 
    memset(temp, 0, sizeof(temp)); 
    for(i = 0; i < n; i++) 
        for(k = 0; k < n; k++) 
            if(a[i][k]) 
                for(j = 0; j < n; j++) 
                    if( b[k][j] ) 
                        temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % m; 
    memcpy(a, temp, sizeof(temp)); 
}
void init_() 
{ 
    int i, j; 
    for(i = 0; i < n; i++) 
        for(j = 0; j < n; j++) 
            ret[i][j] = (i == j); 
} 
void q_mod(int k) 
{ 
    init_(); 
    for(; k ; k >>= 1) 
    { 
        if(k & 1) 
            matmul(ret, Mat); 
        matmul(Mat, Mat); 
    } 
} 
__int64 solve() 
{ 
    __int64 i, j, sum, ans = 0; 
    for(i = 0; i < n; i++) 
    { 
        sum = 0; 
        for( j = 0; j < n; j++) 
        { 
            sum = (sum + map[j] * ret[i][j]) % m; 
        } 
        res[i] = sum; 
    } 
    for( i = 0 ; i < n ; i++) 
        ans += res[i];  
    return ans; 
} 
int main() 
{ 
    int i, j, k = 0; 
    while(scanf("%I64d%I64d%I64d", &bl, &m, &l), bl + m + l) 
    { 
        k++; 
        make_mlen(); 
        make_matrix(); 
        input(); 
        q_mod(l); 
        printf("Case %d: %I64d\n", k, solve()); 
    } 
    return 0; 
}
