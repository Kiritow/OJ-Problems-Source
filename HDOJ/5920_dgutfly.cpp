#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
const double eps=1e-8;
int len;
//大数乘法
void subtract(char *a,char *b,char *c)
{
    for(int i=len-1;i>=0;i--)
    {
        c[i]=a[i]-b[i]+'0';
        if(c[i]<'0')c[i]+=10,a[i-1]--;
    }
}

char str[2][1005],sub[50][1005];
int main()
{
    int i,j,k,n;
    scanf("%d",&n);getchar();
    for(int h=1;h<=n;h++)
    {
        memset(sub,'0',sizeof(sub));
        gets(str[0]);
        len=strlen(str[0]);
        int old=1,now=0;
        int cnt=0;
        for(i=0;str[now][i];)//前置0到末尾，整个数就是0
        {
            old^=1,now^=1;//滚动数组
            if(!strcmp(str[old]+i,"10"))//10=9+1
            {
                sub[cnt][0]='9';sub[cnt][1]=0;cnt++;
                sub[cnt][0]='1';sub[cnt][1]=0;cnt++;
                break;
            }
            for(j=i;j<=len-1-j+i && str[old][j]<=str[old][len-1-j+i];j++);
            strcpy(sub[cnt],str[old]);
            if(j<len-1-j+i)//对折后有小于的，就只能取较小的回文数
            {
                sub[cnt][(i+len-1)/2]--;
                for(j=(i+len-1)/2;j>=0 && sub[cnt][j]<'0';j--)sub[cnt][j]+=10,sub[cnt][j-1]--;
            }
            for(j=0;sub[cnt][j]=='0';j++);//去前导0
            for(k=j;k<=len-1-k+j;k++)sub[cnt][len-1-k+j]=sub[cnt][k];//根据前半串对折构造后半串
            sub[cnt][len]=0;
            subtract(str[old],sub[cnt],str[now]);
            for(;str[now][i]=='0';i++);
            cnt++;
        }
        printf("Case #%d:\n%d\n",h,cnt);
        for(i=0;i<cnt;i++)
        {
            char *s;
            for(s=sub[i];*s=='0';s++);
            puts(s);
        }
    }
    return 0;
}

ugly problem
