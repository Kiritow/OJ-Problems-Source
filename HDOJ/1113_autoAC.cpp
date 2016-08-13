#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int power[26] = {1}, dic[105], p = 0;
char source[105][7], rem[105][7];
bool comp (const int x, const int y) {
     return strcmp (rem[x], rem[y]) < 0;
}
int main () {
    int len;
    char tmp[7];
    for (int i = 1; i < 26; i++)
        power[i] = power[i-1]*2;
    while (true) {
          dic[++p] = 0;
          scanf ("%s", tmp);
          if (strcmp (tmp, "XXXXXX") == 0)
             break;
          strcpy (source[p], tmp);
          len = strlen (tmp);
          for (int i = 0; i < len; i++)
              dic[p] += power[tmp[i]-'a'];
    }
    while (true) {
          int value = 0, pm = 0, situ[105];
          sizeof (rem, '\0', sizeof (rem));
          scanf ("%s", tmp);
          if (strcmp (tmp, "XXXXXX") == 0)
             break;
          len = strlen (tmp);
          for (int i = 0; i < len; i++)
              value += power[tmp[i]-'a'];
          for (int i = 1; i <= p; i++)
              if (value == dic[i])
                 strcpy (rem[++pm], source[i]);
          if (pm == 0) {
             printf ("NOT A VALID WORD\n******\n");
             continue;
          }
          for (int i = 1; i <= pm; i++)
              situ[i] = i;
          sort (situ+1, situ+pm+1, comp);
          for (int i = 1; i <= pm; i++)
              printf ("%s\n", rem[situ[i]]);
          printf ("******\n");
    }
    return 0;
}
