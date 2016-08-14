 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 #define CLR(x) memset(x, 0, sizeof(x))
 int n, m;
 int d[505][505][2];
 int x[505][505][2];
 int nor[505][505], wes[505][505];
 void init()
 {
     for (int t = 0; t < 2; ++ t)
         for (int i = 0; i < n; ++ i)
             for (int j = 0; j < m; ++ j)
                 scanf ("%d", &x[i][j][t]);
     CLR (nor); CLR (wes);
     for (int i = 0; i < n; ++ i)
         for (int j = 0; j < m; ++ j){
             wes[i][j] = (j ? x[i][j][0]+wes[i][j-1] : x[i][j][0]);
             nor[i][j] = (i ? x[i][j][1]+nor[i-1][j] : x[i][j][1]);
         }
 }
 int DP()
 {
     CLR (d);
     d[0][0][0] = x[0][0][0]; d[0][0][1] = x[0][0][1];
     for (int i = 0; i < n; ++ i)
         for (int j = 0; j < m; ++ j){
             if (!i && !j) continue;
             d[i][j][0] = wes[i][j];
             if (i)
                 d[i][j][0] += max(d[i-1][j][0], d[i-1][j][1]);
             d[i][j][1] = nor[i][j];
             if (j)
                 d[i][j][1] += max(d[i][j-1][0], d[i][j-1][1]);
         }
     return max(d[n-1][m-1][0], d[n-1][m-1][1]);
 }
 int main()
 {
     while (scanf ("%d%d", &n, &m) != EOF && n){    
         init();
         printf ("%d\n", DP());        
     }
     return 0;
 }
