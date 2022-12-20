#include "avl.h"
#include <stdio.h>

int main(){

    AVL tree1;

    insert_value(&tree1, 43);
    print(tree1);
    insert_value(&tree1, 35);
    print(tree1);
    insert_value(&tree1, 71);
    print(tree1);
    insert_value(&tree1, 20);
    print(tree1);
    printf("insertion and double rotation:\n");
    insert_value(&tree1, 27);//a double rotation occurs to maintain the tree balancing 
    print(tree1);

    printf("insertion and simple rotation to right:\n");
    insert_value(&tree1, 12);//a simple rotation to the right occurs to maintain the tree balancing
    print(tree1);

    insert_value(&tree1, 40);
    print(tree1);

    printf("remotion and double rotation:\n");
    remove_value(&tree1, 71);//a double rotation occurs after the remotion to maintain the tree balancing
    print(tree1);

    if(search(tree1, 40)) printf("40: true\n");

    else printf("40: false\n");

    if(search(tree1, 71)) printf("71: true\n");

    else printf("71: false\n");

    return 0;
}