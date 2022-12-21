#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

typedef enum{false, true} bool;

typedef int DataType;

typedef struct {
  bool occupied;
  bool deleted;
  DataType value;
} TableElement;

typedef struct {
  int n_pos; // number of positions in the table.
  TableElement *T;
} Table;

#define SIZE_FACTOR 5

/* Create a table with SIZE_FACTOR times n_elem_max positions.
   Correctly initialize table attributes, n_pos = SIZE_FACTOR * n_elem_max,
   occupied = false and deleted = false for all indexes*/
bool alloc_table(Table *tablePtr, int n_elem_max);

/* Deallocates the table */
void deallocate_table(Table *tablePtr);

/* Insert elem into table T. Uses the position defined by the hash
   function in hash.h and hash.c, where hash(elem, i, T.n_pos) for
   i = 0,1,2,3... are the consecutive positions where the element
   can be inserted. Returns the position where the element will be
   inserted or -1 if the insertion is not possible.*/
int insert_value(Table T, int elem);

/* Search for an element in table T. Returns its position in the table
   or -1 if the search fails.*/
int search(Table T, int elem);

/* Search for an element and remove it. Returns its position in the table
   or -1 if the remotion fails.*/
int remove_value(Table T, int elem);

#endif