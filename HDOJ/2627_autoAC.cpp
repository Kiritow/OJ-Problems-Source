#include<stdio.h>
int main()
{
    int t,n,i;
    char a[100];
    int b[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        scanf("%s",a);
        int sum=0,p=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            if(a[i]=='1')
            {
                p++;
                sum+=b[i];
            }
        }
        printf("Samuel was accused with %d case(s),",p);
        if(sum==0)printf("and he will stay in the prison for 0 year(s).\n");
        else if(sum>0&&sum<20)printf("and he will stay in the prison for 3 year(s).\n");
        else if(sum>=20&&sum<30)printf("and he will stay in the prison for 5 year(s).\n");
        else if(sum>=30&&sum<40)printf("and he will stay in the prison for 10 year(s).\n");
        else if(sum>=40&&sum<50)printf("and he will stay in the prison for 15 year(s).\n");
        else if(sum>=50&&sum<60)printf("and he will stay in the prison for 20 year(s).\n");
        else if(sum>=60&&sum<70)printf("and he will stay in the prison for 25 year(s).\n");
        else if(sum>=70&&sum<80)printf("and he will stay in the prison for 30 year(s).\n");
        else if(sum>=80&&sum<90)printf("and he will stay in the prison for 35 year(s).\n");
        else
            printf("and he will stay in the prison for 40 year(s).\n");
    }
    return 0;
}
