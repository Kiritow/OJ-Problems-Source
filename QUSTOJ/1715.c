#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// itoa implement
char* int2str(int num,char* buff,int bina)
{
	char k[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	if(bina==10)
	{
		sprintf(buff,"%d",num);
		return buff;
	}
	int cnt=0;
	while(num>0)
	{
		buff[cnt]=k[num%bina];
		num=num/bina;
		cnt++;
	}
	buff[cnt]=0;
	for(int i=0;i<cnt/2;i++)
	{
	    char t=buff[i];
	    buff[i]=buff[cnt-i-1];
	    buff[cnt-i-1]=t;
	}
	return buff;
}

char buff[32];
int a,b;
int main()
{
    scanf("%d %d",&a,&b);
    printf("%s\n",int2str(a,buff,b));
    return 0;
}
