#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 10010
#define maxm 1000010
#define inf 0x3f3f3f3f
char table[11][11];
int row[333], col[333];
void change(char &c1, char &c2){
    if(row[c1] == row[c2])
        c1 = table[row[c1]][col[c1]+1], c2 = table[row[c2]][col[c2]+1];
    else if(col[c1] == col[c2])
        c1 = table[row[c1]+1][col[c1]], c2 = table[row[c2]+1][col[c2]];
    else{
        int r1 = row[c1], co1 = col[c1];
        int r2 = row[c2], co2 = col[c2];
        c1 = table[r1][co2], c2 = table[r2][co1];
    }
}
void update(char c, int &x, int &y){
    table[x][y] = c;
    row[c] = x;
    col[c] = y;
    y++;
    if(y == 6)
        x++, y = 1;
}
int main()
{
    int t;
    char s[2222];
    while(gets(s)){
        memset(table, 0, sizeof(table));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        int curi = 1, curj = 1;
        int l1 = strlen(s);
        for(int i = 0; i < l1; ++i){
            if(s[i] == 'q' || s[i] <'a' || s[i] >'z')
                continue;
            if(row[s[i]] == 0){
                update(s[i],curi, curj);
            }
        }
        if(curi < 6)
            for(int i = 0; i < 26; ++i)
                if(row['a'+i] == 0 && 'a' + i != 'q')
                    update('a'+i, curi, curj);
        for(int j = 1; j <= 5; ++j)
            table[6][j] = table[1][j];
        for(int i = 1; i <= 5; ++i)
            table[i][6] = table[i][1];
        char c1 = 0, c2 = 0;
        gets(s);
        int l = 0, r = strlen(s);
        while(l<r){
            if(s[l] == ' '|| s[l] == 'q'){
                l++;
                continue;
            }
            if(s[l] <'a' || s[l] >'z'){
                l++;
                continue;
            }
            if(c1 == 0){
                c1 = s[l++];
                continue;
            }
            if(c1 && c1 !=s[l])
                c2 = s[l++];
            else if(c1)
                c2 = 'x';
            change(c1, c2);
            printf("%c%c", c1-'a'+'A', c2-'a'+'A');
            c1 = c2 = 0;
        } 
        if(c1){
            c2 = 'x';
            change(c1, c2);
            printf("%c%c", c1-'a'+'A', c2-'a'+'A');
        }
        puts("");
    }
    return 0;
}
