#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    long long n;
    long long sum;
    int len;
    int i;
    int p=4*9999;
    char num[110];
    while(scanf("%s",num)!=EOF)
    {
        n=0;
        len=strlen(num);
        for(i=0; i<len; i++)
        {
            n=n*10+num[i]-'0';
            if(n>p)
            {
                n=n%p;
            }
        }
        n=n%p;  
        sum=n*(n+1)*(n+2)*(n+3)%p; 
        cout<<sum/4<<endl;    
    }
    return 0;
}
