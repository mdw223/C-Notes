// Demonstration of accessing external variables and functions, defined in the
// helper component.

#include <stdio.h>
#include "helper.h"

int main()
{
  // Access a global variable in another component.
  x++;

  // Call the function supplied another component.
  f( 25 );
}
