#include <iostream>
#include <string>
#include <map>
using namespace std;



struct Node
{
    struct Node *child[26];
    int perfixNum;
    bool isWord;
    char ansChar[111];
};

Node *root, *pNode;


void Init()
{
    root = new Node;
    for (int i = 0; i < 26; i++)
    {
        root->child[i] = NULL;
    }
}

void Insert(char word[], char ansChar[])
{
    int len = strlen(word);
    Node *pNode = root;
    for (int i = 0; i < len; i++)
    {
        if (pNode->child[word[i] - 'a'] == NULL)
        {
            Node *newNode = new Node;
            newNode->perfixNum = 1;
            newNode->isWord = 0;
            for (int j = 0; j < 26; j++)
            {
                newNode->child[j] = NULL;
            }

            pNode->child[word[i] - 'a'] = newNode;
        }
        else
        {
            pNode->child[word[i] - 'a']->perfixNum++;
        }
        
        pNode = pNode->child[word[i] - 'a'];
        if(i == len - 1)
        {
            pNode->isWord = 1;
            strcpy(pNode->ansChar, ansChar);
        }
    }
}

bool Find(char word[])
{
    int len = strlen(word);
    pNode = root;
    int i;
    for (i = 0; i < len; i++)
    {
        if (pNode->child[word[i] - 'a'] != NULL)
        {
            pNode = pNode->child[word[i] - 'a'];
        }
        else
        {
            break;
        }
    }
    
    //字典中存在该单词
    if (i == len && pNode->isWord == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




int main()
{
    char getChar[11];
    gets(getChar);
    char str1[33], str2[33];
    Init();
    while (scanf("%s%s", str1, str2), str1[0] != 'E')
    {

        Insert(str2, str1);//插入，单词，单词的翻译
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
                    if (Find(saveStr))
                    {
                        printf("%s", pNode->ansChar);//如果字典中存在该单词，则输出它的翻译
                    }
                    else
                    {
                        
                        printf("%s", saveStr);//字典中不存在该单词，输出原单词
                    }
                }

                printf("%c", ansStr[i]);
                
            }
            else
            {
                saveStr[k++] = ansStr[i];//保存单词
            }
        }
        puts("");
    }

    
    return 0;
}
