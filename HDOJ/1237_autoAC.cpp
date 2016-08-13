#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    double num[205];
    int i;
    double s;
    char f;
    double sum;
    while(cin>>s)
    {
        memset(num,'\0',sizeof(num));
        num[0]=s;
        i=0;
        f=getchar();
        if(f=='\n'&&s==0)break;
        while(1)
        {
            cin>>f>>s;
            if(f=='*')num[i]*=s;
            else if(f=='/')num[i]/=s;
            else if(f=='+')num[++i]=s;
            else
            {
                num[++i]=-s;
            }
            if(getchar()=='\n')break;
        }
        sum=0;
        for(i;i>=0;i--)
            sum+=num[i];
        printf("%.2lf\n",sum);
    }
    return 0;
}
