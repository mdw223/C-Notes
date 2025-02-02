#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  
  if ( a+++b>=c++-d ) {
    printf( "I didn't really care about this test anyway.!\n" );
  }

  printf( "a=%d b=%d c=%d d=%d\n", a, b, c, d );

  return 0;
}
