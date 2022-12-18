#include <stdio.h>
#include "bst.h"

int main(){

    BST tree;

    insert(&tree, 5);
    insert(&tree, 10);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 7);
    insert(&tree, 6);
    insert(&tree, 13);
    insert(&tree, 9);
    insert(&tree, 2);
    insert(&tree, 12);

    print(tree);

    remove_node(&tree, 5);
    remove_node(&tree, 13);

    print(tree);

    return 0;
}