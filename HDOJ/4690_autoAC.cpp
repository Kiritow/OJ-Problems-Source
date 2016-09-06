#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <functional>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#include <ctime>
#include <iterator>
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
using namespace std;
string A[16][16] = {
    "NUL","SOH","STX","ETX","","HT","","DEL","","","","VT","FF","CR","SO","SI",
    "DLE","DC1","DC2","DC3","","","BS","","CAN","EM","","","IFS","IGS","IRS","IUS ITB",
    "","","","","","LF","ETB","ESC","","","","","","ENQ","ACK","BEL",
    "","","SYN","","","","","EOT","","","","","DC4","NAK","","SUB",
    "SP","","","","","","","","","","",".","<","(","+","|",
    "&","","","","","","","","","","!","$","*",")",";","",
    "-","/","","","","","","","","","",",","%","_",">","?",
    "","","","","","","","","","`",":","#","@","'","=","\"",
    "","a","b","c","d","e","f","g","h","i","","","","","","",
    "","j","k","l","m","n","o","p","q","r","","","","","","",
    "","~","s","t","u","v","w","x","y","z","","","","","","",
    "^","","","","","","","","","","[","]","","","","",
    "{","A","B","C","D","E","F","G","H","I","","","","","","",
    "}","J","K","L","M","N","O","P","Q","R","","","","","","",
    "\\","","S","T","U","V","W","X","Y","Z","","","","","","",
    "0","1","2","3","4","5","6","7","8","9","","","","","",""
};
string B[8][16] = {
"NUL",    "SOH",    "STX",    "ETX",    "EOT",    "ENQ",    "ACK",    "BEL",    "BS",    "HT",    "LF",    "VT",    "FF",    "CR",    "SO",    "SI",
"DLE",    "DC1",    "DC2",    "DC3",    "DC4",    "NAK",    "SYN",    "ETB",    "CAN",    "EM",    "SUB",    "ESC",    "IFS",    "IGS",    "IRS",    "IUS ITB",
"SP",    "!",    "\"",    "#",    "$",    "%",    "&",    "'",    "(",    ")",    "*",    "+",    ",",    "-",    ".",    "/",
"0",    "1",    "2",    "3",    "4",    "5",    "6",    "7",    "8",    "9",    ":",    ";",    "<",    "=",    ">",    "?",
"@",    "A",    "B",    "C",    "D",    "E",    "F",    "G",    "H",    "I",    "J",    "K",    "L",    "M",    "N",    "O",
"P",    "Q",    "R",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",    "Z",    "[", "\\","]","^","_",
"`",    "a",    "b",    "c",    "d",    "e",    "f",    "g",    "h",    "i",    "j",    "k",    "l",    "m",    "n",    "o",
"p",    "q",    "r",    "s",    "t",    "u",    "v",    "w",    "x",    "y",    "z",    "{",    "|",    "}",    "~",    "DEL"
};
map<pair<int,int>, pair<int,int> > coll;
int main(void)
{
    string sad;
    ios::sync_with_stdio(false);
    cin>>sad; coll.clear();
    string tmp; pair<int,int> so, to;
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16; ++j)
        {
            if (A[i][j]!="")
            {
                so.first=i, so.second=j;
                bool mrk = false;
                for (int k = 0; k < 8; ++k)
                {
                    for (int h = 0; h < 16; ++h)
                    {
                        if (A[i][j]==B[k][h])
                        {
                            mrk = true;
                            to.first=k,to.second=h;
                            coll[so] = to; break;
                        }
                    }
                    if (mrk) break;
                }
            }
        }
    }
    for (int i = 0; i < sad.size(); i+=2)
    {
        int X, Y; tmp.clear();
        if (sad[i]>='A'&&sad[i]<='F') X = sad[i]- 'A'+10;
        else X = sad[i] - '0';
        if (sad[i+1]>='A'&&sad[i+1]<='F') Y = sad[i+1]- 'A'+10;
        else Y = sad[i+1] - '0';
        pair<int,int> hehe, TM;
        hehe.first = X, hehe.second = Y;
        TM = coll[hehe];
        int j = TM.first, k = TM.second;
        char XX, YY;
        XX = j+ '0';
        if (k >= 10) YY = k - 10 + 'A';
        else YY = k + '0';
        printf("%c%c", XX, YY);
    }
    printf("\n");
    return 0;
}
