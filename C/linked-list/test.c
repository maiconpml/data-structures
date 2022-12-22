#include "linked-list.h"
#include <stdio.h>

int main(){

    List list1;

    initialize_list(&list1);
    
    insert_first(list1, 12);
    insert_first(list1, 21);
    insert_first(list1, 97);
    insert_first(list1, 213);
    insert_first(list1, 67);

    print(list1);

    insert_last(list1, 54);
    insert_last(list1, 45);
    insert_last(list1, 897);
    insert_last(list1, 34);
    insert_last(list1, 68);

    print(list1);

    insert_position(list1, 37, 3);

    print(list1);

    Node * list2 = clone(list1);

    clear_list(list1);

    print(list1);
    print(list2);

    remove_value(list2, 54);

    print(list2);

    printf("last index of 897: %d\n", last_indexOf(list2, 897));

    int* vect = convert_to_array(list2);
    int n = number_of_elem(list2);

    for(int i = 0; i < n; ++i){

        printf("%d;", vect[i]);
    }printf("\n");

    deallocate_list(&list1);
    deallocate_list(&list2);
}