#include "helper.h"
#include <stdio.h>

// A global variable, visible to anyone who links with this component.
int x = 5;

// A function, visible to anyone who links with this component.
void f( int a )
{
   printf( "x = %d\n", x );
   printf( "parameter = %d\n", a );
}
