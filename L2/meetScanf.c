/*
 * Demonstration of the use of scanf.
 */

#include <stdio.h>
#include <stdbool.h>

int main()
{
  // Prompt the user.
  printf( "Please enter an integer: " );

  // Try to read a value, see how much we read.
  int val;
  int matches = scanf( "%d", &val );
  if ( matches == 1 ) {
    printf( "You entered %d\n", val );
  } else if ( matches == 0 ) {
    printf( "That's not an integer.\n" );
  } else {
    printf( "You didn't enter anything.\n" );
  }

  return 0;
}
