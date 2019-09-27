#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char *monthWords[] = {"", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    int rm, rd;
    printf("%d/%d is day %d of the year %d\n", 3, 14, day_of_year(2019, 14, 1), 2019);
    printf("%d/%d is day %d of the year %d\n", 3, 14, day_of_year(-2, 3, 1), -2);
    month_day(2019, 5000, &rm, &rd);
    printf("Day %d of the year %d is %d %d\n", 5000, 2019, rd, rm);
    month_day(-5, 60, &rm, &rd);
    printf("Day %d of the year %d is %d %d\n", 5000, 2019, rd, rm);
    return 0;
}

int day_of_year(int year, int month, int day){
    int i, leap;
    if (year >= 0) {
        leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        if (month <= 13 && month >= 1 && day >= 1 && day <= daytab[leap][month]) {
            for (i = 1; i < month; i++)
                day += daytab[leap][i];
            return day;
        }else
            printf("Please enter a valid day or month\n");
        return -1;
    }else
        printf("Please enter a valid year\n");
    return -1;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap, t;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (i = 0, t = 0; i <= 12; i++)
        t += daytab[leap][i];
    if (year >= 0 && yearday >= 1 && yearday <= t) {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }else {
        printf("Not a valid day or year\n");
        *pmonth = -1;
        *pday = -1;
    }
}