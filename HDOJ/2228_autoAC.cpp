#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string ord[2];
string dfs(string ord)
{
 int i;
 if(ord == "01")return "01";
 ord = ord.substr(1,ord.length()-2);
 vector<string> subtree;
 int flag = 0,start = 0 ,end;
 for(i = 0 ; i < ord.length() ; i++ )
 {
 flag += ord[i] == '0' ? 1 : -1;
 if(!flag){
 end = i;
 subtree.push_back( dfs(ord.substr(start , end - start + 1)) );
 start = end + 1;
 }
 }
 sort(subtree.begin() , subtree.end() );
 string ret = "0";
 for(i = 0 ; i < subtree.size(); i ++)ret += subtree[i] ;
 ret += "1";
 return ret;
}
bool solve()
{
 if(dfs(ord[0]) == dfs(ord[1]))return true;
 else return false;
}
int main()
{
 int cas;
 char t[2][4000];
 scanf("%d",&cas);
 while(cas--)
 {
 t[0][0] = t[1][0] = '0';
 scanf("%s%s",t[0]+1,t[1]+1);
 ord[0] = string(t[0]) + "1" ; ord[1] = string(t[1]) + "1";
 if(solve())printf("True\n");
 else printf("False\n");
 }
 return 0;
}
