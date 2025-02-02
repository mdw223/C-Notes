/**
   Same as countChars, but with a common rookie mistake, using
   getchar() to reading characters into a char variable. (I know, sounds
   ridiculous).  The twoOfEverything.in input file shows the error
   in this program.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int ccount = 0;

  // Keep reading until we hit the EOF.  The way we're doing this is an
  // error.  It won't always be able to detect the end-of-file at the right
  // place.
  char ch;
  while ( ( ch = getchar() ) != EOF )
    ccount++;

  // Report how many characters we found.
  printf( "%d\n", ccount );
  
  // Better than just returning zero.
  return EXIT_SUCCESS;
}
