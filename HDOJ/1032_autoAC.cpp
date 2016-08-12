#include <iostream>
using namespace std;
#define MAXNUM 1000000 + 1
 int result[MAXNUM];
 int main()
 {
   int beg,end,max,count,temp;
   while(cin>>beg>>end)
   {
       cout<<beg<<" "<<end<<" ";
       if(beg > end)
       {
           temp = beg;beg = end;end = temp;
       }
       max = count = 0;
       for(int t = beg;t <= end;++t)
       {
           if(result[t])
               count = result[t];
           else
           {
               temp = t;
               count = 1;
               while(temp != 1)
               {
                   if(temp%2 == 0)
                       temp = temp/2;
                   else
                       temp = 3*temp + 1;
                   ++count;
               }
               result[t] = count;
           }
           if(count > max)
               max = count;
       }
       cout<<max<<endl;
   }
   return 0;
}
