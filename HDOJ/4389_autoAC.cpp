Here is a function f(x):
int f ( int x ) {
    if ( x == 0 ) return 0;
    return f ( x / 10 ) + x % 10;
}
