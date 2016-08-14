#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn=100;
char x1[maxn];
char s1[maxn];
char s2[maxn];
char stack[maxn];
int len1,len2,len3;
void dfs(int x,int y,int ptr)
{
    if(y==len2)
    {              
        printf("\n");               
        for(int i=0;i<len3;i++)
            printf("%c ",x1[i]);
    }
    else 
    {   
        if(x<len1)
        {  
            char temp=stack[ptr];                                                
            x1[len3++]='i';
            stack[ptr]=s1[x];
            dfs(x+1,y,ptr+1);
            stack[ptr]=temp;
            len3--;
        }
        if(ptr>0&&stack[ptr-1]==s2[y])
        {
            x1[len3++]='o';                                      
            dfs(x,y+1,ptr-1);
            len3--;
        }
    }
}
int main()
{
    while(scanf("%s%s",&s1,&s2)!=EOF)
    {                             
        len1=strlen(s1);
        len2=strlen(s2);
        len3=0;
        if(len1!=len2) 
        {
            printf("[\n]\n");
            continue;
        }
        printf("[");
        dfs(0,0,0);
        printf("\n]\n");
    }                                              
    return 0;
}
