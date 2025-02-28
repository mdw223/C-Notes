// Demonstration of how structures are laid out in memory, possibly with
// some padding between the fields.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Compare this to the Person struct in structLayout1.c.  Here, the second
// two fields are swapped.  This reduces the need for padding and saves a little
// space.
struct Person {
  char name[ 10 ];
  int age;
  double height;
};

int main()
{
  // With a new layout, this particular struct doesn't need any padding.
  printf( "sizeof( struct Person) = %zd\n", sizeof( struct Person ) );

  // It's introducing some padding,  I wonder if we can see where it is.
  struct Person bill;

  // Print the starting addresses of bill's fields.
  printf( "name:   %p\n", &bill.name );
  // We just need a two-byte gap here, to make age start at a 4-byte boundary
  printf( "age:    %p\n", &bill.age );
  printf( "height: %p\n", &bill.height );
  // With this field order, we don't need any padding at the end.

  return 0;
}
