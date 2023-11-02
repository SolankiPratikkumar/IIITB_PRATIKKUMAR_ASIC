

int main() {
    int sensor_input;
    int buzzer;
    int led;
    int mask = 0xFFFFFFF9;
  
while(1)
{
     asm (
                
		"andi %0, x30, 1\n\t"
		: "=r"(sensor_input) 
		: 
                :
                 );

    if (sensor_input == 1) {
        asm (
            "ori x30, x30, 6\n\t"
            "andi %0, x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
            : "r"(mask)
        );
    } 
    else {
        asm (
            "and x30, x30, %2\n\t"
            "andi %0,x30, 4\n\t"
            "andi %1, x30, 2"
            : "=r"(buzzer), "=r"(led)
            : "r"(mask)
        );
    }

   } 
    return 0;
}

