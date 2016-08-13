//日期函数
char *week[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date { int y, m, d; };
//判闰年
inline int leap(int y) {
  return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
//判合法性
inline bool legal(Date &a) {
  if (a.m < 0 || a.m > 12) { return false; }
  if (a.m == 2) { return a.d > 0 && a.d <= 28 + leap(a.y); }
  return a.d > 0 && a.d <= days[a.m - 1];
}
//比较日期大小
inline int datecmp(Date &a, Date &b) {
  if (a.y != b.y) { return a.y - b.y; }
  if (a.m != b.m) { return a.m - b.m; }
  return a.d - b.d;
}
//返回指定日期是星期几
int DaysOfTheWeek(Date a) {
  if (a.m == 1 || a.m == 2) { a.m += 12; a.y--; } //1月2月当作前一年的13, 14月
  //判断是否在1752年9月3日之前
  if (a.y < 1752 || (a.y == 1752 && a.m < 9) || (a.y == 1752 && a.m == 9 && a.d < 3)) {
    return (a.d + 2 * a.m + 3 * (a.m + 1) / 5 + a.y + a.y / 4 + 5) % 7;
  } else {
    return (a.d + 2 * a.m + 3 * (a.m + 1) / 5 + a.y + a.y / 4 - a.y / 100 + a.y / 400) % 7;
  }
}
//日期转天数偏移
int date2int(Date a) {
  int ret = a.y * 365 + (a.y - 1) / 4 - (a.y - 1) / 100 + (a.y - 1) / 400;
  days[1] += leap(a.y);
  for (int i = 0; i < a.m - 1; ret += days[i++]);
  days[1] = 28;
  return ret + a.d;
}
//天数偏移转日期
Date int2date(int a) {
  Date ret; ret.y = a / 146097 * 400;
  for (a %= 146097; a >= 365 + leap(ret.y); a -= 365 + leap(ret.y), ret.y++);
  days[1] += leap(ret.y);
  for (ret.m = 1; a >= days[ret.m - 1]; a -= days[ret.m - 1], ret.m++);
  days[1] = 28; ret.d = a + 1;
  return ret;
}
