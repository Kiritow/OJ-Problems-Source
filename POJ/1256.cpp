#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char buff[1024];

//vector<string> vec;

bool cmp(const char& a,const char& b)
{
    char c=a>='a'?a-'a':a-'A';
    char d=b>='a'?b-'a':b-'A';
    if(c!=d) return c<d;
    else return a<b;
}

int main()
{
    int t;
    scanf("%d%*c",&t);
    for(int i=0;i<t;i++)
    {
        gets(buff);
        string str(buff);
        sort(str.begin(),str.end(),cmp);
        ////What? You mean this is needn't?
        //if(find(vec.begin(),vec.end(),str)!=vec.end()) continue;
        //vec.push_back(str);
        printf("%s\n",str.c_str());
        while(next_permutation(str.begin(),str.end(),cmp))
        {
            printf("%s\n",str.c_str());
        }
    }
    return 0;
}
