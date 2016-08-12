#include <iostream>
using namespace std;
bool money[8002];
int main()
{    
    unsigned numFive,numTwo,numOne;
    while(cin>>numOne>>numTwo>>numFive)
    {
        if(numOne==0&&numTwo==0&&numFive==0)
            break;
        memset(money,0,sizeof(bool)*(8002));
        for(unsigned i=0;i<=numFive;i++)
            for(unsigned j=0;j<=numTwo;j++)
                for(unsigned k=0;k<=numOne;k++)
                    money[k+j*2+i*5]=true;
        for(int i=1;i<=8001;i++)
            if(money[i]==false)
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}
