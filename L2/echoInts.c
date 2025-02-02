/**
   A formatted I/O program that reads and echos back all the integer
   values it can, one value per output line.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int val;

  // While we match one conversion specification
  while ( scanf( "%d", &val ) == 1 ) {
    // Print it.
    printf( "%6d\n", val );
  }

  return EXIT_SUCCESS;
}
