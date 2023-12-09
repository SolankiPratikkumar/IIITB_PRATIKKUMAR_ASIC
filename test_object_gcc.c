#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sensor;      // bit 0
    int buzzer;      // bit 1
    int shift = 0xFFFFFFF2;
    int min = 1;
    int max = 100;
    int j = 0;
    int k = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    while (j < 11) {
        int randomNum = rand();
        printf("Random number: %d\n", randomNum);
        sensor = randomNum % 2;
        printf("Sensor value: %d\n", sensor);

        if (sensor == 1) { 
            printf("Presence of Object\n");
            buzzer = 1;
            /*asm(
            "and x30, x30, %1\n\t"
            "or x30, x30, %0\n\t"
            :"=r"(buzzer)
            :"r"(shift));*/
            for (int i = 0; i < 1000000; i++);
        }
        else { 
            printf("Presence of Object not detected\n");
            buzzer = 0; 
            /*asm(
            "and x30, x30, %1\n\t"
            "or x30, x30, %0\n\t"
            :"=r"(buzzer)
            :"r"(shift));*/
            for (int i = 0; i < 1000000; i++);
        }

        j++;
    }

    return 0;
}
