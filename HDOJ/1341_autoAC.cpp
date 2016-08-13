#include <iostream>
#include <stdio.h>
using namespace std;
unsigned char ins[32], accu, pc;
char str[10];
unsigned char getValue(char *ins)
{
    unsigned char res(0);
    for(int i(0); i<8; ++i) res = res * 2 + ins[i] - '0';
    return res;
}
int main()
{
    bool halt;
    int type, value;
    while(scanf("%s", str) != EOF)
    {
        ins[0] = getValue(str);
        for(int i(1); i<32; ++i) scanf("%s", str), ins[i] = getValue(str);
        halt = false;
        pc = accu = 0;
        while(!halt)
        {
            type = ins[pc] >> 5;
            value = ins[pc] % 32;
            switch(type)
            {
                case 0:
                    ins[value] = accu;
                    pc = (pc + 1) % 32;
                    break;
                case 1:
                    accu = ins[value];
                    pc = (pc + 1) % 32;
                    break;
                case 2:
                    if(!accu) pc = value;
                    else pc = (pc + 1) % 32;
                    break;
                case 3:
                    pc = (pc + 1) % 32;
                    break;
                case 4:
                    --accu;
                    pc = (pc + 1) % 32;
                    break;
                case 5:
                    ++accu;
                    pc = (pc + 1) % 32;
                    break;
                case 6:
                    pc = ins[pc] % 32;
                    break;
                case 7:
                    halt = true;
                    break;
            }
        }
        for(int i(7); i>=0; --i)
            printf("%d", (accu >> i) & 1);
        printf("\n");
    }
    return 0;
}
