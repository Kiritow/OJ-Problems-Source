#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int data[4];
char buff[32];
char cmdline[10240];
int strlenx(const char* inc)
{
    int i=0;
    while(inc[i]!='\0') i++;
    return i;
}
//Kiritow's Quick sort function : written on Nov. 2ND ,rewritten on Nov. 10TH
//Updated Version : QuickSort (Build 2)
template <class T>
void quicksort(T* a,int left,int right)
{
    if(left>=right) return;
    T keyvalue=a[left];
    int i=left,j=right;
    while(i<j)
    {
        while(i<j&&a[j]>=keyvalue)
        {
            j--;
        }
        while(i<j&&a[i]<=keyvalue)
        {
            i++;
        }
        T tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
    if(i==j)
    {
        T tmp=a[left];
        a[left]=a[i];
        a[i]=tmp;
    }
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
int main()
{
    //I know there's a better way to do this. But I am not happy now. So I won't think anything.
    for(int i=1;i<26;i++)
    {
        for(int j=1;j<26;j++)
        {
            for(int k=1;k<26;k++)
            {
                for(int x=1;x<26;x++)
                {
                    if(i+j+k+x==26)
                    {
                        if(i*j*k*x==880)
                        {
                            data[0]=i;
                            data[1]=j;
                            data[2]=k;
                            data[3]=x;
                            quicksort(data,0,3);
                            int diff=data[1]-data[0];
                            for(int p=0;p<20;p++)
                            {
                                sprintf(buff,"%d ",data[0]);
                                strcat(cmdline,buff);
                                data[0]+=diff;
                            }
                            cmdline[strlenx(cmdline)-1]='\0';
                            puts(cmdline);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}
