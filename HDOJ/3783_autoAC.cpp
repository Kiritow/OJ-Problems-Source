#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char str[1000];
    int z,o,j;
    while(gets(str))
    {
        if(!strcmp(str,"E"))
        break;
        z = o = j = 0;
        int len = strlen(str);
        int i;
        for(i = 0;i<len;i++)
        {
            if(str[i] == 'Z')
            z++;
            else if(str[i] == 'O')
            o++;
            else if(str[i] == 'J')
            j++;
        }
        while(z || o || j)
        {
            if(z)
            {
                cout << "Z";
                z--;
            }
            if(o)
            {
                cout << "O";
                o--;
            }
            if(j)
            {
                cout << "J";
                j--;
            }
        }
        cout << endl;
    }
    return 0;
}
