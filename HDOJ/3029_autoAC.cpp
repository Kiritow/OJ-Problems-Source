#include <iostream>
#include <cmath>
using namespace std;
int num[30];
int ind;
void solve(int n)
{
        ind = 0;
        while(n)
        {
                num[ind++] = n % 3;
                n /= 3;
        }
}
void ss(int ii)
{
        num[ii]+=1;
        for(int i=ii;i<ind;i++)
        {
                if(num[i]>2)
                {
                      num[i] = 0;
                      num[i+1]++;
                      if(i == ind-1) ind += 1;
                }
        }
}
int main()
{
     int n;
     while( cin  >> n)
     {
        memset(num , 0 ,sizeof(num));
        solve(n);
        int re[30];
        int sum = 0,countd=0;
        memset(re,0,sizeof(re));
        for(int i=0;i<ind;i++)
        {
                if(num[i]==2)
                {
                       sum++;
                       ss(i);
                       re[i] = 1;
                }
        }
        for(int i=0;i<ind;i++)
            if(num[i] == 1)  countd++;
        if(sum == 0)  cout << "0" << endl;
        else
        {
            cout <<sum;
            for(int i=0;i<ind;i++)
            if(re[i])      printf(" %.lf",pow(3.0,i));
            cout << endl;
        }
        cout << countd;
        for(int i=0;i<ind;i++)
        if(num[i] == 1) printf(" %.lf",pow(3.0,i));
        cout << endl;
    }
    return 0;
}
