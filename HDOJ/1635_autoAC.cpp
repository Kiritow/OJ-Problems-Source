#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
static int aMDays[] =  {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
static int aMDaysL[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
bool LeapYear(int Year, bool bNew) {
    if (bNew) {
        return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
    }
    return (Year % 4 == 0);
}
int Date2Days(int Year, int Month, int Date, bool bNew) {
    --Year; 
    int Days = Year * 365 + Year / 4 + (bNew ? (Year / 400 - Year / 100) : 0);
    Days += ((Month > 2) ? LeapYear(Year + 1, bNew) : 0);
    return (Days + aMDays[Month - 1] + Date - 1 - (!bNew * 2));
}
int main(void) {
    const static string aDays[] = {"Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday", "Saturday"};
    const static string aMonths[] = {"January", "February", "March",
        "April", "May", "June", "July", "August", "September",
        "October", "November", "December"};
    const int nDays400Y = 400 * 365 + 100 - 3;
    const int nDays100Y = 100 * 365 + 25 - 1;
    const int nDays4Y = 4 * 365 + 1, nDays1Y = 365;
    for (string str; cin >> str && str != "#";) {
        int Day, Date, Month, Year;
        Day = find(&aDays[0], &aDays[7], str) - &aDays[0];
        cin >> Date >> str >> Year;
        Month = find(&aMonths[0], &aMonths[12], str) - &aMonths[0] + 1;
        int nDays = Date2Days(Year, Month, Date, false);
        bool bOld2New = true; 
        if (Day == (nDays + 1) % 7) {
            Year = nDays / nDays400Y * 400; 
            nDays %= nDays400Y;
            if (nDays == nDays100Y * 4) { 
                Year += 300;
                nDays -= nDays100Y * 3;
            }
            else {
                Year += nDays / nDays100Y * 100;
                nDays %= nDays100Y; 
            }
        } 
        else {
            nDays = Date2Days(Year, Month, Date, true) + 2;
            Year = bOld2New = 0;
        }
        Year += nDays / nDays4Y * 4;
        nDays %= nDays4Y;
        if (nDays == nDays1Y * 4) { 
            Year += 3;
            nDays -= nDays1Y * 3;
        }
        else {
            Year += nDays / nDays1Y;
            nDays %= nDays1Y; 
        }
        int *pMDays = (LeapYear(++Year, bOld2New) ? aMDaysL : aMDays);
        for (Month = 0; Month < 12 && pMDays[Month] <= nDays; ++Month);
        Date = nDays - pMDays[Month - 1] + 1;
        Day = (Date2Days(Year, Month, Date, bOld2New) + 1) % 7;
        cout << aDays[Day] << ' ' << Date << (bOld2New ? " " : "* ");
        cout << aMonths[Month - 1] << ' ' << Year << endl;
    }
    return 0;
}
