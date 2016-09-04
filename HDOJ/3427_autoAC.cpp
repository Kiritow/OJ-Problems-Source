#include<stdio.h>
#include<string.h>
#define NN 155 
char str[NN];
int mark[NN][NN];
int num[NN];
char cha[NN];
int dfs(int l, int r)
{
    int i, t;
    if (l == r){   
        if (num[l] > 1)
            return 1;
        else
            return 0;
    }
    if (mark[l][r]>= 0)
        return mark[l][r];
    char ch = cha[l];
    for (i = l + 1; i <= r; i++){
        if (cha[i] == ch){
            if (mark[l + 1][i - 1] = dfs(l + 1, i - 1)){
                t = mark[i][r];
                mark[i][r] = -1;
                num[i] += num[l];
                mark[i][r] = dfs(i, r);
                num[i] -= num[l];
                if (mark[i][r] == 1)
                {
                    mark[i][r] = t;
                    return 1;
                }
                mark[i][r] = t;
            }
        }
    }
    if (num[l] > 1 && (mark[l + 1][r] = dfs(l + 1, r)))
        return 1;
    return 0;
}
int main()
{
    int len, time, index, i;
    while (scanf("%s", str) != EOF){
        len = strlen(str);
        if (len == 0){
            puts("solvable");
            continue;
        }
        time = 1;
        index = 0;
        for (i = 1; i <= len; i++){
            if (str[i] != str[i - 1]){
                cha[index] = str[i - 1];
                num[index] = time;
                time = 1;
                index++;
            }
            else
                time++;
        }    
        memset(mark, -1, sizeof(mark));
        if (dfs(0, index - 1))
            puts("solvable");
        else
            puts("unsolvable");
    }
    return 0;
}
