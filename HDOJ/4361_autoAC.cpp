#include <cstdio>
#include <cstdlib>
int main()
{
    srand(1121139700);
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber --)
        if(rand() & 1) printf("alive!\n");
        else          printf("dead!\n");
}
