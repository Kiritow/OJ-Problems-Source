#include <iostream>   
#include <string>   
using namespace std;  
int main()  
{  
    string input;  
    while (cin>>input)  
    {  
        cout<<"300 420 moveto"<<endl;  
        cout<<"310 420 lineto"<<endl;  
        int x=310,y=420;  
        int len=input.length();  
        int flag=1;      
        for(int i=0;i<len;i++)  
        {   
            if(input[i]=='A')  
            {  
                switch(flag)  
                {  
                    case 1:  
                        y-=10;  
                        flag=2;  
                        break;  
                    case 2:  
                        x-=10;  
                        flag=3;  
                        break;  
                    case 3:  
                        y+=10;  
                        flag=4;  
                        break;  
                    case 4:  
                        x+=10;  
                        flag=1;  
                        break;  
                }  
                cout<<x<<" "<<y<<" lineto"<<endl;  
            }  
            else 
            {  
                switch(flag)  
                {  
                case 1:  
                    y+=10;  
                    flag=4;  
                    break;  
                case 2:  
                    x+=10;  
                    flag=1;  
                    break;  
                case 3:  
                    y-=10;  
                    flag=2;  
                    break;  
                case 4:  
                    x-=10;  
                    flag=3;  
                    break;  
                }  
                cout<<x<<" "<<y<<" lineto"<<endl;  
            }  
        }  
        cout<<"stroke\nshowpage"<<endl;  
    }  
    return 0;  
}
