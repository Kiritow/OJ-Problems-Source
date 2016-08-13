#include <stdio.h>
#include <string.h>
void chessmove(char (*board)[8], char vert1, char hori1, char vert2, char hori2);
void printboard(char (*board)[8]);
int main()
{
    char inputbuffer[1000];
    char board_buffer[8][8] =
    {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    char board[8][8];
    char vert1, hori1, vert2, hori2;
    int end = 1;
    while(1)
    {
        memcpy(board,board_buffer,sizeof(board));
        while(1)
        {
            if(scanf("%d",&end)==EOF)
                return 0;
            if(end==-1) break;
            gets(inputbuffer);
            if (sscanf(inputbuffer,"%*c%*c%c%c%*c%c%c", &vert1, &hori1, &vert2, &hori2) != 4)
                continue;
            chessmove(board, vert1, hori1, vert2, hori2);
            if (sscanf(inputbuffer+7,"%*c%*c%c%c%*c%c%c", &vert1, &hori1, &vert2, &hori2) != 4)
                continue;
            chessmove(board, vert1, hori1, vert2, hori2);
        }
        printboard(board);
    }
    return 0;
}
void chessmove(char (*board)[8], char vert1, char hori1, char vert2, char hori2)
{
    int v1 = vert1 - 'a', h1 = 7 - hori1 + '1';
    int v2 = vert2 - 'a', h2 = 7 - hori2 + '1';
    char chessman = board[h1][v1];
    board[h1][v1] = ' ';
    board[h2][v2] = chessman;
}
void printboard(char (*board)[8])
{
    int i, j, cnt;
    for (i = 0; i < 8; ++i)
    {
        for (j = 0; j < 8; )
        {
            cnt = 0;
            while (board[i][j] == ' ' && j < 8)
            {
                ++cnt;
                ++j;
            }
            if (cnt > 0)
                printf("%d", cnt);
            else
                printf("%c", board[i][j++]);
        }
        if (i < 7)
            printf("/");
        else
            printf("\n");
    }
}
