#include <iostream>
#include <algorithm>
using namespace std;
char date[1000][1000];
char strings[2000];
int main ()
{ 
    int num;
    int i,j;
    int len;
    int pos=0;
    while(cin>>num)
    { 
        pos=0;
        for(i=0;i<num;i++)
            cin>>date[i];
        len=strlen(date[0]);
        int flag=0;
        for(j=0;j<len;j++)
        {
            for(i=0;i<num;i++)
            {
                if(date[i][j]!='_')
                    flag=1;            
                if(flag==1)                  
                {
                    strings[pos]=date[i][j];
                    pos++;
                }
            }
        }
        strings[pos]='\0';
        reverse(strings,strings+pos);
        for(i=0;i<pos;i++)
        {
            if(strings[i]=='_')
            {
                printf(" ");
                strings[i]=' ';
                continue;
            }
            else if(strings[i]=='\\')
            {
                cout<<'\n';
                continue;
            }
            else 
                cout<<strings[i];
        }
        cout<<endl<<endl;
    }
    return 0;
}
