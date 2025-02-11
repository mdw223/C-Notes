// Demonstration of how pointers let us try to read/write any memory
// location.  An error here can crash our program.

#include <stdio.h>

int main()
{
  // Make up an address
  int *p = (int *)12345678;

  // I wonder if I can successfully write to this
  // memory location.  Let's find out.
  *p = 100;

  // We probably won't get past the previous line during execution.
  // But, if we do. ...

  // Uninitialized pointer, whatever's left in left over in this variable
  // will determine where it points.
  int *q;

  // If we try to access that memory, it will probably crash our program.
  *q = 250;

  return 0;
}
