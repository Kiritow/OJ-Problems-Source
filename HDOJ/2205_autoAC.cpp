#include<iostream>
#include<cstring>
using namespace std;
    char str[51],st[51];
    bool ar[51][51][51][51];
int main()
{
     int max,i,j,len1,len2,l1,l2;
    while (gets(str)&&gets(st))
    {
        len1=strlen(str);
        len2=strlen(st);
        memset(ar,0,sizeof(ar));
        max=0;
        for (i=0;i<=len1;i++)
            for (j=0;j<=len2;j++)
                ar[i][1][j][0]=ar[i][0][j][1]=ar[i][0][j][0]=true;
        for (l1=0;l1<=len1;l1++)
            for (l2=0;l2<=len2;l2++)
                for (i=0;i<=len1-l1;i++)
                    for (j=0;j<=len2-l2;j++)
                    {
                        if (!ar[i][l1][j][l2])
                            ar[i][l1][j][l2]=
                                l1>1&&ar[i+1][l1-2][j][l2]&&str[i]==str[i+l1-1]||
                                l2>1&&ar[i][l1][j+1][l2-2]&&st[j]==st[j+l2-1]||
                                l1>0&&l2>0&&ar[i][l1-1][j+1][l2-1]&&str[i+l1-1]==st[j]||
                                l1>0&&l2>0&&ar[i+1][l1-1][j][l2-1]&&str[i]==st[j+l2-1];
                                if (ar[i][l1][j][l2]&&l1+l2>max) max=l1+l2;
                    }
                    cout<<max<<endl;
    }
    return 0;
}
