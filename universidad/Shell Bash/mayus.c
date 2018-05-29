#include <stdio.h>
#include <ctype.h>

int main (void) /*convertor de palabras a Mayucula */
{

int c;
while ((c = getchar()) !=EOF)

putchar(islower(c) ? toupper(c) : c);
 

}
