#ifndef __LKDLIST_H__
#define __LKDLIST_H__

typedef enum{false, true} bool;

typedef struct auxNode {
  int value;
  struct auxNode * prev;  
  struct auxNode * next;
} Node;
typedef Node * List;

/* Initialize an empty list. */
void initialize_list(List * list_pt);

/* Insert value in the end of the list pointed by list_pt. list points to the sentinel node. */
void insert_first(List list, int value);

/* Insert value at the beggining of the list pointed by list. list poits to the sentinel node. */
void insert_last(List list, int value);

/* Inserts a value at a given position and returns true or false if the insertion is successful or not. */
bool insert_position(List list, int value, int position);

/* Remove the last value and return it. */
int remove_last(List list);

/* Remove the first value and return it.*/
int remove_first(List list);

/* Removes the first occurrence of a value in the list.*/
bool remove_value(List list, int val);

/* Remove all occurrences of a certain value of the list pointed by list.
 * Return the number of ocurrences. */
int remove_occurrences(List list, int value);

/* Return a copy of a given list.*/
Node* clone(List list);

/* Search for an element on the list. 
   Return the position of first occurrence of value on the list starting at 0.
   Return -1 if the search fails. */
int indexOf(List list, int value);

int last_indexOf(List list, int value);

/* Print the list in stdout in this way:
   [1,6,8,5,3,8,6,4,6]
 */
void print(List list);

/* Removes all elements from the list making the list an empty list.*/
void clear_list(List list);

/* Deallocate all nodes of the list.
 */
void deallocate_list(List *list_pt);

#endif
