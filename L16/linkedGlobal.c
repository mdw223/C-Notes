// Linked list with the head accessed as a global variable.

#include <stdio.h>
#include <stdlib.h>

// Node for building our linked list.
struct NodeStruct {
  // Value in this node.
  int value;

  // Pointer to the next node.
  struct NodeStruct *next;
};

// A short type name to use for a node.
typedef struct NodeStruct Node;

// Pointer to the head node.
Node *head = NULL;

// Add a value to the start of the list.
// Here, we just modify the global head pointer.
void addValue( int val )
{
  // Make a new node.
  Node *n = (Node *)malloc( sizeof( Node ) );

  // Save val in the value field.
  n->value = val;

  // Link it to the start of the list.
  n->next = head;
  head = n;
}

// Traversal function that calls the visit funciton for the value
// of each node.
void traverse( void (*visit)( int val ) )
{
  for ( Node *n = head; n; n = n->next )
    visit( n->value );
}

// Visitor funciton that we
static void myVisitor( int val )
{
  printf( "%d\n", val );
}

int main()
{
  // Add a few values to the list.
  addValue( 75 );
  addValue( 18 );
  addValue( 42 );
  addValue( 9 );
  addValue( 103 );

  // Use a for loop to walk down the list, printing out the values.
  for ( Node *n = head; n; n = n->next )
    printf( "%d\n", n->value );

  // Use a visitor pattern to traverse the list, without
  // having to worry about its representaton.
  traverse( myVisitor );
  
  return 0;
}
