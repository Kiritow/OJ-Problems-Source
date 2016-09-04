#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
struct node{
    int a[59];
    void init()
    {
        for(int i=0;i<59;i++) a[i]=i;
    }
    void chface(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
    {
        int tmp= a[a0];
        a[a0]=a[a6],a[a6]=a[a8],a[a8]=a[a2],a[a2]=tmp;
        tmp = a[a1];
        a[a1]=a[a3],a[a3]=a[a7],a[a7]=a[a5],a[a5]=tmp;
    }
    void chline(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11)
    {
        int tmp = a[a0];
        a[a0]=a[a9],a[a9]=a[a6],a[a6]=a[a3],a[a3]=tmp;
        tmp = a[a1];
        a[a1]=a[a10],a[a10]=a[a7],a[a7]=a[a4],a[a4]=tmp;
        tmp = a[a2];
        a[a2]=a[a11],a[a11]=a[a8],a[a8]=a[a5],a[a5]=tmp;
    }
    bool check()
    {
        for(int i=0;i<59;i++)
        if(a[i]!=i) return false;
        return true;
    }
    void U()
    {
        chface(36,37,38, 39,40,41, 42,43,44);
        chline(2,1,0, 29,28,27, 20,19,18 ,11,10,9);
    }
    void u()
    {
        chface(38,37,36, 41,40,39, 44,43,42);
        chline(9,10,11,18,19,20,27,28,29,0,1,2);
    }
    void R()
    {
        chface(9,10,11,12,13,14,15,16,17);
        chline(44,41,38,18,21,24,53,50,47,8,5,2);
    }
    void r()
    {
        chface(11,10,9, 14,13,12, 17,16,15);
        chline(2,5,8,47,50,53,24,21,18,38,41,44);
    }
    void F()
    {
        chface(0,1,2,3,4,5,6,7,8);
        chline(42,43,44 ,9,12,15, 47,46,45, 35,32,29);
    }
    void f()
    {
        chface(2,1,0, 5,4,3, 8,7,6);
        chline(29,32,35,45,46,47,15,12,9,44,43,42);
    }
    void D()
    {
        chface(45,46,47,48,49,50,51,52,53);
        chline(6,7,8 ,15,16,17, 24,25,26, 33,34,35);
    }
    void d()
    {
        chface(47,46,45, 50,49,48, 53,52,51);
        chline(35,34,33,26,25,24,17,16,15,8,7,6);
    }
    void L()
    {
        chface(27,28,29,30,31,32,33,34,35);
        chline(0,3,6, 45,48,51, 26,23,20, 36,39,42);
    }
    void l()
    {
        chface(29,28,27,32,31,30,35,34,33);
        chline(42,39,36,20,23,26,51,48,45,6,3,0);
    }
    void B()
    {
        chface(18,19,20,21,22,23,24,25,26);
        chline(38,37,36, 27,30,33, 51,52,53, 17,14,11);
    }
    void b()
    {
        chface(20,19,18, 23,22,21,26,25,24);
        chline(11,14,17,53,52,51,33,30,27,36,37,38);
    }
    void X()
    {
        chline(5,4,3, 32,31,30, 23,22,21, 14,13,12);
    }
    void x()
    {
        chline(12,13,14,21,22,23,30,31,32,3,4,5);
    }
    void Y()
    {
        chline(7,4,1, 43,40,37, 19,22,25, 52,49,46);
    }
    void y()
    {
        chline(46,49,52,25,22,19,37,40,43,1,4,7);
    }
    void Z()
    {
        chline(41,40,39,28,31,34, 48,49,50, 16,13,10);
    }
    void z()
    {
        chline(10,13,16,50,49,48,34,31,28,39,40,41);
    }
};
int main()
{
    char a[2009];
    node t;
    bool ou = false;
    while(~scanf("%s",a))
    {
        if(ou) printf("\n");
        ou = true;
        t.init();
        int len = strlen(a);
        for(int i=0;i<len;i++)
        {
            if(a[i]=='U') t.U();
            else if(a[i]=='R') t.R();
            else if(a[i]=='F') t.F();
            else if(a[i]=='D') t.D();
            else if(a[i]=='L') t.L();
            else if(a[i]=='B') t.B();
            else if(a[i]=='X') t.X();
            else if(a[i]=='Y') t.Y();
            else if(a[i]=='Z') t.Z();
            else if(a[i]=='u') t.u();
            else if(a[i]=='r') t.r();
            else if(a[i]=='f') t.f();
            else if(a[i]=='d') t.d();
            else if(a[i]=='l') t.l();
            else if(a[i]=='b') t.b();
            else if(a[i]=='x') t.x();
            else if(a[i]=='y') t.y();
            else if(a[i]=='z') t.z();
        }
        if(t.check())
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}
