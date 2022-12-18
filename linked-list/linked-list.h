#ifndef __LKDLIST_H__
#define __LKDLIST_H__

typedef struct auxNode {
  int value;
  struct auxNode * prev;  
  struct auxNode * next;
} Node;
typedef Node * List;

/* Initialize an empty list. */
void initialize_list(List * list_pt);

/* Insert value in the end of the list pointed by list_pt. list points to the sentinel node*/
void insert_first(List list, int value);

/* Insert value at the beggining of the list pointed by list. list poits to the sentinel node*/
void insert_last(List list, int value);

/* Remove the last value and return it. */
int remove_last(List list);

/* Remove the first value and return it.*/
int remove_first(List list);

/* Remove all occurrences of a certain value of the list pointed by list.
 * Return the number of ocurrences. */
int remove_occurrences(List list, int value);

/* Search for an element on the list. 
   Return the position of first occurrence of value on the list starting at 0.
   Return -1 if the search fails. */
int search(List list, int value);

/* Print the list in stdout in this way:
   [1,6,8,5,3,8,6,4,6]
 */
void print(List list);

/* Deallocate all nodes of the list.
 */
void deallocate_list(List *list_pt);

#endif
