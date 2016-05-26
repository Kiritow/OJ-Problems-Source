#include <iostream>
#include <cstdio>
using namespace std;
 
 
/**Written By Kiritow
Nov. 30th, 2015
All Rights Reserved.
*/
 
 
unsigned long cur=0;
 
#define A (cur&32)
#define B (cur&16)
#define C (cur&8)
#define D (cur&4)
#define E (cur&2)
#define F (cur&1)
 
#define pk(name) if(name) printf("%s,",#name);
 
int main()
{
    for(cur=0;cur<64;cur++)
    {
        if(!A&&!B)
        {
            continue;
        }
        if(A&&D)
        {
            continue;
        }
        if(!(((A&&E)||(A&&F)||(E&&F))&&(!(A&&E&&F))))
        {
            continue;
        }
        if(!((B&&C)||(!B&&!C)))
        {
            continue;
        }
        if(!((C&&!D)||(!C&&D)))
        {
            continue;
        }
        if(!D)
        {
            if(E)
                continue;
        }
 
        pk(A);
        pk(B);
        pk(C);
        pk(D);
        pk(E);
        pk(F);
 
        printf("\n");
    }
    return 0;
}
