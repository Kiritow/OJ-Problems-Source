#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

char buffer[1024];
int bucket[26];
bool cmp(const int& a,const int& b)
{
    return a>b;
}
int main()
{
    gets(buffer);
    int L=strlen(buffer);
    for(int i=0;i<L;i++) ++bucket[buffer[i]-'a'];
    sort(bucket,bucket+26,cmp);
    int sum=0;
    for(int i=2;i<26;i++) sum+=bucket[i];
    printf("%d\n",sum);
    return 0;
}
