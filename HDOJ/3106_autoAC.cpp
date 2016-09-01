#include<cstdio>
#include<cstdlib>
#include<cstring>
char a[1000];
char einput[1000]="JOKER";
int gnum(char x){
    if(x == 'K')    return 10;
    if(x == 'Q')    return 10;
    if(x == 'J')    return 10;
    if(x == 'T')    return 10;
    if(x == 'A')    return 1;
    return int(x) - 48;
} 
int len;
int p, d;
int tp, td;
int sum;
bool flagp, flagd;
bool ans;
int getp(int s, int t, bool flag){
    int result = p;
    for(int i = s; i <= t; i++){
        if(a[i] == 'A')
            flag  = true;
        result += gnum(a[i]);
    }
    if(result <= 11 && flag)
        result += 10;
    return result;
}
int getd(int s, int t, bool flag){
    int result = d;
    if(result >= 17)
        return result;
    if(flag && result <= 11 && result + 10 >= 17)
        return result + 10;
    for(int i = s; i <= t; i++)
        if(result < 17){
            if(a[i] == 'A')
                flag = true;
            result += gnum(a[i]);
            if(flag && result <= 11 &result + 10 >= 17)
                return result + 10;
        }
        else 
            return result;
        return result;
}
int main(){
    while(1){
        memset(a, 0, sizeof(a));
        fgets(a, 1000, stdin);
        flagp = false;
        flagd = false;
        ans = false;
        if(a[strlen(a) - 1] == '\n')
            a[strlen(a) - 1] = '\0';
        len = strlen(a);
        if(strcmp(a, einput) == 0)
            break;
        p = gnum(a[0]) + gnum(a[2]);
        d = gnum(a[1]) + gnum(a[3]);
        if(a[0] == 'A')
            flagp = true;
        if(a[2] == 'A')
            flagp = true;
        if(a[1] == 'A')
            flagd = true;
        if(a[3] == 'A')
            flagd = true;
        if(len == 4){
            if(flagp && p <= 11)
                p += 10;
            if(flagd && d <= 11)
                d += 10;
            if(p>=d)
                printf("Yes\n");
            else
                printf("No\n"); 
        }
        else{
            sum = p;
            ans = false;
            tp = p;
            if(flagp && tp <= 11)
                tp += 10;
            td = getd(4, len-1, flagd);
            if(tp <= 21)
                if(tp >= td || td > 21)
                {
                    ans = true;
                }
            for(int i = 4; i <= len - 1; i++){
                if(ans)
                    break;
                sum += gnum(a[i]);
                if(sum > 21)
                    break;
                tp = getp(4, i , flagp);
                td = getd(i + 1, len -1, flagd);
                if(tp <= 21)
                    if(tp >= td || td > 21){
                        ans = true;
                        break;
                    } 
            }
            if(ans)
                printf("Yes\n");
            else
                printf("No\n"); 
        }
    }
    return 0;
}
