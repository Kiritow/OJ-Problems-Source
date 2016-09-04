#include<iostream>
#include<string>
using namespace std;
char ch[25];
int main()
{
    int n, i, j;
    scanf("%d", &n);
    while(n--)
    {
        int a, b;
        scanf("%d%d%*c%s", &a, &b, ch);
        printf("%d ", a);
        for(i = 0; ch[i] != '\0'; i++)
        {
            for(j = 0; j < b; j++)
                printf("%c", ch[i]);
        }
        printf("\n");
    }
    return 0;
}
