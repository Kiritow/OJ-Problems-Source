#include<iostream>
using namespace std;
int x[21][21][21]={0};
int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    if(x[a][b][c]!=0)
        return x[a][b][c];
    if(a<b&&b<c)
    {
        x[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return x[a][b][c];
    }
    else
    {
        x[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return x[a][b][c];
    }
}
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c&&!(a==-1&&b==-1&&c==-1))
    {
        if(a<=0||b<=0||c<=0)
        {
            printf("w(%d, %d, %d) = %d\n",a,b,c,1);
            continue;
        }
        if(a>20||b>20||c>20)
            printf("w(%d, %d, %d) = %d\n",a,b,c,w(20,20,20));
        else
            printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    return 0;
}
