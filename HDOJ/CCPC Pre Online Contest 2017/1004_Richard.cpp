// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include <cstdio>
#include <string>
#include <cmath>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define LL long long
//#define DEBUG
using namespace std;

const int MAXN = 1000005 ;
const long long mod = 1e9+7;
char s[2 * MAXN];
char t[MAXN];
char tmp[MAXN];
int ls;
int lt;
int nx[MAXN];
int nm[MAXN];
int mk[MAXN];
void getNext();
void kmp();

void init() {
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    memset(nx, 0, sizeof(nx));
    memset(nm, 0, sizeof(nm));
    memset(mk, 0, sizeof(mk));
}

//int KMP(char A[], char B[], int C[])
//{
//
//    int num = 0;
//    int Alen = strlen(A);
//    int Blen = strlen(B);
//
//    int i = 0;
//    int j = -1;
//    C[0] = -1;
//    while (i < Alen) {
//        if (B[i] == B[j] || j == -1) {
//            i++;
//            j++;
//            C[i] = j;
//        }
//        else
//            j = C[j];
//    }
//
//    i = 0;
//    j = 0;
//    while (i < Alen) {
//        if (j == -1 || A[i] == B[j]) {
//            i++;
//            j++;
//        }
//        else
//            j = C[j];
//        if (j == Blen)
//            num++;
//    }
//    return num;
//}
//拆分计算
void kmp() {

    int j = lt;
    for (int i = ls - 1; i >= 0; i--) {

        while (t[j - 1] != s[i] && j < lt) {
            j = nx[j];
            mk[lt - j]++;
        }
        if (t[j - 1] == s[i]) {
            j--;
            nm[lt - j]++;
        }
        if (j <= 0) {
            i += lt - j - 1;
            j = lt;
        }
#ifdef DEBUG
        printf("%c", nm[i]);
#endif 
    }
}
void getNext() {

    nx[lt - 1] = lt;
    for (int i = lt - 2; i >= 0; i--) {

        int j = nx[i + 1];

        while (t[j - 1] != t[i] && j < lt) {
            j = nx[j];
        }

        if (t[j - 1] == t[i]) {
            nx[i] = j - 1;
        }
        else {
            nx[i] = lt;
        }
#ifdef DEBUG
        printf("%c", nx[i]);
#endif 
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for(int c=0;c<T;c++){

        init();

        scanf("%s%s", tmp, t);

        lt = strlen(t);

        for (int i = 0; i < lt; i++)
            s[i] = ',';
        s[lt] = '\0';

        strcat(s, tmp);
        ls = strlen(s);
        getNext();
        kmp();
        long long sum = 0;
        int mem = 0;
        for (int i = lt; i > 0; i--) {
            mem += mk[i];
            sum += (LL)i * (LL)(nm[i] + mem)%mod;
            sum %= mod;
#ifdef DEBUG
            printf("%lld\n", sum);
#endif 
        }
        printf("%lld\n", sum);
    }
    return 0;
}