#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
void print(int num)
{
    for(int i = 1; i <= num ; i++)
        putchar('\t');
}
void print(int num, int pos , char A[])
{
    if(pos == n)
    {
        print(num);
        printf("printf(\"");
        for(int i = 0 ; i < n ; i++)
        {
            if(i)putchar('<');
            printf("%c" , A[i]);
        }
        puts("\\n\");");
        return;
    }
    for(int i = pos; i > 0  ; i-- , num++ )
    {
        print(num);
        printf("if (%c<%c)\n",A[i-1],A[i]);
        char _A[10];
        for(int j = 0 ; j < n; j++)
            _A[j] = A[j];
        print(num+1 , pos+1 ,_A);
        print(num);
        puts("else");
        swap(A[i-1] , A[i]);
    }
    print(num,pos+1,A);
}
int main()
{
    while(scanf("%d",&n),n)
    {
        puts("#include <stdio.h>\n");
        printf("int ");
        for(int i = 0 ; i < n ; i++)
        {
            if(i)putchar(',');
            putchar('a'+i);
        }
        puts(";\nbool ok;\n\nint main()\n{");
        printf("\tprintf(\"Please enter %d different integers:\\n\");\n",n);
        puts("\tdo\n\t{");
        printf("\t\tscanf(\"");
        for(int i = 0 ; i< n ;i++)
        {
            printf("%%d");
        }
        printf("\"");
        for(int i = 0 ; i< n ;i++)
        {
            printf(",&%c",'a'+i);
        }
        puts(");");
        printf("\t\tok=1;\n\t\tif (");
        for(int i = 0; i < n-1 ;i ++)
        {
            for(int j = i+1; j < n; j++)
            {
                printf("%c==%c",'a'+i,'a'+j);
                if(i!=n-2 || j!=n-1)printf(" || ");
            }
        }
        puts(")\n\t\t\tok=0;\n\t}while (ok);");
        char A[10];
        for(int i = 0 ; i < n ; i++)
            A[i] = 'a'+i;
        print(1,0,A);
        puts("\treturn 0;\n}\n");
    }
    return 0;
}
