#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[300];
int len;
bool flag;
bool OK( int x,int y ){
    if( x == y ){
        if( s[x] >= 'p' && s[x] <= 'z' )
            return true;
        else return false;
    }
    if( s[x] == 'N' ){
        if( OK(x+1,y) )
            return true;
        else return false;
    }
    if( s[x] == 'C' || s[x] == 'D' || s[x] == 'E' || s[x] == 'I' ){
        for( int i = x+1 ; i <= y ; ++i )
            if( OK(x+1,i) && OK(i+1,y) )
                return true;
        return false;
    }
    return false;
}
int main(){
    while(scanf("%s",s)!=EOF){
        flag = false;
        len = strlen(s);
        if( len == 1 && ( s[0] >= 'p' && s[0] <= 'z' ) )
            flag = true;
        else{
            if( OK(0,len-1) )
                flag = true;
        }
        if( flag )
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
