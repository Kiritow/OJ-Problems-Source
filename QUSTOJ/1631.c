#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char save[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
char maps[512];
char data[512];

int main()
{
	for ( int i = 1 ; save[i] ; ++ i )
		maps[save[i]] = save[i-1];
	
	while ( gets(data) ) {
		for ( int i = 0 ; data[i] ; ++ i )
			if ( data[i] == ' ' || data[i] == '	' )
				printf("%c",data[i]);
			else printf("%c",maps[data[i]]);
		printf("\n");	
	}
	return 0;
}
