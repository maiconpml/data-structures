# AVL tree

The AVL tree is a binary search tree that has properties that keep the tree balanced. To do this, you first need to calculate the balancing factor of a node by subtracting the height of its left child by the height of its right child. By the properties of the AVL tree, the balancing factor can be between -1 and 1 including -1 and 1. When the balancing factor of a node becomes 2 or -2 due to an insertion or removal, a movement of the nodes takes place called rotation.
Rotation can happen to both sides. Left rotation occurs when a node has a balance factor of -2. In this case, node X with balancing factor -2 becomes the left child of its right child Y. Also, the previous left child of node Y becomes the right child of node X.
After this operation, both nodes X and Y have their balancing factor equals to 0. 

This implementation contains these functions:

- insert_value: insert a value in the list and returns a boolean indicating whether the insertion take place or not.
- remove_value: remove a value in the list and returns a boolean indicating whether the remotion occurred or not.
- search: returns a boolean indicating whether a given value is in the list or not.
- print: print the tree formated in pre-order to stdout.
