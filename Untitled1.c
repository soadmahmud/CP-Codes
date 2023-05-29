#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50];
    int year, month, days_in_month, i, j, day_of_week;

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%d", &month);

    // Calculate the number of days in the month
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    // Determine the day of the week for the first day of the month
    day_of_week = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    for (i = 1; i < month; i++) {
        if (i == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day_of_week = (day_of_week + 29) % 7;
            } else {
                day_of_week = (day_of_week + 28) % 7;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            day_of_week = (day_of_week + 30) % 7;
        } else {
            day_of_week = (day_of_week + 31) % 7;
        }
    }

    // Create the file
    sprintf(filename, "calendar-%d-%d.txt", year, month);
    fp = fopen(filename, "w");

    if(fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    // Write the header and days of the week
    fprintf(fp, "Calendar for %d-%d\n\n", year, month);
    fprintf(fp, "Sun Mon Tue Wed Thu Fri Sat\n");

    // Write the calendar data
    for (i = 0; i < day_of_week; i++) {
        fprintf(fp, "    ");
    }
    for (i = 1, j = day_of_week; i <= days_in_month; i++, j++) {
        if (j == 7) {
            j = 0;
            fprintf(fp, "\n");
        }
        fprintf(fp, "%3d ", i);
    }
    fprintf(fp, "\n");



    printf("Calendar for %d-%d\n\n", year, month);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Write the calendar data
    for (i = 0; i < day_of_week; i++) {
        printf("    ");
    }
    for (i = 1, j = day_of_week; i <= days_in_month; i++, j++) {
        if (j == 7) {
            j = 0;
            printf("\n");
        }
        printf("%3d ", i);
    }
    printf("\n");

    fclose(fp);
    printf("File created successfully.\n");
    return 0;
}
