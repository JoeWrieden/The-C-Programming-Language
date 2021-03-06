#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char *monthWords[] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    int d = 1; int m = 3; int y = 2019; int yd = 60;
    int rm, rd;
    printf("%d %s is day %d of the year %d\n", d, monthWords[m], day_of_year(y, m, d), y);
    month_day(y, yd, &rm, &rd);
    printf("Day %d of the year %d is %d %s\n", yd, y, rd, monthWords[rm]);
    return 0;
}

int day_of_year(int year, int month, int day){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for ( i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}