#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[])
{
    char mark[256], seq[100099];
    memset (mark,0,256);
    int i, idx =0;
    for (i=0;i<10000;i++)
    {
        char k;
        k=getchar();
        if(k=='\n')
            break;
        mark[k]++;
        seq[idx] = k;
        idx++;
    }
    for(i=0;i<idx;i++)
        if (mark[seq[i]]==1)
        {
            printf("%c",seq[i]);
            break;
        }
    if (i==idx)
        puts("no");
    return 0;
}
