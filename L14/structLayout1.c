// Demonstration of how structures are laid out in memory, possibly with
// some padding between the fields.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct, with some fields.
struct Person {
  char name[ 10 ];
  double height;
  int age;
};

int main()
{
  // Here, I get 32, but the struct really only needs 22 bytes.
  printf( "sizeof( struct Person) = %zd\n", sizeof( struct Person ) );

  // It's introducing some padding,  I wonder if we can see where it is.
  struct Person bill;

  // Print the starting addresses of bill's fields.
  printf( "name:   %p\n", &bill.name );
  // There must be a 6-byte gap here.
  printf( "height: %p\n", &bill.height );
  printf( "age:    %p\n", &bill.age );
  // There must also be a 4-byte gap at the end.

  return 0;
}
