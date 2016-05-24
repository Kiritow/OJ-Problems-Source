#include <stdio.h>

int numThing[100];
int costs[100][5];
int values[100][5];

int dp[3201];

int MAX(int a, int b){
    return a>b ? a:b;
}
int main(){
    int limit, num;
    int cost, value, index, i, k;

    scanf("%d %d", &limit, &num);
    limit /= 10;
    for(i=0; i<=num; i++)
        numThing[i] = 0;
    for(i=0; i<num; i++){
        scanf("%d %d %d", &cost, &value, &index);
        index--;
        if(index < 0)
            index = i;
        costs[index][numThing[index]] = cost/10;
        values[index][numThing[index]] = value;
        numThing[index]++;
    }

    for(i=0; i<=limit; i++)
        dp[i] = 0;

    for(i=0; i<num; i++){
        if(numThing[i] == 0)
            continue;
        for(k=limit; k>=costs[i][0]; k--){
            switch(numThing[i]){
                case 3:
                    if(k-costs[i][0]-costs[i][1]-costs[i][2] >= 0)
                        dp[k] = MAX(dp[k], dp[k-costs[i][0]-costs[i][1]-costs[i][2]] + values[i][0]*costs[i][0] + values[i][1]*costs[i][1] + values[i][2]*costs[i][2]);
                case 2:
                    if(k-costs[i][0]-costs[i][1] >= 0)
                        dp[k] = MAX(dp[k], dp[k-costs[i][0]-costs[i][1]] + values[i][0]*costs[i][0] + values[i][1]*costs[i][1]);
                    if(k-costs[i][0]-costs[i][2] >= 0)
                        dp[k] = MAX(dp[k], dp[k-costs[i][0]-costs[i][2]] + values[i][0]*costs[i][0] + values[i][2]*costs[i][2]);
                case 1:
                    dp[k] = MAX(dp[k], dp[k-costs[i][0]] + values[i][0]*costs[i][0]);
            }
        }
    }
    printf("%d\n", dp[limit]*10);

    return 0;
}
