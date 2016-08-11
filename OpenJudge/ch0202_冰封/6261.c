#include <stdio.h>

int i=1;
void move(int n,char from,char to)
{
	printf("%c->%d->%c\n",from,n,to);
	i++;
}

void hanoi(int n,char from,char denpend_on,char to)
{
    if (n==1)
    move(1,from,to);
	else
	{
      hanoi(n-1,from,to,denpend_on);
	  move(n,from,to);
	  hanoi(n-1,denpend_on,from,to);
	}
}

int main(void)
{
   	char c1,c2,c3;
	 int n;
	 scanf("%d %c %c %c",&n,&c1,&c2,&c3);
	 hanoi(n,c1,c3,c2);
	 return 0;
}
