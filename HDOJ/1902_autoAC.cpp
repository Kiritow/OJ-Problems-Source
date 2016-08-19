#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAX = 20000+5;
int main()
{
    int n,m,d[MAX],a[MAX];
    while(std::cin>>n>>m,(n+m))
    {
        for(int i = 0;i < n;i++)
          std::cin>>d[i];
        for(int i = 0;i < m;i++)
          std::cin>>a[i];
        if(n>m)
        {
          std::cout<<"Loowater is doomed!"<<std::endl;
          continue;
        }
        std::sort(d,d+n);
        std::sort(a,a+m);
        int tot = 0;
        int i = 0,j=0;
        while(i<n&&j<m)
        {
            if(a[j]>=d[i]){
               tot += a[j];
               j++,i++;
            }else
            {
                j++;
            }
        }
        if(i>=n)
          std::cout<<tot<<std::endl;
        else
          std::cout<<"Loowater is doomed!"<<std::endl;
    }
    return 0;
}
