#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef enum{false, true} bool;

typedef struct auxNode{

    int value;
    struct auxnode* left;
    struct auxNode* right;
}Node;

typedef Node* BST;

/* tree is a pointer to the root of a sub tree and treePtr is a pointer to a pointer of a root of a sub tree*/

/** Insert a value x on the BST and return true if success or false if failure*/
bool insert(BST* treePtr, int x);

/** Remove value x of the BST. In nodes with two valid pointers the node
 * receive its predecessor and return true if success or false if failure*/
bool remove_node(BST* treePtr, int x);

/** Search for an value x in the BST and return true if success or false if failure*/
bool search(BST tree, int x);

/** Print the BST. */
void print(BST tree);

#endif