#include<stdio.h>
int main()
{
    double k,l,s,w;
    while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w),k||l||s||w)
        if(s<l||w*9.81*s-k*(s-l)*(s-l)/2>=0){
            if(2*9.81*s-(s>=l)*k*(s-l)*(s-l)/w<=100)
                puts("James Bond survives.");
            else
                puts("Killed by the impact.");
        }
        else
            puts(Stuck in
