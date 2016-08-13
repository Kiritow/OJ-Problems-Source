#include <iostream>
#include <iomanip>
using namespace std;
struct LL
{
    int num[50];
    int len;
};
LL count[51][51];
LL total[51];
LL operator+(const LL& a, const LL& b)
{
    LL c;
    int Len = a.len>b.len?a.len:b.len;
    int jin = 0;
    for(int i=0;i<Len;i++)
    {
        c.num[i] = jin;
        jin = 0;
        if(i<a.len)
            c.num[i] += a.num[i];
        if(i<b.len)
            c.num[i] += b.num[i];
        jin = c.num[i]/1000000;
        c.num[i]%=1000000;
    }
    c.len = Len;
    if(jin)
    {
        c.num[Len] = jin;
        c.len++;
    }
    return c;
}
LL operator*(const LL& a, int num)
{
    LL c;
    int Len = a.len;
    int jin = 0;
    for(int i=0;i<Len;i++)
    {
        c.num[i] = jin;
        jin = 0;
        c.num[i]+=a.num[i]*num;
        jin = c.num[i]/1000000;
        c.num[i]%=1000000;
    }
    c.len = Len;
    if(jin)
    {
        c.num[Len] = jin;
        c.len++;
    }
    return c;
}
ostream& operator<<(ostream& out, const LL& a)
{
    out << a.num[a.len-1];
    for(int i=a.len-2;i>=0;i--)
    {
        out << setfill('0') << setw(6) << a.num[i];
    }
    return out;
}
int main()
{
    count[1][0].num[0] = 1;
    count[1][0].len = 1;
    total[1].num[0] = 1;
    total[1].len = 1;
    for(int i=2;i<51;i++)
    {
        total[i] = count[i][0] = count[i-1][0] * i;
        for(int j=1;j<i;j++)
        {
            count[i][j] = (count[i-1][j-1]+count[i-1][j]) * (i-j); 
            total[i]=total[i]+count[i][j];
        }
    }
    int P;
    cin >> P;
    while(P--)
    {
        int k;
        cin >> k;
        cout << total[k] << endl;
    }
}
