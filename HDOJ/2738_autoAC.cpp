#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 101
struct Term
{
    int s[maxn];
    char ch[maxn];
}term[maxn];
string word[maxn];
string st;
int n, m, termnum[maxn];
bool input()
{
    int i = 0;
    while (1)
    {
        getline(cin, word[i]);
        if (word[i] == "#")
            return false;
        if (word[i] == "*")
            break;
        i++;
    }
    n = i;
    return true;
}
void getterm(string &a, Term &term, int &num)
{
    int i = 0, j = 0;
    while (i < a.length())
    {
        if (a[i] != '-' && a[i] != '+')
        {
            term.ch[j] = a[i];
            term.s[j] = 1;
            i++;
            j++;
            continue;
        }
        if (a[i] == '-')
            term.s[j] = 0;
        if (a[i] == '+')
            term.s[j] = 2;
        i++;
        term.ch[j] = a[i];
        i++;
        j++;
    }
    num = j;
}
void maketerms()
{
    int temp;
    int i = 0;
    temp = st.find('|');
    while (temp != string::npos)
    {
        string sub = st.substr(0, temp);
        getterm(sub, term[i], termnum[i]);
        st.erase(0, temp + 1);
        i++;
        temp = st.find('|');
    }
    getterm(st, term[i], termnum[i]);
    m = i + 1;
}
bool match(string &word, Term &term, int &num)
{
    for (int i = 0; i < num; i++)
        if (term.s[i] == 0 && word.find(term.ch[i]) != string::npos)
            return false;
    for (int i = 0; i < num; i++)
        if (term.s[i] == 2 && word.find(term.ch[i]) == string::npos)
            return false;
    for (int i = 0; i < num; i++)
        if (term.s[i] == 1 && word.find(term.ch[i]) != string::npos)
            return true;
    return false;
}
int main()
{
        while (1)
    {
        if (!input())
            break;
        sort(word, word + n);
        while (getline(cin, st) && st != "**")
        {
            bool found = false;
            maketerms();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    if (match(word[i], term[j], termnum[j]))
                    {
                        found = true;
                        cout << word[i] << endl;
                        break;
                    }
                if (found)
                    break;
            }
            if (!found)
                cout << "NONE" << endl;
        }
        cout << "$" << endl;
    }
    return 0;
}
