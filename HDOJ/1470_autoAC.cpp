#include<iostream>
#include<string.h>
using namespace std;
#define N 55
#define M 10
int people[M];
int brith[M];
int n;
int ok;
int FP;
int now[M];
int yes[M];
struct say{
    char talk;
    char name;
    int bo;
    int sex;
};
void thesome()
{
    for(int i = 0; i < 6; i++)
        if(now[i] != people[i])
            yes[i] = 1;
}
int ture_say(say f)
{
    if(f.sex != -1)
    {
        if(f.name == 'T')
        {
            if(f.bo && f.sex - 4 == people[0])
                return 1;
            else if(!f.bo && f.sex - 4 != people[0])
                return 1;
            else
                return 0;
        }
        else
        {
            int id = f.name - 'A' + 1;
            if(f.bo && f.sex == people[id])
                return 1;
            else if(!f.bo && f.sex != people[id])
                return 1;
            else
                return 0;
        }
    }
    else
    {
        int id = f.name - 'A' + 1;
        if(people[id] == 3 && !f.bo)
            return 1;
        else if (people[id] == 1 && f.bo)
            return 1;
        else if(people[id] == 2)
        {
            if(people[0] && !f.bo)
                return 1;
            else if(!people[0] && f.bo)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
}
int write(char str[])
{
    if(strncmp(str, "divine.", 7) == 0)
        return 3;
    else if(strncmp(str, "human.", 6) == 0)
        return 2;
    else if(strncmp(str, "evil.", 5) == 0)
        return 1;
    else if(strncmp(str, "day.", 4) == 0)
        return 5;
    else if( strncmp(str, "night.", 6) == 0)
        return 4;
    else if( strncmp(str, "lying.", 6) ==0)
        return -1;
}
void read(say tem[])
{
    char str[M];
    int id;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        tem[i].talk = str[0];
        id = str[0] - 'A' + 1;
        brith[id] = 1;
        cin >> str;
        if(strcmp(str, "It") == 0)
            tem[i].name = 'T';
        else if(str[0] == 'I')
            tem[i].name = tem[i].talk;
        else
        {
            tem[i].name = str[0];
            id = str[0] - 'A' + 1;
            brith[id] = 1;
        }
        cin >> str;
        cin >> str;
        if(strcmp(str, "not"))
        {
            tem[i].bo = 1;
            tem[i].sex = write(str);
        }
        else
        {
            tem[i].bo = 0;
            cin >> str;
            tem[i].sex = write(str);
        }
    }
}
int judge(say tem[])
{
    for(int i = 0; i < n; i++)
    {
        int id = tem[i].talk - 'A' + 1;
        if(people[id] == 3)
        {
            if(ture_say(tem[i]))
                continue;
            else
                return 0;
        }
        else if(people[id] == 2)
        {
            int f = ture_say(tem[i]);
            if( (people[0] && f) || (!people[0] && !f) )
                continue;
            else
                return 0;
        }
        else if(people[id] == 1)
        {
            if(!ture_say(tem[i]))
                continue;
            else
                return 0;
        }
    }
    return 1;
}
void build(int k, say tem[])
{
    if(k < 6)
    {
        if(brith[k])
        {
            for(people[k] = 1; people[k] < 4; people[k]++)
                build(k + 1, tem);
        }
        else
            build(k + 1, tem);
    }
    else if(judge(tem))
    {
        if(ok >= 1)
            thesome();
        else
            for(int i = 0; i < 6; i++)
                now[i] = people[i];
        ok++;
    }
}
int main()
{
    int t = 1;
    while(cin >> n, n)
    {
        memset(people, 0, sizeof(people));
        memset(brith, 0, sizeof(brith));
        ok = 0;
        say tem[N];
        memset(yes, 0,sizeof(yes));
        read(tem);
        cout << "Conversation #" << t++ << endl;
        for(people[0] = 0; people[0] < 2; people[0]++)
            build(1, tem);
        if(ok == 0)
            cout << "This is impossible." << endl;
        else
        {
            //*
            int oi = 0;
            for(int i = 1; i < 6; i++)
            {
                if(!yes[i] && now[i])
                {
                    oi++;
                    char c = 'A' + i - 1;
                    if(now[i] == 3)
                        cout << c << " is divine." << endl;
                    else if(now[i] == 2)
                        cout << c << " is human." << endl;
                    else if(now[i] == 1)
                        cout << c << " is evil." << endl;
                }
            }
            if(oi == 0 && yes[0])
                cout << "No facts are deducible." << endl;
            if(now[0] && !yes[0])
                cout << "It is day." << endl;
            else if(!yes[0])
                cout << "It is night." << endl;
        }
        cout << endl;
    }
    return 0;
}
