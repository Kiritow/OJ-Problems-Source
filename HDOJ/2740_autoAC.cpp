#include <cstdio>
#include <cmath>
int main()
{
double B,N;
int A;
while(scanf("%lf%lf",&B,&N)&&(B!=0.0||N!=0.0))
{
A=pow(B,1/N);
if((B-pow(A,N))<(pow(A+1,N)-B))
    printf("%d\n",A);
else 
    printf("%d\n",A+1);    
    }
    return 0;    
}
