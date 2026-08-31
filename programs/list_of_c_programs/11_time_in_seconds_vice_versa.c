/*
gcc .\11_time_in_seconds_vice_versa.c -o .\11_time_in_seconds_vice_versa
.\11_time_in_seconds_vice_versa.exe
Want in hour_to_seconds or seconds_to_hour? (h/s): seconds_to_hour
Enter the time in seconds: 72000
Time in hour: 20, minutes: 0, seconds: 0

.\11_time_in_seconds_vice_versa.exe
Want in hour_to_seconds or seconds_to_hour? (h/s): hour_to_seconds
Enter the time in hour: 2
Time in seconds: 7200
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *time_str = (char *)calloc(20, sizeof(char));
    int time, hours, minutes, seconds;
    if (time_str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Want in hour_to_seconds or seconds_to_hour? (h/s): ");
    scanf("%20s", time_str);

    bool is_hour_to_seconds = strcmp(time_str, "hour_to_seconds") == 0;
    is_hour_to_seconds ? printf("Enter the time in hour: ") : printf("Enter the time in seconds: ");

    scanf("%d", &time);
    if(is_hour_to_seconds != true){
        hours = time/3600;
        minutes = (time%3600)/60;
        seconds = time%60;
        printf("Time in hour: %d, minutes: %d, seconds: %d\n", hours, minutes, seconds);
    }
    else{
        seconds = time * 3600;
        printf("Time in seconds: %d\n", seconds);
    }
    free(time_str);
    return 0;
}