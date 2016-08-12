#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    double examples[300],enter;
    int numDenominator=3,circleA;
    examples[0]=1.0/2.0;
    for(circleA=1;circleA<280;circleA++){
      examples[circleA]=examples[circleA-1]+1.0/(double)(numDenominator++);
    }
    while(cin>>enter){
        if(0.00==enter){
         break;
        }
        for(circleA=0;circleA<280;circleA++){
          if(examples[circleA]>=enter){
               cout<<circleA+1<<" card(s)"<<endl;
               break;
          }
        }
    }
    return 0;
}
