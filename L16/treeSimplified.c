// A (potentially unbalanced) tree implemented in C, using some pointer-to-pointer
// to fold some of the different cases into one.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for building trees.
struct NodeStruct {
  // Key in this node.
  int key;

  // Pointer to the left and right subtrees.
  struct NodeStruct *left, *right;
};

// A short type name to use for a node.
typedef struct NodeStruct Node;

// Struct containing the whole tree
typedef struct {
  // Root of the tree.
  Node *root;
} Tree;

// Internal use function, to find the pointer to the node with the
// given key if it exists, or a pointer to null in the right place
Node **findPointer( Tree *tree, int val )
{
  Node **target = &( tree->root );
  while ( *target && (*target)->key != val )
    if ( val < (*target)->key )
      target = &(*target)->left;
    else
      target = &(*target)->right;
  
  return target;
}

// Insert key, getting findPoitner to do most of the work.
bool insertKey( Tree *tree, int val )
{
  // Find the pointer where that value should be.
  Node **target = findPointer( tree, val );

  // If it already points to a node, we already have the key.
  if ( *target )
    return false;

  // Otherwise, add a leaf node for value.
  *target = (Node *)malloc( sizeof( Node ) );
  **target = (Node){ val, NULL, NULL };
  return true;
}

// Return true if tree contains val, with findPointer() doing most of the work.
bool containsKey( Tree *tree, int val )
{
  Node **target = findPointer( tree, val );
  return *target;
}

// Internal use function to find a replacement node for n, remove it
// from its current position and fill in its left and right pointers
// to take the place of n.
static Node *findReplacement( Node *n )
{
  if ( ! n->left )
    // No left child, just use the right child as is.
    return n->right;

  // Find the pointer to our predecessor, with no right child.
  Node **predPtr = &( n->left );
  while ( (*predPtr)->right )
    predPtr = &(*predPtr)->right;

  // Replace it with its left child.
  Node *pred = *predPtr;
  *predPtr = pred->left;
  
  // Copy the children of n to pred and return it.
  pred->left = n->left;
  pred->right = n->right;
  return pred;
}

// Remove function, with help from findPointer()
bool removeKey( Tree *tree, int val )
{
  // Find the pointer to the node to remove.
  Node **target = findPointer( tree, val );

  // If it doesn't exist, we're done.
  if ( ! *target )
    return false;

  // Find a replacement for the target and free it.
  Node *n = *target;
  *target = findReplacement( n );
  free( n );
  return true;
}

// Generic traversal, running a visitor at each node.
void traverse( Node *n, void (*visit)( int val ) )
{
  if ( n ) {
    // Traverse the left subtree.
    traverse( n->left, visit );
    // Let the visitor see the key at the current node.
    visit( n->key );
    // Then, the right subtree.
    traverse( n->right, visit );
  }
}

// Same visitor function from our linked list example.
static void myVisitor( int val )
{
  printf( "%d\n", val );
}

// Print the tree, using indentation to show the structure.
void printTree( Node *n, int depth )
{
  if ( n ) {
    // We print the subtrees backward here, so you can lean
    // your head to the left and read the left (bottom) to right (top)
    // structure of the tree.
    // Then the value at this node, indented
    printTree( n->right, depth + 1 );
    for ( int i = 0; i < depth; i++ )
      printf( "  " );
    printf( "%d\n", n->key );
    printTree( n->left, depth + 1 );
  }
}

int main()
{
  // Make a tree.  Again, something like a constructor would be better.
  Tree tree = { NULL };

  // Add a few values to the tree.
  insertKey( &tree, 21 );
  insertKey( &tree, 50 );
  insertKey( &tree, 75 );
  insertKey( &tree, 18 );
  insertKey( &tree, 42 );
  insertKey( &tree, 9 );
  insertKey( &tree, 103 );

  // use a generic traversal function.
  traverse( tree.root, myVisitor );

  // Try removing a couple of keys.
  removeKey( &tree, 50 );
  removeKey( &tree, 9 );

  // Check a couple of keys.
  if ( ! containsKey( &tree, 103 ) || containsKey( &tree, 9 ) )
    printf( "Error, bad containsKey() result\n" );
  
  // Print out the shape of the tree (well, sort of)
  printTree( tree.root, 0 );
  
  
  return 0;
}
