#include<iostream>
using namespace std;
bool ch[40000002] = {0};
int a=30000000, b=40000000;
void init()
{
    int i, j;
    for( i=2; i <= 6325; i++ )
    {
        if(!ch[i])
        {
            for( j=i+i; j <= 6325; j += i)
                ch[j] = true;
            for( j=a/i*i; j <= b; j+=i)
                ch[j] = true;
        }
    }
}
int main()
{
    init();
    int i;
    for( i=a; i < b; i++ )
    {
        if(ch[i] == false)
            printf("%d\n", i);
    }
    return 0;
}
