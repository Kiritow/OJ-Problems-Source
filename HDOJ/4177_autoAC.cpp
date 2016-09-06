#include <stdio.h>
inline int ab(int x) { return x >= 0 ? x : -x ;}
int cal(int x,int y,int z,int &k)
{
    if(ab(x-y)==ab(y-z)) {
        k = y; return ab(x-y);
    }
    else if(ab(x-z)==ab(y-z)) {
        k = z; return ab(x-z);
    }
    else if(ab(x-y)==ab(z-x)) {
        k = x; return ab(x-y);
    }
    else { k = -1 ; return -1;}
}
int tx[8] , ti[8];
int h[4] , m[4] , re[4];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int re[4] , dis;
        for(int i=1;i<=3;i++){
            scanf("%d:%d",&h[i],&m[i]);
        }
        for(int i=1;i<=3;i++)
        {
            re[i] = h[i]*60+m[i];
        }
        int ok = 0;
        tx[1] = cal(re[1],re[2],re[3],ti[1]);
        tx[2] = cal(re[1]+720,re[2],re[3],ti[2]);
        tx[3] = cal(re[1],re[2]+720,re[3],ti[3]);
        tx[4] = cal(re[1],re[2],re[3]+720,ti[4]);
        tx[5] = cal(re[1]-720,re[2],re[3],ti[5]);
        tx[6] = cal(re[1],re[2]-720,re[3],ti[6]);
        tx[7] = cal(re[1],re[2],re[3]-720,ti[7]);
        for(int i=1;i<=7;i++)
        {
            if(tx[i] > 0) 
            {
                ok = 1;
                if(tx[i] == 4*60) {
                    printf("Look at the sun\n");
                    break;
                }
                else {
                    printf("The correct time is %d:%02d\n",
                        ti[i]/60,ti[i]%60);
                    break;
                }
            }
        }
        if(!ok) printf("Look at the sun\n");
    }
    return 0;
}
