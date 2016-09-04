#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

void getfill(char* s,int L,int* f)
{
    //memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<L;i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}

#define MAXLEN 1000100
int next[MAXLEN];
char buffer[MAXLEN];
int main()
{
    while(scanf("%s",buffer)==1)
    {
        if(buffer[0]=='.') break;
        memset(next,0,sizeof(next));
        int len=strlen(buffer);
        getfill(buffer,len,next);
        if(len%(len-next[len])==0)
        {
            printf("%d\n",len/(len-next[len]));
        }
        else
        {
            printf("1\n");
        }
    }
    return 0;
}
