# AVL tree

The AVL tree is a binary search tree that has properties that keep the tree balanced. To do this, you first need to calculate a node's balancing factor by subtracting the height of its left child from the height of its right child. By the properties of the AVL tree, the balancing factor can only be between -1 and 1 including -1 and 1. When the balancing factor of a node becomes 2 or -2 due to an insertion or removal, a movement of the nodes occurs called rotation.
Rotation can happen both ways. On left rotation of node X, node X becomes the left child of its right child Y. Also, the previous left child of node Y becomes the right child of node X. The operations on right rotation are the same but mirrored.
There are two cases where these operations will happen in different orders. When a node X has a balancing factor of 2, its left subtree is 2 levels taller than the right subtree. In this case, a clockwise rotation needs to occur to keep the tree balanced. However, if the left child of node X, called Y, has its right subtree larger than the left one, a right rotation of node Y is necessary for the rotation of node X to be effective and keep the tree balanced. In the case where a node has a balancing factor -2, that is, its right subtree is 2 levels higher than its left subtree, the same operations described above happen, however, mirrored.

This implementation contains these functions:

- insert_value: insert a value in the list and returns a boolean indicating whether the insertion take place or not.
- remove_value: remove a value in the list and returns a boolean indicating whether the remotion occurred or not.
- search: returns a boolean indicating whether a given value is in the list or not.
- print: print the tree formated in pre-order to stdout.
