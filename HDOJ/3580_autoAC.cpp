#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int alp[52][52];
bool mark[26];
int num[26];
int size;
int dir[8][4]={{-1, 0, 1, 1}, {1, 0, -1, 1}, {1, 0, -1, -1}, {-1, 0, 1, -1}, {-1, 1, 1, 0}, {1, 1, 0, -1}, {-1, -1, 1, 0}, {-1, 1, 0, -1}};
bool ok(int x, int y, int k, int d)
{
    int i=x, j=y, len, l;
    i+=dir[k][0]*d;j+=dir[k][1]*d;
    if(k<4)len=d+1;
    else len=2*d+1;
    for(l=0; l<len; l++, i+=dir[k][2], j+=dir[k][3]){
        if(i<0||i>size||j<0||j>size||alp[i][j]!=alp[x][y])return false;
    }
    num[alp[x][y]-'A']++;
    return true;
}
int main()
{
    int t, ca, i, j, k, deep;
    scanf("%d",&t);
    for(ca=1; ca<=t; ca++){
        scanf("%d", &size);
        getchar();
        memset(mark, false, sizeof(mark));
        memset(alp, 0, sizeof(alp));
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                scanf("%c", &alp[i][j]);
                mark[alp[i][j]-'A']=true;
            }
            getchar();
        }
        memset(num, 0, sizeof(num));
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                for(k=0; k<=7; k++){
                    deep=1;
                    while(ok(i, j, k, deep)){
                        deep++;
                    }
                }
            }
        }
        printf("Case %d:\n", ca);
        for(i=0; i<26; i++)
            if(mark[i])
                printf("%c %d\n", i+'A', num[i]);
    }
    return 0;
}
