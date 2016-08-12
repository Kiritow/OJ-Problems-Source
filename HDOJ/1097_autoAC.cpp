#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        a%=10;
        if(a==0||a==5||a==6||a==1) printf("%d\n",a);
        else if(a==4||a==9)
        {
            printf("%d\n",b%2==0?a*a%10:a);    
        }
        else
        {
            if(b%4==1) printf("%d\n",a);
            else if(b%4==2) printf("%d\n",a*a%10);
            else if(b%4==3) printf("%d\n",a*a*a%10);
            else printf("%d\n",a*a*a*a%10);    
        }    
    }
    return 0;    
}
