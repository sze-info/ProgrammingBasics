#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

struct date {
  int day, month, year;
};

bool leap(int year) { // leap year detection
  return (year%4==0 and year%100!=0) or year%400==0;
}

int daysOfMonth(int year, int month) { // returns the days
  int ad[12] =               // in a given month of a year
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if(month == 2) {
    if(leap(year)) return 29; else return 28;
  } else {
    return ad[month-1];
  }
}

bool check(struct date d) { // content validation
  if(d.month<1 or d.month>12) return false;
  int days = daysOfMonth(d.year, d.month);
  if(d.day<1 or d.day>days) return false;
  return true;
}

int dayOfYear(struct date d) { // determining the day of the year
  int days = d.day;            // based on year, month and day
  for(int month=1; month<d.month; month++) {
    days += daysOfMonth(d.year, month);
  }
  return days;
}

int base(struct date d) { // days elapsed since 01.01.0000
  int b = 0;
  for(int year=0; year<d.year; year++) {
    b += 365 + leap(year);
  }
  for(int month=1; month<d.month; month++) {
    b += daysOfMonth(d.year, month);
  }
  b += d.day;
  return b;
}

int difference(struct date begin, struct date end) { // days elapsed
  return base(end)-base(begin);       // between begin and end dates
}

// determining month and day based on the day of the year
struct date monthAndDay(int year, int dayOfYear) {
  struct date d = { dayOfYear, 1, year };
  int day;
  for(d.month=1; 
      d.day>(day=daysOfMonth(year, d.month)); d.month++) {
    d.day -= day;
  }
  return d;
}

int main(void) {
  struct date d = {23, 10, 2020};
  printf("The given date is %s.\n"
         "%d.%d.%d is the %dth day of the year.\n", 
         (check(d)?"valid":"invalid"), d.day, d.month, d.year, 
         dayOfYear(d));
  struct date xmas = {24, 12, 2020};
  printf("How many days are left to christmas? %d\n", 
    difference(d, xmas));
  int dy = 300;
  d = monthAndDay(d.year, dy);
  printf("The %dth day of %d is: %d.%d\n", 
    dy, d.year, d.day, d.month);
  return 0;
}

