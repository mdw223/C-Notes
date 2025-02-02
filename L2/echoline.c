/*
 A sample program to read and write a single line of text.
 */
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
  // While there's still more input on this line.
  int ch = getchar();
  while ( ch != '\n' && ch != EOF ) {
    // Echo it and get the next character.
    putchar( ch );
    ch = getchar();
  }

  // End the output line.
  putchar( '\n' );
  
  // Better than just returning zero.
  return EXIT_SUCCESS;
}
