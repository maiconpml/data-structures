#include "iostream"
#include "linked-list.h"

//Testing all the methods of the class linked list
int main(){
    
    linkedList list1;

    list1.insert_first(3);
    list1.insert_first(5);
    list1.insert_first(7);
    list1.insert_first(34);
    list1.insert_first(6);

    list1.insert_last(21);
    list1.insert_last(54);
    list1.insert_last(34);
    list1.insert_last(212);
    list1.insert_last(28);

    list1.remove_occurrences(34);

    list1.remove_first();
    list1.remove_first();

    list1.remove_last();
    list1.remove_last();

    cout << list1.index(21) << endl;

    list1.print();

    return 0;
}
