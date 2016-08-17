#include <stdio.h>
int calculate(int year, int month, int day);
int main()
{
    const char *weekdays[] =
    {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    const char *monthname[] =
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int year, month, day, week;
    while (scanf("%d%d%d", &month, &day, &year) != EOF)
    {
        if (year == 0 && month == 0 && day == 0)
            break;
        week = calculate(year, month, day);
        if (week == -1)
            printf("%d/%d/%d is an invalid date.\n", month, day, year);
        else
            printf("%s %d, %d is a %s\n", monthname[month - 1], day, year, weekdays[week]);
    }
    return 0;
}
int calculate(int year, int month, int day)
{
    int count, leap, century;
    static const int daycount[] =
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    if (year <= 0 || month > 12 || month < 1 || day < 1 || day > 31)
        return -1;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return -1;
    if (year <= 1752)
    {
        if (year == 1752 && month == 9 && day > 2 && day < 14)
            return -1;
        if (year % 4 == 0)
        {
            leap = 1;  
            if (month == 2)
            {
                if (day > 29)
                    return -1;
            }
        }
        else
        {
            leap = 0;
            if (month == 2)
            {
                if (day > 28)
                    return -1;
            }
        }
        count = (year - 1) * 365 + (year - 1) / 4;  
        count += daycount[month - 1] + day;
        if (leap && month > 2)  
            count += 1;
        if (year == 1752)  
        {
            if (month > 9 || (month == 9 && day >= 14))
                count -= 11;
        }
        return ((count + 5) % 7);
    }
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            leap = 1;  
            if (month == 2)
            {
                if (day > 29)
                    return -1;
            }
        }
        else
        {
            leap = 0;
            if (month == 2)
            {
                if (day > 28)
                    return -1;
            }
        }
        century = (year - 1) / 100 - 17;  
        count = (year - 1) * 365 + (year - 1) / 4;  
        count += (daycount[month - 1] + day);  
        count -= (11 + century);  
        count += (century + 1) / 4;  
        if (leap && month > 2) 
            count += 1;
        return ((count + 5) % 7);
    }
    return -1;
}
