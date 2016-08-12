#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[10000],coun,n,m,i;
int main()
{
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
        {
            a[i] = i+1;
        }
        vector<int> iv(a,a+n);
        coun = 1;
        while(next_permutation(iv.begin(),iv.end()))
        {
            coun++;
            if(coun==m)
                break;
        }
        printf("%d",iv[0]);
        for(i=1;i<n;i++)
            printf(" %d",iv[i]);
        printf("\n");
    }
    return 0;
}
