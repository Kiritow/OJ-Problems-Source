#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int IsKind(int n) 
{
    int i, sum = 0;
    for(i=1; i<=(int)sqrt(n); i++)
        if(n%i == 0)
            sum += i + n/i;
    return sum;
}
int main()
{
    int n, m, t;
    scanf("%d", &t);
    while( t-- ) {
        scanf("%d%d", &n, &m);
        if(IsKind(m) == IsKind(n))
            printf("YES\n");            
        else
            printf("NO\n");
    }    
    return 0;
}
