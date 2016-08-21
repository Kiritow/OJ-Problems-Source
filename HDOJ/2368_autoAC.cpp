#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    __int64 t=0;
    __int64 r,w,l;
    while(cin>>r)
    {
        if(r==0) break;
        cin>>w>>l;
        t++;
        __int64 length_1,length_2;
        length_1=w*w+l*l;
        length_2=4*r*r;
        if(length_1<=length_2)
        printf("Pizza %I64d fits on the table.\n",t);
        else
        printf("Pizza %I64d does not fit on the table.\n",t);
    }
    return 0;
}
