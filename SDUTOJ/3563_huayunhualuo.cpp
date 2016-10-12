#include <bits/stdc++.h>

using namespace std;

const int Max = 100100;

struct node
{
    int sore;

    int ali;

    int Id;

    bool operator < (const node &a)const
    {
        return sore == a.sore ? Id<a.Id : sore > a.sore;
    }

}a[Max*2],b[Max],c[Max];


void Solve(int n)
{
    int num1 = 0,num2 = 0;

    for(int i = 0;i<n;i+=2)
    {
        if(a[i].ali > a[i+1].ali)
        {
            b[num1]= a[i];

            b[num1].sore++; num1++;

            c[num2++] = a[i+1];
        }
        else
        {

            b[num1]= a[i+1];

            b[num1].sore++; num1++;

            c[num2++] = a[i];
        }
    }

    int num = 0;

    int i = 0 ,j = 0;

    while(i<num1&&j<num2)
    {
        if(b[i].sore>c[j].sore || (b[i].sore == c[j].sore && b[i].Id<c[j].Id))
        {
            a[num++] = b[i++];
        }
        else a[num++] = c[j++];
    }

    while(i<num1) a[num++] = b[i++];

    while(j<num2) a[num++] = c[j++];
}


int main()
{
    int T;

    int n,m,k;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);

        n = 2*n;

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&a[i].sore); a[i].Id = i+1;
        }

        for(int i = 0;i<n;i++) scanf("%d",&a[i].ali);

        sort(a,a+n);

        while(m--)
        {
            Solve(n);

        }
        printf("%d\n",a[k-1].Id);
    }
    return 0;
}
