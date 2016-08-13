#include <stdio.h>
int leap(int year)
{
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
                return 1;
        }
        return 0;
}
int main()
{
        int T;
        scanf("%d", &T);
        int year, month, day;
        while (T--) {
                scanf("%d-%d-%d", &year, &month, &day);
                int sum = 365 * 18;
                for (int i = 1; i < 18; i++) {
                        sum += leap(i + year);
                }
                if (month <= 2) {
                        sum += leap(year);
                } else {
                        sum += leap(year + 18);
                }
                if (month == 2 && day == 29) {
                        printf("-1\n");
                } else {
                        printf("%d\n", sum);
                }
        }
        return 0;
}
