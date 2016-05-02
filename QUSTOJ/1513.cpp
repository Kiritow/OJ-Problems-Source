//Problem1513
#include <cstdio>
#include <cstring>
using namespace std;
char buff[256];
int main()
{
	while(scanf("%s",buff)==1)
	{
		int len=strlen(buff);
		for(int i=0;i<len;i++)
		{
			if(buff[i]>='A'&&buff[i]<='Z')
			{
				buff[i]=(buff[i]-'A'+1)%26+'a';
			}
			else if(buff[i]>='a'&&buff[i]<='z')
			{
				char ans;
				switch(buff[i])
				{
					case 'a':case 'b':case 'c':ans='1';break;
					case 'd':case 'e':case 'f':ans='2';break;
					case 'g':case 'h':case 'i':ans='3';break;
					case 'j':case 'k':case 'l':ans='4';break;
					case 'm':case 'n':case 'o':ans='5';break;
					case 'p':case 'q':case 'r':case 's':ans='6';break;
					case 't':case 'u':case 'v':ans='7';break;
					case 'w':case 'x':case 'y':case 'z':ans='8';break;
				}
				ans++;
				buff[i]=ans;
			}
		}
		printf("%s\n",buff);
	}
}
