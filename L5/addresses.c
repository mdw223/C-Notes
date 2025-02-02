// We haven't learned about pointers yet, but we will soon.  This example
// uses pointer operations to see where variables reside in memory.

#include <stdio.h>

// a global variable.
int x = 15;

void func( int *yp )
{
  int z = 35;

  // Let's see the addresses for a global variable,
  // a local variable allocated in main and another local
  // variable allocated in this function.
  printf( "&x = %p\n", &x );
  printf( "&y = %p\n", yp );
  printf( "&z = %p\n", &z );
}

int main()
{
  // a local variable.
  int y = 25;

  func( &y );

  return 0;
}
