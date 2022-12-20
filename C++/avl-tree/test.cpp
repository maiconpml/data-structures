#include "avl.h"

int main(){

    AVL tree;

    tree.insert_value(43);
    tree.print();
    tree.insert_value(35);
    tree.print();
    tree.insert_value(71);
    tree.print();
    tree.insert_value(20);
    tree.print();
    cout << "insertion and double rotation:\n";
    tree.insert_value(27);//a double rotation occurs to maintain the tree balancing
    tree.print();
    cout << "insertion and simple rotation to right:\n";
    tree.insert_value(12);//a simple rotation to the right occurs to maintain the tree balancing
    tree.print();
    tree.insert_value(40);
    tree.print();

    cout << "remotion and double rotation:\n";
    tree.remove_value(71);//a double rotation occurs after the remotion to maintain the tree balancing
    tree.print();

    cout << tree.search(40) << endl;
    cout << tree.search(71) << endl;
    
    return 0;
}