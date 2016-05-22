#include <bits/stdc++.h>
using namespace std;

int main()
{
    char getChar[11];
    gets(getChar);
    char str1[33], str2[33];
    map <string, string> mp;
    map <string, string> :: iterator it;
    while (scanf("%s%s", str1, str2), str1[0] != 'E')
    {
        mp[str2] = str1;//可以传入char[]的地址
    }
    
    getchar();
    char ansStr[3333];
    char saveStr[33];
    while (gets(ansStr), ansStr[0] != 'E')
    {
        int i;
        int k = 0;
        for (i = 0; i < strlen(ansStr); i++)
        {
            if (ansStr[i] < 'a' || ansStr[i] > 'z')
            {
                if (ansStr[i - 1] >= 'a' && ansStr[i - 1] <= 'z')
                {
                    saveStr[k] = '\0';
                    k = 0;
                    it = mp.find(saveStr);
                    if (it == mp.end())
                    {
                        printf("%s", saveStr);//字典中不存在，则输出原单词
                    }
                    else
                    {
                        cout << it->second;//存在，输出翻译
                    }
                }

                printf("%c", ansStr[i]);
                
            }
            else
            {
                saveStr[k++] = ansStr[i];
            }
        }
        puts("");
    }

    
    return 0;
}
