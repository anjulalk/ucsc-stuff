#include <stdio.h>
#include "writetable.h"
#include "findchar.h"

void write_table(int);
void find_char(char *, char);
 
int main(void)
{
    int num;
    char ch = 'l';
    char str[] = "Hello, What are you doing these days?";
    
    printf("Wanna create Table of some number, enter number: ");
    scanf("%d", &num);
    
    /*write_table(num);*/
    write_table(num);
    
    /*find_char(str, ch); */    
    find_char(str, ch);     /* str, a string, is an address */
 
    return 0;
}
