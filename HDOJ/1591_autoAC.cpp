#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string lib;
    cin >> lib;
    for(char c = 'Z'; c >= 'A'; --c)
    {if(lib.find(c) == string::npos){lib += c;}}
    string line;
    cin.ignore(1);
    while(getline(cin , line))
    {
        for(size_ i = 0; i < line.size(); ++i)
        {
            if(isupper(line[i]))
            {line[i] = 'A' + lib.find(line[i]);}
            else if(islower((line[i])))
            {line[i] = 'a' + lib.find(toupper(line[i]));}
        }
        cout << line << endl;
    }
    return 0;
}
