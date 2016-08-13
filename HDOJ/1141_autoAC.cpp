#include<iostream>
#include<cmath>
using namespace std;
int x[21];
void make()
{
    int i,j;
    double k=log(4.0);
    for(i=196;i<=216;++i)
    {
        k*=2;   
        double f=0;
        for(j=1;f<k;++j)
            f+=log((double)j);
        x[i-196]=j-2;
    }
}
int main()
{
    make();
    int year;
    while(cin>>year&&year)
        cout<<x[(year-1960)/10]<<endl;
    return 0;
}#include<iostream>
#include<cmath>
using namespace std;
int x[21];
void make()
{
    int i,j;
    double k=log(4.0);
    for(i=196;i<=216;++i)
    {
        k*=2;   
        double f=0;
        for(j=1;f<k;++j)
            f+=log((double)j);
        x[i-196]=j-2;
    }
}
int main()
{
    make();
    int year;
    while(cin>>year&&year)
        cout<<x[(year-1960)/10]<<endl;
    return 0;
}
