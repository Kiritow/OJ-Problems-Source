#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1010;
struct BID{
    char name[25], type[5];
    double price;
};
BID bid[MAX], buy[MAX], sell[MAX];
int main(){
    int N, flag;
    char issuer[12];
    while(scanf("%d%s", &N, issuer) != EOF && N)
    {
        int cntb = 0, cnts = 0;
        for(int i = 0; i < N; ++i)
        {
            scanf("%s%s%lf", bid[i].name, bid[i].type, &bid[i].price);
            if(strcmp(bid[i].type, "buy") == 0)
                buy[cntb++] = bid[i];
            if(strcmp(bid[i].type, "sell") == 0)
                sell[cnts++] = bid[i];
        }
        printf("%s\n", issuer);
        for(int i = 0; i < N; ++i)
        {
            flag = 0; printf("%s:", bid[i].name);
            if(strcmp(bid[i].type, "buy") == 0)
            {
                for(int j = 0; j < cnts; ++j)
                {
                    if(sell[j].price <= bid[i].price)
                    {
                        printf(" %s", sell[j].name);
                        flag = 1;
                    }
                }
            }
            if(strcmp(bid[i].type, "sell") == 0)
            {
                for(int j = 0; j < cntb; ++j)
                {
                    if(buy[j].price >= bid[i].price)
                    {
                        printf(" %s", buy[j].name);
                        flag = 1;
                    }
                }
            }
            if(!flag)
                printf(" NO-ONE");
            printf("\n");
        }
    }
    return 0;
}
