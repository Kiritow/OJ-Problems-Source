#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double L,R;
}INUM;
char str[1024];
char* format(INUM i)
{
    sprintf(str,"(%.2f%+.2fi)",i.L,i.R);
    return str;
}
int main()
{
    INUM a,b;
    scanf("%lf %lf %lf %lf",&a.L,&a.R,&b.L,&b.R);
    INUM ans;
    ans.L=a.L+b.L;
    ans.R=a.R+b.R;
    printf(format(a));
    printf("+");
    printf(format(b));
    printf("=");
    printf(format(ans));
    printf("\n");

    ans.L=a.L-b.L;
    ans.R=a.R-b.R;
    printf(format(a));
    printf("-");
    printf(format(b));
    printf("=");
    printf(format(ans));
    printf("\n");

    ans.L=a.L*b.L-a.R*b.R;
    ans.R=a.L*b.R+a.R*b.L;
    printf(format(a));
    printf("*");
    printf(format(b));
    printf("=");
    printf(format(ans));
    printf("\n");

    ans.L=a.L*b.L+a.R*b.R;
    ans.L/=b.L*b.L+b.R*b.R;
    ans.R=a.R*b.L-a.L*b.R;
    ans.R/=b.L*b.L+b.R*b.R;
    printf(format(a));
    printf("/");
    printf(format(b));
    printf("=");
    printf(format(ans));
    printf("\n");

    return 0;
}
