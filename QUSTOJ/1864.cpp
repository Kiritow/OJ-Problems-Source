#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

template<int num>
struct fib
{
    enum {result=fib<num-1>::result+fib<num-2>::result};
};

template<>
struct fib<0>
{
    enum {result=1};
};

template<>
struct fib<1>
{
    enum{ result=1};
};

int x[15];

int main()
{
    x[0]=fib<0>::result;
    x[1]=fib<1>::result;
    x[2]=fib<2>::result;
    x[3]=fib<3>::result;
    x[4]=fib<4>::result;
    x[5]=fib<5>::result;
    x[6]=fib<6>::result;
    x[7]=fib<7>::result;
    x[8]=fib<8>::result;
    x[9]=fib<9>::result;
    x[10]=fib<10>::result;
    x[11]=fib<11>::result;
    x[12]=fib<12>::result;
    x[13]=fib<13>::result;
    x[14]=fib<14>::result;
    int a;
    cin>>a;
    cout<<x[a-1]<<endl;

    return 0;
}

