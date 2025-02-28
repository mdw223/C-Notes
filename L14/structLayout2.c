// Demonstration of how structures are laid out in memory, possibly with
// some padding between the fields.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Compare this to the Person struct in structLayout1.c.  Here, the middle
// field is smaller, so our alignment requirements are just for 4-byte.
struct Person {
  char name[ 10 ];
  float height;
  int age;
};

int main()
{
  // With a new layout, this particular struct doesn't need any padding.
  printf( "sizeof( struct Person) = %zd\n", sizeof( struct Person ) );

  // It's introducing some padding,  I wonder if we can see where it is.
  struct Person bill;

  // Print the starting addresses of bill's fields.
  printf( "name:   %p\n", &bill.name );
  // Now, there's only a two-byte gap here.
  printf( "height: %p\n", &bill.height );
  printf( "age:    %p\n", &bill.age );
  // And, we don't need any padding at the end to maintain 4-byte alignment

  return 0;
}
