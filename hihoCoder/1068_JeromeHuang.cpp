#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
using namespace std;


const int N = 10e6+10;
const int M = 30;
int arrayData[N];
int rmqData[N][M];
int n,m;
int min(int x, int y){
    return (x <y ? x : y);
}
void RMQ(){
    int i, j;
    for (i = 0; i < n; i++){
        rmqData[i][0] = arrayData[i];
    }
    for (j = 1; j <=m; j++){
        for (i = 0; i+(1 << j)-1 <n; i++){
            rmqData[i][j] = min(rmqData[i][j - 1], rmqData[i + (1<<(j - 1))][j - 1]);
        }
    }
}

int main(){
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++){
        scanf("%d", &arrayData[i]);
    }
    m = (log(n*1.0) / log(2.0));

    RMQ();
    
    int q;
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        l = l - 1;
        r = r - 1;
        int k=0;
        while ((1 << (k + 1)) <= (r - l + 1)) k++;
        printf("%d\n", min(rmqData[l][k], rmqData[r-(1<<k)+1][k]));
    }
    return 0;
}
