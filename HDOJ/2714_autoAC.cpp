#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int main ()
{
    string str;
    while ( cin >> str )
    {
          int N = str.size();
          int sum = 0, ask = 0;
          for ( int i = 1; i <= N; ++ i )
          {
               switch ( str[i-1] )
               {
                       case 'X':
                                sum += (10-i+1) * 10;  break;
                       case '?':
                                ask = 10-i+1;  break;
                       default :
                                sum += (10-i+1) * (str[i-1] - '0');  break;      
               }
          } 
          int pos = -1;
          for ( int i = 0; i <= 10; ++ i )  
          {
               if ( ( sum + ask * i ) % 11 == 0 )
               {
                    pos = i;
                    break;     
               }    
          } 
          if ( ask != 1 && pos == 10 ) pos = -1;    
          if ( pos == 10 )
             cout << 'X' << endl;  
          else
              cout << pos << endl;
    }
    return 0;
}
