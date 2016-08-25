#include<cstdio>
#include<cstring>
#include<math.h>
#include<iostream>
using namespace std;
int n;
struct acc{
    int meb;
    int bam;
    double mo;
}arr[110];
int judge(int ac, int b){
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i].meb == ac && arr[i].bam == b)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int i;
    char cao[100];
    while(cin >> n)
    {
        if(n == 0)
        {
            cout << "goodbye" << endl;
            break;
        }
        char s;
        for(i = 0; i < n; i++)
        {
            scanf("%d%c%d%lf", &arr[i].meb, &s, &arr[i].bam, &arr[i].mo);
        }
        while(1){
            scanf("%s", cao);
            int l = strlen(cao);
            if(strcmp(cao, "end") == 0)
                break;
            int ac, bank;
            double money;
            if(cao[0] == 'c')
            {
                scanf("%d%c%d", &ac, &s, &bank);
                if(judge(ac, bank) == -1)
                {
                    arr[n].meb = ac;
                    arr[n].bam = bank;
                    arr[n++].mo = 0.0;
                    cout << "create: ok" << endl;
                }
                else
                {
                    cout << "create: already exists" << endl;
                }
            }
            else if(cao[0] == 'd')
            {
                scanf("%d%c%d%lf", &ac, &s, &bank, &money);
                int num = judge(ac, bank);
                if(num == -1)
                {
                    printf("deposit %.2lf: no such account\n", money);
                }
                else{
                    arr[num].mo += money;
                    printf("deposit %.2lf: ok\n", money);
                }
            }
            else if(cao[0] == 'w')
            {
                scanf("%d%c%d%lf", &ac, &s, &bank, &money);
                int num = judge(ac, bank);
                if(num == -1){
                    printf("withdraw %.2lf: no such account\n", money);
                }
                else{
                    if(arr[num].mo < money)
                    {
                        printf("withdraw %.2lf: insufficient funds\n", money);
                    }
                    else{
                        arr[num].mo -= money;
                        printf("withdraw %.2lf: ok\n", money);
                    }
                }
            }
            else if(cao[0] == 't')
            {
                int ac1, bank1;
                char s1;
                scanf("%d%c%d%d%c%d%lf", &ac, &s, &bank, &ac1, &s1, &bank1, &money);
                int num = judge(ac, bank);
                int num1 = judge(ac1, bank1);
                if(num == -1 || num1 == -1){
                    printf("transfer %.2lf: no such account\n", money);
                }
                else{
                    if(arr[num].meb == arr[num1].meb && arr[num].bam == arr[num1].bam)
                    {
                        printf("transfer %.2lf: same account\n", money);
                    }
                    else if(arr[num].mo < money)
                    {
                        printf("transfer %.2lf: insufficient funds\n", money);
                    }
                    else{
                        arr[num].mo -= money;
                        arr[num1].mo += money;
                        if(arr[num].bam == arr[num1].bam)
                        {
                            printf("transfer %.2lf: ok\n", money);
                        }
                        else{
                            printf("transfer %.2lf: interbank\n", money);
                        }
                    }
                }
            }
        }
        cout << "end" << endl << endl;
    }
    return 0;
}
