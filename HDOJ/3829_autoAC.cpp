#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 510
#define N 250010
int Head[M], Next[N], Key[N];
int match[M];
string like[M], dislike[M]; 
bool use[M];
int num;
int child;
void add(int u, int v) 
{
    Key[num] = v;
    Next[num] = Head[u];
    Head[u] = num++;
}
bool find(int u) 
{
    int temp;
    for(int i = Head[u]; i != -1; i = Next[i])
    {
        temp = Key[i];
        if(!use[temp])
        {
            use[temp] = true;
            if(match[temp] == -1 || find(match[temp]))
            {
                match[temp] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary() 
{
    int sum = 0;
    for(int i = 0; i < child; ++i)
    {
        memset(use, false, sizeof(use));
        if(find(i))
            sum++;
    }
    return sum;
}
int main()
{
    int cat, dog;
    string likeit, dislikeit;
    while(scanf("%d%d%d", &cat, &dog, &child) != EOF)
    {
        num = 0;
        memset(Head, -1, sizeof(Head));
        memset(match, -1, sizeof(match));
        for(int i = 0; i < child; ++i)
        {
            cin>>likeit>>dislikeit; 
            like[i] = likeit; 
            dislike[i] = dislikeit;
        }
        for(int i = 0; i < child; ++i) 
            for(int j = 0; j < child; ++j)
                if(like[i].compare(dislike[j]) == 0 || dislike[i].compare(like[j]) == 0) 
                    add(i, j);
        printf("%d\n", child - hungary() / 2); 
    }
    return 0;
}
