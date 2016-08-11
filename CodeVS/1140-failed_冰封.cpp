// 我决定重构了！

#include<stdio.h>

long num ;
long res ;
long cnt ;
bool book[26] ;
char e[26] ;
int size ;

typedef struct {
    char a[5] ;
} ele ;

ele a[1000] ;

void dfs(int idx, ele n){
    if( idx >= num - 1 ){
        a[cnt] = n ;
        cnt++ ;
        return ;
    }
    for(int i = 0; i < size; i++){
        if(book[i]) continue ;
        book[i] = true ;
        n.a[idx] = e[i] ;
        dfs(idx + 1, n) ;
        book[i] = false ;
    }
}

int main(int argc, char** argv){

    // init book do
    for(auto int i = 0; i < 26; i++)
        book[i] = false;
    // end
    
    // init e and size do
    auto char from, to ;
    auto int aa, bb ;
    scanf("%i%i%li", &aa, &bb, &num) ;
    size = (int)(aa - bb) ;
    from = 'a' + --aa ;
    to   = 'a' + --bb ;
    for(char aaa = from;
            aaa < to; aaa++)
        e[aaa - from] = aaa ;
    // end

    // get in do
    auto char *in ;
    scanf("%s", in) ;
    // end
    
    // get the array do
    ele f ;
    dfs(0, f) ;
    // end
    
    int i ;
    for(i = 0; i < 1000; i++){
        int j ;
        for(j = 0; j < size; j++)
            if(a[i].a[j] != in[j]) break;
        if(j >= size)
            break ;
    }
    for(int i = 0; i < 5; i++){
        if(i >= cnt) break ;
        printf("%s\n", a[i].a) ;
    }
    while(1);
    return 0;
}
