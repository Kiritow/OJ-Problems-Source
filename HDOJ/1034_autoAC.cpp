#include<iostream>
using namespace std;
int T[500],T1[500],n;
int check()
{
    int temp = T[0];
    for(int j=1;j<n;j++)
    {
        if(temp != T[j])
            return -1;
    }
    return temp;
}
bool isEv(int num)
{
    return num%2==0?true:false;
}
int main()
{
    int i,k,cnt,res;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&T[i]);
        }
        cnt =0;
        res = -1;
        while(1)
        {
            res = check();
            if(res != -1)
                break;
            for(i=0;i<n;i++)
            {
                T1[i] = T[i]/2;    
            }
            for(i=0;i<n;i++)
            {
                if(i ==n-1)
                {
                    T1[0] += T[n-1]/2;
                }
                else
                {
                    T1[i+1] += T[i]/2;
                }
            }
            for(i=0;i<n;i++)
            {
                if(false == isEv(T1[i]))
                T1[i]++;
                T[i] = T1[i];
            }
            cnt++;
        }
        printf("%d %d\n",cnt,res);
    }
    return 0;
}
