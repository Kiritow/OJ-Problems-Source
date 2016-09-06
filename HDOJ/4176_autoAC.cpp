#include <cstdlib>   
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <string.h>  
#include <iostream>  
using namespace std;  
int main()  
{  
    int k;  
    int n;  
    cin>>k;  
    int a[55];  
    int cas=1;  
    while(k--)  
    {  
        cin>>n;  
        for(int i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        int b,c,d=-1;  
        sort(a,a+n);  
        printf("Class %d\n",cas++);  
        b=a[0],c=a[n-1];  
        for(int i=1;i<n;i++)  
        {  
            d=max(d,a[i]-a[i-1]);  
        }  
        printf("Max %d, Min %d, Largest gap %d\n",c,b,d);  
    }  
    return 0;  
}
