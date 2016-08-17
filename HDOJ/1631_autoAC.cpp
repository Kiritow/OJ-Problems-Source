#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum SYMBOL{A, MOD, LA, BA, DA, PREDA, NAM, SE, PC, P, PN, PS, ST, VP, PV, UN};
bool aVowel[] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0}; 
static SYMBOL aConvTbl[14][4] = { 
    {PREDA, UN, PREDA, PREDA}, {PREDA, UN, UN, PS}, {NAM, UN, UN, PN},
    {LA, UN, PS, PN}, {MOD, UN, PS, VP}, {A, PS, PS, PS}, {PS, UN, UN, P},
    {DA, UN, P, PC}, {BA, PN, P, PC}, {VP, PN, UN, PV}, {PV, UN, PN, ST},
    {PV, UN, UN, ST}, {PC, UN, UN, SE}, {ST, UN, UN, SE}, 
}; 
SYMBOL Token2Status(const string &str) {
    int nNum = str.length(), cLast = str[nNum - 1];
    if (!islower(cLast) || !aVowel[cLast - 'a']) {
        return NAM; 
    }
    switch (nNum) {
    case 1: return A; 
    case 5:
        nNum = aVowel[str[4] - 'a'];
        nNum |= ((aVowel[str[0] - 'a'] << 4) | (aVowel[str[1] - 'a'] << 3));
        nNum |= ((aVowel[str[2] - 'a'] << 2) | (aVowel[str[3] - 'a'] << 1));
        return (nNum == 5 || nNum == 9) ? PREDA : UN;
    case 2: 
        switch (str[0]) { 
        case 'g': return MOD;
        case 'b': return BA;
        case 'd': return DA;
        case 'l': return LA;
        }
    }
    return UN; 
}
int main(void) {
    vector<SYMBOL> Set;
    for (string str; cin >> str && str != "#";) { 
        int nDot = str.find('.'); 
        if (nDot == str.npos) { 
            Set.push_back(Token2Status(str)); 
            continue;
        } 
        str.erase(str.length() - 1); 
        if (!str.empty()) { 
            Set.push_back(Token2Status(str));
        } 
        for (int i = 0; i < 14; ++i) { 
            SYMBOL *pTbl = aConvTbl[i]; 
            for (vector<SYMBOL>::iterator j = Set.begin(); j != Set.end();) {
                vector<SYMBOL>::iterator iBeg = Set.begin(), iEnd = Set.end();
                if (*j != pTbl[0]) {
                    ++j; 
                    continue;
                } 
                if (pTbl[1] != UN && (j == iBeg || *(j - 1) != pTbl[1])) {
                    ++j; 
                    continue;
                }
                if (pTbl[2] != UN && (j == iEnd - 1 || *(j + 1) != pTbl[2])) {
                    ++j; 
                    continue;
                }
                j = pTbl[1] != UN ? Set.erase(j - 1) : j;
                j = pTbl[2] != UN ? Set.erase(j + 1) - 1 : j;
                *j = pTbl[3]; 
            }
        }
        cout << (Set.size() == 1 && Set[0] == SE ? "Good" : "Bad!") << endl;
        Set.clear(); 
    }
    return 0;
}
