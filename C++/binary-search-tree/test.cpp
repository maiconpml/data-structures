#include "bst.h"

int main()
{
    
    BST tree1;

    tree1.insert_value(5);
    tree1.insert_value(10);
    tree1.insert_value(67);
    tree1.insert_value(3);
    tree1.insert_value(7);
    tree1.insert_value(4);
    tree1.insert_value(70);
    
    tree1.print();

    tree1.remove_value(5);

    tree1.print();
    
    tree1.remove_value(67);

    tree1.print();
    return 0;
}
