// A (potentially unbalanced) tree implemented in C, without
// any fancy pointer-to-pointer tricks.

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

// Typical insert function
bool insertKey( Tree *tree, int val )
{
  if ( ! tree->root ) {
    // Make a new node with this value at the root.
    tree->root = (Node *)malloc( sizeof( Node ) );
    tree->root->key = val;
    tree->root->left = tree->root->right = NULL;
    return true;
  }

  // Find the parent node for the new node we need to insert.
  Node *parent = tree->root;

  while ( parent ) {
    // Is the value already in the tree?
    if ( val == parent->key )
      return false;
    
    if ( val < parent->key ) {
      if ( ! parent->left ) {
        // There's no left child, that's where to put the new node.
        parent->left = (Node *)malloc( sizeof( Node ) );
        // Struct initialization syntax lets us initialize all fields at once.
        *(parent->left) = (Node){ val, NULL, NULL };
        return true;
      } else
        // There's a left node, descend to it and continue from there.
        parent = parent->left;
    } else {
      if ( ! parent->right ) {
        // There's no right child, that's where to put the new node.
        parent->right = (Node *)malloc( sizeof( Node ) );
        *(parent->right) = (Node){ val, NULL, NULL };
        return true;
      } else
        // There's a right node, descend to it and continue from there.
        parent = parent->right;
    }
  }

  // This should never be reached.
  return false;
}

// Return true if we can find a key matching val.
bool containsKey( Tree *tree, int val )
{
  Node *n = tree->root;

  // As long as we're still in the tree.
  while ( n ) {
    // Return immediately if we find a match.
    if ( n->key == val )
      return true;

    // Go left or right based on key comparison.
    if ( val < n->key )
      n = n->left;
    else
      n = n->right;
  }
  
  // We didn't find the requested key.
  return false;
}

// Internal use function to find a replacement node for n, remove it
// from its current position and fill in its left and right pointers
// to take the place of n.
static Node *findReplacement( Node *n )
{
  if ( ! n->left )
    // No left child, just use the right child as is.
    return n->right;

  if ( ! n->left->right ) {
    // Left child has no successors, use that with the right subtree from n.
    n->left->right = n->right;
    return n->left;
  }

  // Find the parent of the predecessor of n.
  Node *par = n->left;
  while ( par->right->right )
    par = par->right;

  // Remove predecessor, replacing it with its (only) left child.
  Node *pred = par->right;
  par->right = pred->left;
  
  // Copy the children of n to pred and return it.
  pred->left = n->left;
  pred->right = n->right;
  return pred;
}    

// Typical remove function
bool removeKey( Tree *tree, int val )
{
  // Do we need to replace the root node?
  if ( tree->root && tree->root->key == val ) {
    // Replace the root node and free it.
    Node *target = tree->root;
    tree->root = findReplacement( target );
    free( target );
    return true;
  }
  
  // Find the parent node for the node we're removing.
  Node *parent = tree->root;

  while ( parent ) {
    // Is the desired key to the left or the right of this parent node?
    if ( val < parent->key ) {
      // It's to the left.
      if ( parent->left && parent->left->key == val ) {
        // Found it, we need to replace the left child of parent.
        Node *target = parent->left;
        parent->left = findReplacement( target );
        free( target );
        return true;
      } else
        // Descend the tree to the left.
        parent = parent->left;
    } else {
      // It's to the right.
      if ( parent->right && parent->right->key == val ) {
        // Found it, we need to replace the right child of parent.
        Node *target = parent->right;
        parent->right = findReplacement( target );
        free( target );
        return true;
      } else
        // Descend the tree to the right.
        parent = parent->right;
    }
  }

  // The target node wasn't in the tree.
  return false;
}

// Recursive traversal to print the keys in the tree.
void printKeys( Node *n )
{
  if ( n ) {
    // Inorder traversal, print the left subtree
    printKeys( n->left );
    // Then the key at this node
    printf( "%d\n", n->key );
    // Then the right subtree.
    printKeys( n->right );
  }
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

  // Print out the values in sorted order.  This requires a traversal.
  printKeys( tree.root );

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
