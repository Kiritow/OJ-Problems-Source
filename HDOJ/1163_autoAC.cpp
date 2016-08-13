#include<stdio.h>
int main()
{
    int n;
    char s[20]="149429719159479789";
    while(~scanf("%d",&n),n)
        printf("%c\n",s[(n-1)%18]);
    return 0;
}
