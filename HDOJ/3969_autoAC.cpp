#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int i, j, t, n, k;
    char team1[55], team2[55], tmp[122], tmp1[55][55], tmp2[55][55], fk[9];
    bool chuchang[3][13];
    int score[5], pts[5][55], off[5][55], def[5][55], reb[5][55], ast[5][55], pf[5][55], free[5][55][5], three[5][55][5], faqiu[55][55][5], stl[5][55], block[5][55];
    scanf("%d", &t);
    while(t--)
    {
        memset(chuchang, 0, sizeof(chuchang));
        memset(score, 0, sizeof(score));
        memset(pts, 0, sizeof(pts));
        memset(off, 0, sizeof(off));
        memset(def, 0, sizeof(def));
        memset(reb, 0, sizeof(reb));
        memset(ast, 0, sizeof(ast));
        memset(pf, 0, sizeof(pf));
        memset(free, 0, sizeof(free));
        memset(three, 0, sizeof(three));
        memset(faqiu, 0, sizeof(faqiu));
        memset(stl, 0, sizeof(stl));
        memset(block, 0, sizeof(block));
        map<string, int>teamnum;
        map<string, int>num;
        scanf("%s %s %s", team1, tmp, team2);
        for(i = 1; i <= 12; i++)
        {
            scanf("%s", tmp1[i]);
            string tmpname = tmp1[i];
            teamnum[tmpname] = 1;
            num[tmpname] = i;
        }
        for(i = 1; i <= 12; i++)
        {
            scanf("%s", tmp2[i]);
            string tmpname = tmp2[i];
            teamnum[tmpname] = 2;
            num[tmpname] = i;
        }
        scanf("%d", &n);
        string pre = "", now = "";
        bool ispass = 0,  twoout = 0, threeout = 0, fa = 0, fangui = 0;
        getchar();
        for(k = 0; k < n; k++)
        {
            gets(tmp);
            if(k == 0 || k == n - 1) continue;
            string str = tmp;
            if(str.find("Hold Ball") != -1)
            {
                int len = str.length() - 10;
                string tt = str.substr(0, len);
                now = tt;
                fangui = false;
            }
            else if(str.find("Pass to") != -1)
            {
                string tt = "";
                int len = str.length();
                for(i = 0; i < len; i++)
                {
                    if(str[i] == ' ') break;
                    else tt += str[i];
                }
                pre = tt;
                ispass = true;
                now = str.substr(pre.length() + 9);
            }
            else if(str.find("Layup") != -1 || str.find("Slam Dunk") != -1 || str.find("Hook Shot") != -1  || str.find("Jump Shot") != -1 )
            twoout = true;
            else if(str.find("3pt Shot") != -1)
            threeout = true;
            else if(str.find("Missed") != -1)
            {
                if(fa == true)
                {
                    faqiu[teamnum[now]][num[now]][2]++;
                    fa = false;
                }
                else if(twoout == true)
                {
                    if(!fangui) free[teamnum[now]][num[now]][2]++;
                    else fangui = false;
                    twoout = false;
                }
                else if(threeout == true)
                {
                    if(!fangui)
                    {
                        free[teamnum[now]][num[now]][2]++;
                        three[teamnum[now]][num[now]][2]++;
                    }
                    else fangui = false;
                    threeout = false;
                }
                ispass = false;
            }
            else if(str.find("Made") != -1)
            {
                if(fa == true)
                {
                    pts[teamnum[now]][num[now]]++;
                    score[teamnum[now]]++;
                    faqiu[teamnum[now]][num[now]][2]++;
                    faqiu[teamnum[now]][num[now]][1]++;
                    fa = false;
                }
                else if(twoout)
                {
                    pts[teamnum[now]][num[now]] += 2;
                    score[teamnum[now]] += 2;
                    free[teamnum[now]][num[now]][1]++;
                    free[teamnum[now]][num[now]][2]++;
                    if(ispass)
                    {
                        ast[teamnum[now]][num[pre]]++;
                        ispass = false;
                    }
                    twoout = false;
                }
                else if(threeout)
                {
                    pts[teamnum[now]][num[now]] += 3;
                    score[teamnum[now]] += 3;
                    free[teamnum[now]][num[now]][1]++;
                    free[teamnum[now]][num[now]][2]++;
                    three[teamnum[now]][num[now]][2]++;
                    three[teamnum[now]][num[now]][1]++;
                    if(ispass)
                    {
                        ast[teamnum[now]][num[pre]]++;
                        ispass = false;
                    }
                    threeout = false;
                }
                ispass = false;
            }
            else if(str.find("Rebound") != -1)
            {
                string tt = "";
                int len = str.length();
                for(i = 0; i < len; i++)
                {
                    if(str[i] == ' ') break;
                    else tt += str[i];
                }
                if(teamnum[tt] != teamnum[now])
                {
                    def[teamnum[tt]][num[tt]]++;
                    reb[teamnum[tt]][num[tt]]++;
                }
                else if(teamnum[tt] == teamnum[now])
                {
                    off[teamnum[tt]][num[tt]]++;
                    reb[teamnum[tt]][num[tt]]++;
                }
                now = tt;
                ispass = false;
                twoout = false;
                threeout = false;
            }
            else if(str.find("Blocked") != -1)
            {
                if(threeout)
                {
                    free[teamnum[now]][num[now]][2]++;
                    three[teamnum[now]][num[now]][2]++;
                    threeout = false;
                }
                else if(twoout)
                {
                    free[teamnum[now]][num[now]][2]++;
                    twoout = false;
                }
                string tt = str.substr(11);
                block[teamnum[tt]][num[tt]]++;
                ispass = false;
                twoout = false;
                threeout = false;
            }
            else if(str.find("Foul") != -1)
            {
                string tt = "";
                int len = str.length();
                for(i = 0; i < len; i++)
                {
                    if(str[i] == ' ') break;
                    else tt += str[i];
                }
                pf[teamnum[tt]][num[tt]]++;
                if(twoout || threeout)
                    fangui = true;
            }
            else if(str.find("Free Throw") != -1)
            {
                fa = true;
                ispass = false;
            }
            else if(str.find("Substitution") != -1)
            {
                int len = str.find("Substitution") + 25;
                string tt = str.substr(len);
                chuchang[teamnum[tt]][num[tt]] = 1;
                ispass = false;
                twoout = false;
                threeout = false;
            }
            else if(str.find("Timeout") != -1)
            ispass = false;
            else if(str.find("Jump Ball") != -1)
            ispass = false;
            else if(str.find("Steal") != -1)
            {
                string tt = "";
                int len = str.length();
                for(i = 0; i < len; i++)
                {
                    if(str[i] == ' ') break;
                    else tt += str[i];
                }
                stl[teamnum[tt]][num[tt]]++;
                now = tt;
                ispass = false;
            }
        }
        printf("%s %d-%d %s\n", team1, score[1], score[2], team2);
        printf("%s\n", team1);
        puts("              PLAYER PTS OFF DEF REB AST STL BLK PF FGM-A 3PM-A FTM-A");
        for(i = 1; i <= 12; i++)
        {
            if(i <= 5 || chuchang[1][i] == 1)
            {
                printf("%20s%4d%4d%4d%4d%4d%4d%4d%3d", tmp1[i], pts[1][i], off[1][i], def[1][i], reb[1][i], ast[1][i], stl[1][i], block[1][i], pf[1][i]);
                sprintf(fk, "%d-%d", free[1][i][1], free[1][i][2]);
                printf("%6s", fk);
                sprintf(fk, "%d-%d", three[1][i][1], three[1][i][2]);
                printf("%6s", fk);
                sprintf(fk, "%d-%d", faqiu[1][i][1], faqiu[1][i][2]);
                printf("%6s\n", fk);
            }
            else
            {
                printf("%20s", tmp1[i]);
                puts("          DNP - Coach's Decision");
            }
        }
        printf("%s\n", team2);
        puts("              PLAYER PTS OFF DEF REB AST STL BLK PF FGM-A 3PM-A FTM-A");
        for(i = 1; i <= 12; i++)
        {
            if(i <= 5 || chuchang[2][i] == 1)
            {
                printf("%20s%4d%4d%4d%4d%4d%4d%4d%3d", tmp2[i], pts[2][i], off[2][i], def[2][i], reb[2][i], ast[2][i], stl[2][i], block[2][i], pf[2][i]);
                sprintf(fk, "%d-%d", free[2][i][1], free[2][i][2]);
                printf("%6s", fk);
                sprintf(fk, "%d-%d", three[2][i][1], three[2][i][2]);
                printf("%6s", fk);
                sprintf(fk, "%d-%d", faqiu[2][i][1], faqiu[2][i][2]);
                printf("%6s\n", fk);
            }
            else
            {
                printf("%20s", tmp2[i]);
                puts("          DNP - Coach's Decision");
            }
        }
        puts("");
    }
    return 0;
}
