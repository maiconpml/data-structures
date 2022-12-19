#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

typedef enum{false,true} bool;

typedef struct auxNode {
  int value;
  int height;
  struct auxNode * left;
  struct auxNode * right;
} Node;
typedef Node* AVL;

/** Insert a value x in the tree */
bool insert_value(AVL* treePtr, int x);

/** Remove a value x from the tree*/
bool remove_value(AVL* treePtr, int x);

/*  Search for a value x in the tree*/
bool search(AVL tree, int x);

/** Print the tree*/
void print(AVL tree);

#endif
