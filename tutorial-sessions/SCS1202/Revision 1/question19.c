#include <stdio.h>

int main(void) {
    char regcode[9];
    printf("Registration number: ");
    scanf("%s[^\n]", regcode);
    //example: S/08/101

    char fac, year[2], regno[3];
    
    fac = regcode[0];

    year[0] = regcode[2];
    year[1] = regcode[3];

    regno[0] = regcode[5];
    regno[1] = regcode[6];
    regno[2] = regcode[7];

    printf("Faculty: %c\nYear: %s\nRegistration No: %s\n", fac, year, regno);
    return 0;

}