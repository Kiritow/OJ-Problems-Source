#include <iostream>
using namespace std;
string op;
int parm;
int n;

int operation_type[16];
int operation_parm[16];

bool takeoperation(int a)
{
    for(int i=0;i<n;i++)
    {
        switch(operation_type[i])
        {
        case 0:
            a+=operation_parm[i];
            if(a<0) return false;
            break;
        case 1:
            a-=operation_parm[i];
            if(a<0) return false;
            break;
        case 2:
            a*=operation_parm[i];
            if(a<0) return false;
            break;
        case 3:
            if(a%operation_parm[i]!=0)
            {
                return false;
            }
            else
            {
                a/=operation_parm[i];
            }
            break;
        }
    }
    return true;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>op>>operation_parm[i];
        operation_type[i]=0;
        switch(op.at(0))
        {
        case 'D':
            operation_type[i]++;
        case 'M':
            operation_type[i]++;
        case 'S':
            operation_type[i]++;
        case 'A':
            break;
        }
    }
    int cnt=0;
    for(int i=1;i<=100;i++)
    {
        if(takeoperation(i))
        {
            cnt++;
        }
    }
    cout<<100-cnt<<endl;
    return 0;
}
