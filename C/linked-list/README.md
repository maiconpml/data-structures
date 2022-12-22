# Circular doubly linked list

A doubly circular linked list is a list in which a node points to its predecessor and successor and the last and first nodes are each other's predecessors and successors. This implementation uses a sentinel node which is a node with an invalid value that points to the first and last nodes. This node is used to simplify the code since the special case where the list is empty does not exist.  
This implementation contains these functions:

- initialize_list: creates an empty list.
- insert_first: inserts a value at the beginning of the list.
- remove_first: removes the first value from the list and returns the removed value.
- insert_last: inserts a value at the end of the list.
- remove_last: removes the last value from the list and returns the removed value.
- remove_occurrences: removes all occurrences of a value in the list and returns the number of occurrences.
- indexOf: return the index of a given element.
- print: prints the list to stdout.
- deallocate_list: deallocates the list making it an invalid list.
- clear_list: removes all elements from the list making the list an empty list.
- insert_position: inserts a value at a given position and returns true or false if the insertion is successful or not.
- remove_value: removes the first occurrence of a value in the list.
- clone: return a copy of a given list.
- last_indexOf: return the index of a given element starting from last position.
- convert_to_array: convert a list to an array and return its pointer.
- number_of_elem: return the number of elements in a given list.
