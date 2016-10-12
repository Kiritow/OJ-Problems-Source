#include<stdio.h>
#include<string.h>
int main()
{
    char a[12][20], temp[20], name[20];// name,the number = the name
    int qian[20],shou[20],song[20];
    int m, r;// money the number of people
    int n, i, j, k, l;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0; i<n ; ++i)
        {
            scanf("%s", a[i]);
            qian[i]=0;
        }
 
        for(i=0; i<n; ++i)
        {
            scanf("%s", &name);
            for(l=0; l<n; ++l)
            {
                if(strcmp(name,a[l])!=0)
                    continue;
                else
                    scanf("%d%d", &m, &r);
                    if(r==0)
                    {
                        qian[l]=qian[l]+m;
                        song[l]=0;
                    }
                    else
                    {
                        qian[l]= qian[l]+ m%r - m;
                        song[l]= m/r;
                    }
                    for(j=0; j<r; ++j)
                    {
                        scanf("%s", &temp);
                        for(k=0; k<n; ++k)
                        {
                            if(strcmp(temp,a[k])==0)
                            {
                                qian[k]+=song[l];
                                break;
                            }
                        }
                    }
            }
                 
        }
        for(i=0; i<n; ++i)
            printf("%s %d\n", a[i], qian[i]);
    }
    return 0;
}
